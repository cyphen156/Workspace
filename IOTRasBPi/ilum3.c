#include <wiringPiSPI.h>
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define CS_MCP3208	8
#define SPI_CHANNEL	0
#define SPI_SPEED	1000000 // 1MHz
#define Led_1			6

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

	if (wiringPiSetupGpio() == -1) return 1;

	if (wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) return 1;

	pinMode(CS_MCP3208, OUTPUT);
	pinMode(Led, OUTPUT);
	digitalWrite(Led, LOW);
	softPwmCreate(Led, 0, 100);

	while (1) {
		nCdsValue = ReadMcp2308ADC(nCdsChannel);

		printf("CDS Sensor Value = %d\n", nCdsValue);
		if (nCdsValue > 700) {
			digitalWrite(Led, LOW);
			delay(1000);
		}else{

			softPwmWrite(Led, 100-(nCdsValue/7));
			delay(200);
		}
	}
	return 0;
}