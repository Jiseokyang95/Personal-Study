#define LED 9
//#define SWITCH 8 

void setup()
{
      pinMode(LED, OUTPUT);
      //pinMode(SWITCH, INPUT_PULLUP);
}

void loop()
{
      digitalWrite(LED, HIGH);
}