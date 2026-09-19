#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988
#define NOTE_E6 1319

int whiteLED1 = 4;
int greenLED = 9;
int yellowLED = 10;
int redLED = 11;
int whiteLED2 = 12;

int buzzer = 7;

int button1 = 3;
int button2 = 13;

bool buttonPressed = 0;

void playVictoryTune() {
  tone(buzzer, NOTE_G5, 100);
  delay(150);
  tone(buzzer, NOTE_A5, 100);
  delay(150);
  tone(buzzer, NOTE_B5, 100);
  delay(150);
  tone(buzzer, NOTE_E6, 600);
  delay(700);
  noTone(buzzer);
  digitalWrite(buzzer, LOW);
  delay(2500);
}

void setup() {
  randomSeed(analogRead(A0));
  pinMode(whiteLED1, OUTPUT);
  pinMode(whiteLED2, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(random(900, 4901));
  digitalWrite(redLED, LOW);

  while (buttonPressed == 0) {
    digitalWrite(whiteLED1, HIGH);
    digitalWrite(whiteLED2, HIGH);
    if (digitalRead(button1) == 0) {
      buttonPressed = 1;
      digitalWrite(whiteLED2, LOW);
    } else if (digitalRead(button2) == 0) {
      buttonPressed = 1;
      digitalWrite(whiteLED1, LOW);
    }
  }
  playVictoryTune();
  buttonPressed = 0;
  digitalWrite(whiteLED1, LOW);
  digitalWrite(whiteLED2, LOW);
}