#include "sensor.h"
float val_temp, val_humi;
unsigned short SHT11_humi, SHT11_temp;
unsigned short error, checksum;
unsigned char sensing_type;

static void I2C_data_output (void) {
    pinMode(SDA, OUTPUT); }
static void I2C_data_input (void) {
    pinMode(SDA, INPUT); }

static void I2C_sck_output(void) {
    pinMode(SCK, OUTPUT); }
static void I2C_sck_input (void) {
    pinMode(SCK, INPUT); }

static void SET_I2CDATA_PIN (void) {
    digitalWrite(SDA, 1); }
static void CLR_I2CDATA_PIN (void) {
    digitalWrite(SDA, 0); }

static void SET_I2CSCK_PIN (void) {
    digitalWrite(SCK, 1); }
static void CLR_I2CSCK_PIN (void) {
    digitalWrite(SCK, 0); }

static int READ_I2CDATA_PIN (void) {
    return digitalRead(SDA); }
static int READ_I2CSCK_PIN (void) {
    return digitalRead(SCK); }

void SHT11_Init(void)
{
    I2C_data_output();
    I2C_sck_output();
    Connection_reset();
}
void Connection_reset (void)
{
    unsigned char i;
    SET_DATA();
    CLR_SCK();
    for(i=0;i<9;i++) {
        SET_SCK();
        delayMicroseconds(1);
        CLR_SCK();
        delayMicroseconds(1);
    }
}
void Transmission_start (void)
{
    SET_DATA();
    CLR_SCK();
    delayMicroseconds(1);
    SET_SCK();
    delayMicroseconds(1);
    CLR_DATA();
    delayMicroseconds(1);
    CLR_SCK();
    delayMicroseconds(1);
    SET_SCK();
    delayMicroseconds(1);
    SET_DATA();
    delayMicroseconds(1);
    CLR_SCK();
}
float get_SHT11_data (unsigned char type) { // 온습도 데이터 획득
    sensing_type = type;
    error = 0;
    if(sensing_type == HUMI) { // 습도 수치 측정
        error += Measure(&SHT11_humi, &checksum, HUMI);
        if(error != 0) // 에러 발생 시, connection reset
            Connection_reset();
        else // 측정된 값을 바탕으로 온,습도 값 계
            calc_SHT11(SHT11_humi, SHT11_temp);
            return val_humi; }
    else if(sensing_type == TEMP) { // 온도 수치 측정
        error += Measure(&SHT11_temp, &checksum, TEMP);
        if(error != 0) // 에러 발생 시, connection reset
            Connection_reset();
        else
            calc_SHT11(SHT11_humi, SHT11_temp); // 측정된 값을 바탕으로 온,습도 계산
            return val_temp; }
    else{
        return 0; }
}
unsigned char Measure (unsigned short *p_value, unsigned short *p_checksum, unsigned char mode) //TWI 통신을 이용한 온,습도 측정
{
    unsigned short error = 0;
    unsigned short SHT11_msb, SHT11_lsb;
    switch(mode){
        case TEMP:
            error += Write_byte(MEASURE_TEMP); // 온도 요청 신호 송신
            break;
        case HUMI:
            error += Write_byte(MEASURE_HUMI); // 습도 요청 신호 송신
            break;
        default:
            break;
    }
    if(error !=0)
        return error;

    I2C_data_input(); // 수신 대기
    while(READ_DATA()) ;
    I2C_data_input(); // 데이터 수신
    SHT11_msb = Read_byte(ACK);
    SHT11_lsb = Read_byte(ACK);
    *p_value = (SHT11_msb*256) + SHT11_lsb;
    *p_checksum = Read_byte(NOACK);
    return error;
}
unsigned char Write_byte(unsigned char value) {  // 데이터 송신
    unsigned char i, error = 0;
    I2C_data_output();
    for(i=0x80; i>0; i/=2) {
        if (i&value)
            SET_DATA();
        else
            CLR_DATA();
        delayMicroseconds(1);
        SET_SCK();
        delayMicroseconds(1);
        CLR_SCK();
        delayMicroseconds(1); }
    SET_DATA();
    I2C_data_input();
    delayMicroseconds(1);
    SET_SCK();
    error = READ_DATA();
    CLR_SCK();
    I2C_data_output();
    return error;
}
unsigned char Read_byte(unsigned char ack) {  // 데이터 수신
    unsigned char i, val = 0;
    I2C_data_input();
    SET_DATA();
    delayMicroseconds(1);
    for(i=0x80; i>0; i/=2) {
        SET_SCK();
        delayMicroseconds(1);
        if(READ_DATA())
            val = (val | i);
        CLR_SCK();
        delayMicroseconds(1); }
    I2C_data_output();
    if(ack) CLR_DATA();
    else SET_DATA();
    SET_SCK();
    delayMicroseconds(1);
    CLR_SCK();
    delayMicroseconds(1);
    SET_DATA();
    return val;
}
void calc_SHT11 (unsigned short humidity,unsigned short temperatrue) { // 온습도 값 계산 함수
    const float C1 = -2.0468;
    const float C2 = 0.0367;
    const float C3 = -0.0000015955;
    const float T1 = 0.01;
    const float T2 = 0.00008;
    float rh_lin;
    float rh_true;
    float t_C;
    float rh = (float)humidity;
    float t = (float)temperatrue;

    t_C = ((t*0.01)-40.1)-5;
    rh_lin = (C3*rh*rh)+(C2*rh)+C1;
    rh_true = (t_C-25)*(T1+(T2*rh))+rh_lin;
    if (rh_true >100)
        rh_true=100;
    if (rh_true <0.1)
        rh_true = 0.1;
    val_temp = t_C;
    val_humi = rh_true;
}