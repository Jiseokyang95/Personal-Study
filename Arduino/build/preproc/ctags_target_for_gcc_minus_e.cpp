# 1 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
/*

- 아두이노에서 스위치를 누르면 LED를 펄스를 이용해서 동작시키기, 

  1초에 한번누르면 깜박이고, 또 누르면 0.5초에 한번 깜빡이고,

  또한번 누르면 계속 켜지고, 이후에 순환되는 방식으로 한다.

- 그러다가 2초간 꾸욱 누르면 꺼진다.

- 스위치를 누르는 동안에도 기존 동작은 멈춰선 안된다.

*/
# 9 "C:\\Users\\wltjr\\source\\repos\\Personal-Study\\Arduino\\PiezoBuzzer\\PiezoBuzzer.ino"
int i = 3;
int led = 8;
int interruptpin = 2;
int interruptpin2 = 3;
unsigned long cnt = 0;

void setup()
{
    pinMode(led, 0x1);
    pinMode(interruptpin, 0x2);
    Serial.begin(115200);
    attachInterrupt(((interruptpin) == 2 ? 0 : ((interruptpin) == 3 ? 1 : -1)), interrupt, 2);
    attachInterrupt(((interruptpin2) == 2 ? 0 : ((interruptpin2) == 3 ? 1 : -1)), interrupt2, 3);
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
    digitalWrite(led, 0x1);
    delay(1000);
    digitalWrite(led, 0x0);
    delay(1000);
}
void halfsecond() //0.1초마다 깜빡
{
    digitalWrite(led, 0x1);
    delay(100);
    digitalWrite(led, 0x0);
    delay(100);
}
void full() //켜져있는 상태
{
    digitalWrite(led, 0x1);
    delay(1000);
    digitalWrite(led, 0x0);
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
        digitalWrite(led, 0x0);
    delay(100000000000);
    }
}
