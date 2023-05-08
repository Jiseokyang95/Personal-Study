/*
'O', 'x'로 만든 미니 핵맨 게임.
Delay함수는 지양하고 millis함수를 이용하여 게임 진행
스위치 작동시 게임이 시작되고,
2초 마다 x를 생성한 후 사용자가 이를 잡아가는 형식
*/

#include <LiquidCrystal_I2C.h>      // LiquidCrystal_I2C 헤더파일 호출
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD의 address 주소 및 크기 입력

#define ClickPin 8          // Click Digital pin NUM
int joystick_x = 0;         // Analog pin Num
int joystick_y = 1;         // Analog pin Num
int Axle_x = -1;            // 사용자 초기 위치
int Axle_y = 0;             // 사용자 초기 위치
int seed_x[32] = {-2};      // Seed의 위치를 저장하는 배열로서 버그 방지를 위해 초기 값 선정
int seed_y[32] = {-2};      // Seed의 위치를 저장하는 배열로서 버그 방지를 위해 초기 값 선정
int score = 0;              // O이 x 만났을 시 점수 획득 변수
bool isGameStarted = false; // 게임 시작 여부를 판단하는 변수

unsigned long prevMillis = 0;  // millis 이전 값
unsigned long interval = 2000; // 2초마다 seed를 생성하도록 설정

void setup() // 초기화
{
      Serial.begin(115200);
      lcd.init();                      // LCD 초기화
      lcd.backlight();                 // LCD 백라이트 함수
      pinMode(ClickPin, INPUT_PULLUP); // 풀업 방식
}

void loop()
{
      switch (isGameStarted)
      {
      case true:
            // 게임 진행
            Serial.println(score);
            Control_X();
            Control_y();
            Create_seed();
            get_seed();
            break;

      case false:
            // 게임 시작 전
            lcd.setCursor(0, 0);
            lcd.println("  Button Start  ");
            delay(100);
            if (digitalRead(ClickPin) == LOW)
            {
                  isGameStarted = true;
                  lcd.clear();
            }
            break;
      }
}

void Create_seed() // 2초에 한번씩 x 생성
{
      unsigned long currentMillis = millis();
      static int i = 0;
      if (currentMillis - prevMillis >= interval)
      {
            prevMillis = currentMillis;

            seed_x[i] = random(15); // lcd 위치
            seed_y[i] = random(2);

            lcd.setCursor(seed_x[i], seed_y[i]);
            lcd.print("x");

            i++;
            if (i == 32) // 씨드 배열 Full 시 리셋
                  i = 0;
      }
}

void get_seed() // 사용자가 x를 get 했을 때
{
      static unsigned long prevMillis = 0;
      const unsigned long interval = 100;

      if (millis() - prevMillis >= interval)
      {
            prevMillis = millis();

            for (int j = 0; j < 32; j++)
            {
                  if (seed_x[j] == -1 && seed_y[j] == -1)
                        continue; // (-1,-1)로 초기화한 seed는 무시

                  if (Axle_x == seed_x[j] && Axle_y == seed_y[j])
                  {
                        score++;
                        seed_x[j] = -1; // 시드 값 초기화
                        seed_y[j] = -1;
                        break; // 해당 seed와 충돌하면 반복문 탈출
                  }
            }

            if (score == 10) // x get 10회 시 게임 클리어
            {
                  Game_Clear();
            }
      }
}

void Game_Clear() // game clear시 초기화
{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Game Clear");
      delay(5000);

      score = 0;
      Axle_x = 0;
      Axle_y = 0;
      for (int j = 0; j < 32; j++)
      {
            seed_x[j] = -1;
            seed_y[j] = -1;
      }
      lcd.clear();
}

/*
void Click_switch()
{
      if (digitalRead(ClickPin) == LOW)
      {
            int Seed_x = random(15);
            int Seed_y = random(2);

            lcd.setCursor(Seed_x, Seed_y);
            lcd.print("x");
            delay(100);
      }
}
*/

void Control_joystick() // 조이스틱 컨트롤
{
      static unsigned long prevMillis = 0;
      unsigned long currentMillis = millis();
      if (currentMillis - prevMillis >= 100)
      {
            lcd.setCursor(Axle_x, Axle_y);
            lcd.print("O");
            prevMillis = currentMillis;
      }
}

void Control_X() // x값 변화시
{
      static unsigned long prevMillis = 0;
      unsigned long currentMillis = millis();
      if (currentMillis - prevMillis >= 100)
      {
            prevMillis = currentMillis;
            int x = analogRead(joystick_x); // 조이스틱 X축의 아날로그 신호를 x에 저장
            if (x > 1000 && Axle_x < 15)
            {
                  Axle_x++;
                  lcd.setCursor(Axle_x - 1, Axle_y);
                  lcd.print(" ");
                  Control_joystick();
            }

            else if (x < 200 && Axle_x > 0)
            {
                  Axle_x--;
                  lcd.setCursor(Axle_x + 1, Axle_y);
                  lcd.print(" ");
                  Control_joystick();
            }
      }
}

void Control_y() // y 값 변화시
{
      static unsigned long prevMillis = 0;
      unsigned long currentMillis = millis();
      if (currentMillis - prevMillis >= 100)
      {
            prevMillis = currentMillis;

            int y = analogRead(joystick_y); // 조이스틱 y축의 아날로그 신호를 y에 저장
            if (y > 1000 && Axle_y < 1)
            {
                  Axle_y++;
                  lcd.setCursor(Axle_x, Axle_y - 1);
                  lcd.print(" ");
                  Control_joystick();
            }

            else if (y < 200 && Axle_y > 0)
            {
                  Axle_y--;
                  lcd.setCursor(Axle_x, Axle_y + 1);
                  lcd.print(" ");
                  Control_joystick();
            }
      }
}