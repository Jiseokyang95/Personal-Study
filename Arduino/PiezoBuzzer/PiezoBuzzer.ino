const int speakerPin = 8; // 연결된 핀 번호
const int octave = 4; // 옥타브
const int noteDuration = 500; // 음표 길이 (단위: ms)
int Melody[100] = 
{'G','G','A','A','G','G','E','G','G','E','E','D'};
void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for(int i=0; i<100; i++)
  {
  playTone(Melody[i], octave, noteDuration); // C5 음표를 연주합니다.
  }
}

void playTone(char note, int octave, int duration) {
  double frequency = getFrequency(note, octave);
  int period = 1000000 / frequency;
  int pulseWidth = period / 2;
  int numPeriods = duration * frequency / 1000;

  
  for (int i = 0; i < numPeriods; i++) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(pulseWidth);
  }
}

double getFrequency(char note, int octave) {
  const double baseFrequency = 55.0;
  int noteIndex = -10;
  switch (note) {
    case 'C': noteIndex = 0; break;
    case 'D': noteIndex = 2; break;
    case 'E': noteIndex = 4; break;
    case 'F': noteIndex = 5; break;
    case 'G': noteIndex = 7; break;
    case 'A': noteIndex = 9; break;
    case 'B': noteIndex = 11; break;
    default: return 0;
  }
  return baseFrequency * pow(2.0, octave-1) * pow(2.0, noteIndex/12.0);
}