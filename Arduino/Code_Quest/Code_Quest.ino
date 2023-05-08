/*
- 시계의 각도는?
    - 3시정각은 90도입니다.
    - 6시정각은 180도 입니다.
    - 9시 정각은 270도입니다.
    - 12시 정각은 0도입니다.
    - 180도를 넘어가면 작은 각으로 계산합니다.
    - 1분단위로 12시간에 대한 결과를 시리얼 포트로 표시합니다. ⇒ 720개
    - 예시 - 시침이 변하는 고려, 소수점 2자리까지
        - 12:01 - 5.5'
        - 12:02 - 359.17'
        - 11:59 - 0.83'
*/

#include <LiquidCrystal_I2C.h>      // LiquidCrystal_I2C 라이브러리 호출
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD의 I2C 주소와 크기 설정

const double MIN_ANGLE = 6;   // 1분당 회전하는 각도
const double H_H_ANGLE = 30;  // 1시간당 회전하는 각도
const double H_M_ANGLE = 0.5; // 1분당 시침이 회전하는 각도
const double MAX_ANGLE = 180; // 최대 회전 각도

void setup()
{
      Serial.begin(115200); // 시리얼 통신 속도 설정
      lcd.init();           // LCD 초기화
      lcd.backlight();      // LCD 화면 ON
}

void loop()
{
      // unsigned int Seconds = 43320;      // 초 시간 설정
      for (int i = 0; i < 721; i++)
      {
            unsigned int Seconds = 60 * i;
            int hours = (Seconds / 3600) % 12; // 시간 계산
            int minutes = (Seconds / 60) % 60; // 분 계산

            double Hour_angle = hours * H_H_ANGLE + minutes * H_M_ANGLE;
            Serial.println(Hour_angle);
            double Min_angle = minutes * MIN_ANGLE;
            Serial.println(Min_angle);
            double diff = abs(Hour_angle - Min_angle);
            Serial.println(diff);
            if (diff > 180)
            {
                  diff = 360 - diff;
            }

            Serial.print("Time - ");
            Serial.print(hours);
            Serial.print(" : ");
            Serial.print(minutes);
            Serial.println("");
            Serial.print("Angle - ");
            Serial.print(diff);
            Serial.println("'");
            delay(1000);

            lcd.setCursor(0, 0);
            lcd.print("Time : ");
            lcd.print(hours);
            lcd.print(" : ");
            lcd.print(minutes);
            lcd.setCursor(0, 1);
            lcd.print("Angle : ");
            lcd.print(diff);
            delay(1000);
            lcd.clear();
            
            if(i=720)
            i=0;
      }
}