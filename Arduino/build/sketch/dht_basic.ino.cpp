#include <Arduino.h>
#line 1 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
long levelTimeout = 500000; // 500ms
uint8_t bitmask = 0xFF;
uint8_t port = 0xFF;
int pin = 7;
#line 5 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
void setup();
#line 10 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
void loop();
#line 25 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int read(byte *temperature, byte *humidity);
#line 49 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int sample(byte data[40]);
#line 85 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
long levelTime(byte level, int firstWait, int interval);
#line 5 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
void setup()
{
      Serial.begin(115200);
}

void loop()
{
      byte temperature = 0;
      byte humidity = 0;

      read(&temperature, &humidity);
      Serial.print("temperature : ");
      Serial.print(temperature);
      Serial.println("C");
      Serial.print("humidity : ");
      Serial.print(humidity);
      Serial.println("%");
      delay(1000);
}

int read(byte *temperature, byte *humidity)
{
      int ret = 0;
      bitmask = digitalPinToBitMask(pin);
      port = digitalPinToPort(pin);
      byte data[40] = {0};
      sample(data);
      // 받은 data 처리
      /*for (size_t i = 0; i < 40; i++)
      {
            Serial.print(data[i]);
      }*/
      
      *humidity = 0;
      for (size_t i = 0; i < 8; i++)
      {
            *humidity += data[i] * pow(2, 7 - i);
      }
      *temperature = 0;
      for (size_t i = 16; i < 24; i++)
      {
            *temperature += data[i] * pow(2,  23-i);
      }
}
int sample(byte data[40])
{
      // memset(data, 0,40);
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
      delay(18 + 2);
      //
      digitalWrite(pin, HIGH);
      delayMicroseconds(25);
      pinMode(pin, INPUT);

      long t = levelTime(LOW, 10, 6);
      if (t < 40)
      {
            return -1;
      }
      t = levelTime(HIGH, 10, 6);
      if (t < 40)
      {
            return -1;
      }

      for (size_t i = 0; i < 40; i++)
      {
            t = levelTime(LOW, 10, 6);
            if (t < 24)
            {
            }
            t = levelTime(HIGH, 10, 6);
            if (t < 11)
            {
            }
            data[i] = (t > 40 ? 1 : 0);
      }
}

long levelTime(byte level, int firstWait, int interval)
{
      unsigned long time_start = micros();
      long time = 0;

      uint8_t portState = level ? bitmask : 0;

      bool loop = true;
      for (int i = 0; loop; i++)
      {
            if (time < 0 || time > levelTimeout)
            {
                  return -1;
            }

            if (i == 0)
            {
                  if (firstWait > 0)
                  {
                        delayMicroseconds(firstWait);
                  }
            }
            else if (interval > 0)
            {
                  delayMicroseconds(interval);
            }
            time = micros() - time_start;

            // low상태에서 high 상태로 변할때 빠져 나가는 것
            loop = ((*portInputRegister(port) & bitmask) == portState);
      }

      return time;
}
