/*Operate AHT20 Sensors without AHT's library.
Only use wire method.
*/
#include <Wire.h>
#define DefaultAddress 0x38 // Data sheet.Device Address

uint32_t temperature;
uint32_t humidity;

float tempCelsius;
float Humidity_RH;

void setup()
{
      Serial.begin(115200);
      Serial.println("Humidity AHT20 examples");

      // Wire 설정
      Wire.begin();
}

void loop()
{

      float temperature = getTemperature();
      float humidity = getHumidity();

      Serial.print("Temperature: ");
      Serial.print(temperature, 2);
      Serial.print(" C\t");
      Serial.print("Humidity: ");
      Serial.print(humidity, 2);
      Serial.print("% RH");

      Serial.println();

      delay(2000);
}

void readData()
{
      // 측정 모드 설정
      Wire.beginTransmission(DefaultAddress);
      Wire.write(0XAC);
      Wire.write((uint8_t)0x33);
      Wire.write((uint8_t)0x00);
      Wire.endTransmission();
      delay(100);

      // 측정 데이터 값 Read
      if (Wire.requestFrom(DefaultAddress, (uint8_t)6) > 0)
      {
            Wire.read();

            // Data 값 분할
            uint32_t incoming = 0;
            incoming |= (uint32_t)Wire.read() << (8 * 2);
            incoming |= (uint32_t)Wire.read() << (8 * 1);
            uint8_t midByte = Wire.read();

            incoming |= midByte;
            humidity = incoming >> 4;

            // midByte에서 온도값 추출
            temperature = (uint32_t)midByte << (8 * 2);
            temperature |= (uint32_t)Wire.read() << (8 * 1);
            temperature |= (uint32_t)Wire.read() << (8 * 0);

            // CRC 체크
            temperature = temperature & ~(0xFFF00000);
      }
}

float getTemperature()
{
      readData();
      tempCelsius = ((float)temperature / 1048576) * 200 - 50;
      return tempCelsius;
}

float getHumidity()
{
      readData();
      Humidity_RH = ((float)humidity / 1048576) * 100;
      return Humidity_RH;
}