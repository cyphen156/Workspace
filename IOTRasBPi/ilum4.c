#include <wiringPiSPI.h>
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define CS_MCP3208	8
#define SPI_CHANNEL	0
#define SPI_SPEED	1000000 // 1MHz
#define Led_1			6
#define Led_2			12
#define Led_3			13
#define Led_4			16
#define Led_5			19
#define Led_6			20
#define Led_7			26
#define Led_8			21
#define	MAX_Led_NUM		8

const int LedPinTable[MAX_Led_NUM] = {
	Led_1, Led_2, Led_3, Led_4,
	Led_5, Led_6, Led_7, Led_8
};

int ReadMcp2308ADC(unsigned char adcChannel) {
	unsigned char buff[3];
	int nAdcValue = 0;

	buff[0] = 0x06 | ((adcChannel & 0x07) >> 2);
	buff[1] = ((adcChannel & 0x07) << 6);
	buff[2] = 0x00;

	digitalWrite(CS_MCP3208, 0);

	wiringPiSPIDataRW(SPI_CHANNEL, buff, 3); 
	buff[1] = 0x0f & buff[1];
	nAdcValue = (buff[1] << 8) | buff[2];

	digitalWrite(CS_MCP3208, 1);
	return nAdcValue;
}

int main(void) {
	int nCdsChannel = 0;
	int nCdsValue = 0;
	int i = 0;

	if (wiringPiSetupGpio() == -1) return 1;

	if (wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) return 1;

	pinMode(CS_MCP3208, OUTPUT);

	for (i = 0; i < MAX_Led_NUM; i++) {
		pinMode(LedPinTable[i], OUTPUT);
		digitalWrite(LedPinTable[i], LOW);
		softPwmCreate(LedPinTable[i], 0, 100);
	}

	while (1) {
		nCdsValue = ReadMcp2308ADC(nCdsChannel);

		printf("CDS Sensor Value = %d\n", nCdsValue);
		for (i = 0; i < MAX_Led_NUM; i++) {
			if (nCdsValue < 350) {
				softPwmWrite(LedPinTable[i], i*12);
				delay(120);
				}
			else{
				softPwmWrite(LedPinTable[i], LOW);
				delay(120);
			}
		}
	}
	return 0;
}