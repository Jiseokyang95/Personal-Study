int i = 0;
int led = 8;
int interruptpin = 2;
int interruptpin2 = 3;
int Serialbutton = 0;
int buttonstate = 0;
unsigned long cnt = 0;
String stringbutton = "";

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
      serial_button();
      if (i>=0 && i % 3 == 0)
      {
            second();
            Serial.println("1s blink");
      }
      else if (i>0 && i % 3 == 1)
      {
            halfsecond();
            Serial.println("0.5s blink");
      }
      else if (i>0 && i % 3 == 2)
      {
            full();
            Serial.println("on");
      }
      else if(i == -1)
      {
            digitalWrite(led, LOW);
      }
}
void second() // 1초마다 깜빡
{
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      delay(1000);
}
void halfsecond() // 0.1초마다 깜빡
{
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
}
void full() // 켜져있는 상태
{
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      delay(1);
}

void interrupt() // 누르는 순간
{
      if (millis() - cnt > 150)
      {
            i++;
            Serial.println(i);
      }
      cnt = millis();
}
void interrupt2() // 떼는 순간
{
      if (millis() - cnt > 2000)
      {
            digitalWrite(led, LOW);
            i = -1;
            Serial.println("off");
      }
}

void serial_button() // 시리얼 모니터를 이용 제어 값 입력
{
      if (Serial.available() > 0)
      {
            stringbutton = Serial.readString();
            Serial.println(stringbutton);
            if (stringbutton.compareTo("one") == 0)
            {
                  Serial.println("1s blink");
                  i = 0;
            }
            else if (stringbutton.compareTo("two") == 0)
            {
                  Serial.println("0.5s blink");
                  i = 1;
            }
            else if (stringbutton.compareTo("three") == 0)
            {
                  Serial.println("on");
                  i = 2;
            }
            else if (stringbutton.compareTo("zero") == 0)
            {
                  Serial.println("off");
                  i = -1;
                  digitalWrite(led, LOW);
            }
      }
}