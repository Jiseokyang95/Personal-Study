/*
HC-SR04 초음파 센서로 거리 측정
*/
#include <LiquidCrystal_I2C.h>      // LiquidCrystal_I2C 헤더파일 호출
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD의 address 주소 및 크기 입력

#define trigPin 4
#define echoPin 5
#define BuzzerPin 9

long duration, distance;

void setup()
{
      Serial.begin(115200);
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      pinMode(BuzzerPin, OUTPUT);
      lcd.init();
      lcd.backlight();
}

void loop()
{
      Measure_USMeter();
      SerialPort();
      LCD_Print();
      Buzzer_Tone();
}

void Measure_USMeter() // 초음파 센서 거리 측정
{
      digitalWrite(trigPin, LOW);
      digitalWrite(echoPin, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin, HIGH); // trigPin에서 초음파 발생
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH); // echoPin 이 HIGH를 유지한 시간을 저장 한다.
      distance = ((float)(340 * duration) / 1000) / 2;
}

void SerialPort() // 시리얼 모니터 출력
{
      Serial.print("Duration:"); // 시리얼모니터에 Echo가 HIGH인 시간을 표시
      Serial.print(duration);
      Serial.print("\nDIstance:"); // 물체와 초음파 센서간 거리를 표시
      Serial.print(distance);
      Serial.println("mm\n");
}

void LCD_Print() // LCD 출력
{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Duration : ");
      lcd.print(duration);
      lcd.setCursor(0, 1);
      lcd.print("Distance : ");
      lcd.print(distance);
      lcd.print("mm");
}

void Buzzer_Tone() // Buzzer 발생
{
      if (distance < 10) // 거리 10이하 시 경고음 지속
      {
            tone(BuzzerPin, 'C', distance * 20);
      }

      if (distance > 10 && distance < 200) // 거리 200 이하 접근시 소리 가속화
      {
            tone(BuzzerPin, 'C', distance * 2);
            delay(distance * 10);
      }
}