#include <Arduino.h>
#line 1 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int pin = 8;
uint8_t bitmask = 0xFF;
long levelTimeout = 500000; // 500ms
uint8_t port = 0xFF;

#line 6 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
void setup();
#line 11 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
void loop();
#line 22 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int read(byte *temperature, byte *humidity);
#line 39 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int sample(byte data[40]);
#line 76 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int levelTime(byte level, int firstwait, int interval);
#line 6 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
void setup()
{
      Serial.begin(115200);
}

void loop()
{
      byte temperature = 0;
      byte humidity = 0;

      read(&temperature, &humidity);
      Serial.println(temperature);
      Serial.println(humidity);
      delay(1000);
}

int read(byte *temperature, byte *humidity)
{
      digitalPinToBitMask(pin);
      digitalPinToPort(pin);
      byte data[40] = {0};
      sample(data);
      // 받은 data 처리

      for (size_t i = 0; i < 40; i++)
      {
            Serial.println(data[i]);
      }

      *temperature = 0;
      *humidity = 0;
}

int sample(byte data[40])
{
      // memset(data, 0, 40);
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
      delay(18 + 2);
      //
      digitalWrite(pin, HIGH);
      pinMode(pin, INPUT);
      delayMicroseconds(25);

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
            t = levelTime(LOW, 10, 6);
            if (t < 11)
            {
            }
            data[i] = (t>40 ? 1:0);
      }
}

int levelTime(byte level, int firstwait, int interval)
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
                  if (firstwait > 0)
                  {
                        delayMicroseconds(firstwait);
                  }
            }

            else if (interval > 0)
            {
                  delayMicroseconds(interval);
            }
            time = micros() - time_start;

            // LOW 상태에서 HIGH 상태로 변할때 빠져나가는 것
            loop = ((*portInputRegister(port) & bitmask) == portState);
      }

      return time;
}
