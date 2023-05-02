# 1 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
int pin = 8;
uint8_t bitmask = 0xFF;
long levelTimeout = 500000; // 500ms
uint8_t port = 0xFF;

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
      ( 
# 24 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino" 3
     (__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(
# 24 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
     digital_pin_to_bit_mask_PGM + (pin)
# 24 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino" 3
     )); uint8_t __result; __asm__ __volatile__ ( "lpm %0, Z" "\n\t" : "=r" (__result) : "z" (__addr16) ); __result; })) 
# 24 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
     );
      ( 
# 25 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino" 3
     (__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(
# 25 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
     digital_pin_to_port_PGM + (pin)
# 25 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino" 3
     )); uint8_t __result; __asm__ __volatile__ ( "lpm %0, Z" "\n\t" : "=r" (__result) : "z" (__addr16) ); __result; })) 
# 25 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
     );
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
      pinMode(pin, 0x1);
      digitalWrite(pin, 0x0);
      delay(18 + 2);
      //
      digitalWrite(pin, 0x1);
      pinMode(pin, 0x0);
      delayMicroseconds(25);

      long t = levelTime(0x0, 10, 6);
      if (t < 40)
      {
            return -1;
      }

      t = levelTime(0x1, 10, 6);
      if (t < 40)
      {
            return -1;
      }

      for (size_t i = 0; i < 40; i++)
      {
            t = levelTime(0x0, 10, 6);
            if (t < 24)
            {
            }
            t = levelTime(0x0, 10, 6);
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
            loop = ((*( (volatile uint8_t *)( 
# 105 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino" 3
                     (__extension__({ uint16_t __addr16 = (uint16_t)((uint16_t)(
# 105 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
                     port_to_input_PGM + (port)
# 105 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino" 3
                     )); uint16_t __result; __asm__ __volatile__ ( "lpm %A0, Z+" "\n\t" "lpm %B0, Z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
# 105 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\dht_basic\\dht_basic.ino"
                     ) ) & bitmask) == portState);
      }

      return time;
}
