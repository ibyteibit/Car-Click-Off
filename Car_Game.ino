#include "pitches.h";

const int fan1pwm = 9;
const int fan2pwm = 10;

const int Led1 = 7;  // LEDs
const int Led2 = 8;

const int buzz1 = 2;  // Buzzers
const int buzz2 = 3;

const int IRpin1 = 12;  // IR tripwires
const int IRpin2 = 13;

const int button1 = 5;  // Push buttons
const int button2 = 6;

unsigned long m1, m2, m11, m21 = 0;
bool wasPressed, wasPressed1 = false;

int speed, speed1;

void setup() {
  // put your setup code here, to run once:
  pinMode(fan1pwm, OUTPUT);
  pinMode(fan2pwm, OUTPUT);

  pinMode(Led1, OUTPUT);  // LED pin as output
  pinMode(Led2, OUTPUT);

  pinMode(buzz1, OUTPUT);  // Buzzer pin as output
  pinMode(buzz2, OUTPUT);

  pinMode(IRpin1, INPUT);  // Photo interrupter pin as input
  pinMode(IRpin2, INPUT);

  pinMode(button1, INPUT);  // Button input
  pinMode(button2, INPUT);

  pinMode(IRpin1, INPUT);
  pinMode(IRpin2, INPUT);

  Serial.begin(9600);
}



void loop() {
  m2 = millis();
  m21 = millis();


  if (digitalRead(IRpin1) == LOW) {  // turn LED on when sensor is blocked
    victory(1);
  } else if (digitalRead(IRpin2) == LOW) {
    victory(2);
  } 
  else {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
  }

  if (!wasPressed && digitalRead(button1) == HIGH) {
    speed = (int)(13000 / (m2 - m1));
    if (speed > 255) {
      speed = 255;
    }
    wasPressed = !wasPressed;

  } else if (wasPressed && digitalRead(button1) == LOW) {
    wasPressed = !wasPressed;
    m1 = m2;
  } else if ((m2 - m1) >= 200) {
    speed *= .999999;
  }

  analogWrite(fan1pwm, speed);

  if (!wasPressed1 && digitalRead(button2) == HIGH) {
    speed1 = (int)(13000 / (m21 - m11));
    if (speed1 > 255) {
      speed1 = 255;
    }
    wasPressed1 = !wasPressed1;

  } else if (wasPressed1 && digitalRead(button2) == LOW) {
    wasPressed1 = !wasPressed1;
    m11 = m21;
  } else if ((m21 - m11) >= 200) {
    speed1 *= .999999;
  }

  analogWrite(fan2pwm, speed1);

  Serial.println(speed);

}

int melody[] = {

  NOTE_A3, NOTE_CS3, NOTE_E3, NOTE_A4, NOTE_CS4, 0, NOTE_B3, NOTE_DS3, NOTE_F3, NOTE_B4, NOTE_C4, 0, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_FS4
};

int noteDurations[] = {

  8, 8, 8, 8, 4, 4,  8, 8, 8, 8, 4, 4, 4, 1.33, 1.33, 1.33, 4
};

void victory(int winner) {
  Serial.println(winner);
  analogWrite(fan1pwm, 0);
  analogWrite(fan2pwm, 0);
  if (winner == 1) {
    

    for (int note = 0; note < *(&noteDurations + 1) - noteDurations; note++) {
      digitalWrite(Led1, HIGH);
      int noteDuration = 1000 / noteDurations[note];

      tone(buzz1, melody[note], noteDuration);

      int pause = noteDuration * 1.30;

      delay(pause);
      digitalWrite(Led1, LOW);
      noTone(buzz1);
    }
  } else {
    digitalWrite(Led2, HIGH);
    for (int note = 0; note < *(&noteDurations + 1) - noteDurations; note++) {

      int noteDuration = 1000 / noteDurations[note];

      tone(buzz2, melody[note], noteDuration);

      int pause = noteDuration * 1.30;

      delay(pause);

      noTone(buzz2);
    }
  }
}