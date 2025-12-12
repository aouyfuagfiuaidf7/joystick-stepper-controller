#include <Stepper.h>

const int stepsPerRevolution = 2048; // for 28BYJ-48
const int X = A0;
const int Y = A1;
const int SW = 2;
const int green = 7;
const int red = 8;
unsigned long lastStateUpdate = 0;
const int stateUpdateInterval = 500;

bool permit = false;      // motor operation permission flag
bool lastState = HIGH;    // previous button state

Stepper myStepper(stepsPerRevolution, 3, 5, 4, 6);

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  myStepper.setSpeed(10); // initial speed
}

void loop() {
  bool buttonPressed = (digitalRead(SW) == LOW);

  // button press handling: HIGH -> LOW transition
  if (lastState == HIGH && buttonPressed) {
    if (millis() - lastStateUpdate >= stateUpdateInterval) {
        permit = !permit;  // toggle flag
        lastStateUpdate = millis();
    }
  }
  lastState = buttonPressed;

  if (permit) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);

    int posX = analogRead(X);
    int posY = analogRead(Y);

    // speed control via Y axis
    int speed = map(posY, 0, 1023, 1, 20);
    myStepper.setSpeed(speed);

    // calculate X offset from center
    int deltaX = posX - 512;
    
    // deltaX = -512 → steps = -50 (left edge)
    // deltaX = 0    → steps = 0   (center)
    // deltaX = +512 → steps = +50 (right edge)

    // apply dead zone of ±50
    if (abs(deltaX) > 50) {
      int steps = map(deltaX, -512, 512, -50, 50); 
      myStepper.step(steps);
    }
    // if within dead zone → motor stops
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    // motor does not move
  }
}