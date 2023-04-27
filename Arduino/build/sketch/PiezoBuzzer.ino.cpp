#include <Arduino.h>
#line 1 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
/*
- 아두이노에서 스위치를 누르면 LED를 펄스를 이용해서 동작시키기, 
  1초에 한번누르면 깜박이고, 또 누르면 0.5초에 한번 깜빡이고,
  또한번 누르면 계속 켜지고, 이후에 순환되는 방식으로 한다.
- 그러다가 2초간 꾸욱 누르면 꺼진다.
- 스위치를 누르는 동안에도 기존 동작은 멈춰선 안된다.
*/

int i = 3;
int led = 8;
int interruptpin = 2;
int interruptpin2 = 3;
unsigned long cnt = 0;

#line 15 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void setup();
#line 24 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void loop();
#line 33 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void second();
#line 40 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void halfsecond();
#line 47 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void full();
#line 55 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void interrupt();
#line 65 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void interrupt2();
#line 15 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
void setup()
{
    pinMode(led, OUTPUT);
    pinMode(interruptpin, INPUT_PULLUP);
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(interruptpin), interrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(interruptpin2), interrupt2, RISING);
}

void loop()
{
    if (i % 3 == 0)
        second();
    else if (i % 3 == 1)
        halfsecond();
    else if (i % 3 == 2)
        full();
}
void second() //1초마다 깜빡
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}
void halfsecond() //0.1초마다 깜빡
{
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
}
void full() //켜져있는 상태
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1);
}

void interrupt() //누르는 순간
{
    if(millis()-cnt > 150) 
    {
        i++;
        Serial.println(i);
        Serial.println(cnt);
    }
    cnt = millis();
}
void interrupt2() //떼는 순간
{
    if(millis()-cnt > 2000)
    {
        digitalWrite(led, LOW);
    delay(100000000000);
    }
}
