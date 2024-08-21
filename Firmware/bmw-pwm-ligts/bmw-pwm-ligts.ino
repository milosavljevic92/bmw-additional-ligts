// define ports
#define PWM_OUTPUT_1 5
#define PWM_OUTPUT_2 6
#define INPUT_POSITION 7
#define INPUT_BRAKE 8

// define const
int BRAKE_INTESITY = 100; // from 0 - 100 
int POSITION_INTESITY = 80; // from 0 - 100 
int SCALE_STABIL_BLOCK = 1;
int SCALE_WEIGHT_BLOCK = 2;

int lastBrakeState = LOW;
int lastPositionState = LOW;
int pwmValue = 0;

void setup() {
  pinMode(INPUT_BRAKE, INPUT);
  pinMode(INPUT_POSITION, INPUT);
  pinMode(PWM_OUTPUT_1, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int currentBrakeState = digitalRead(INPUT_BRAKE);
  int currentPositionState = digitalRead(INPUT_POSITION);
  
  if (currentBrakeState != lastBrakeState) {
    pwmValue = map(BRAKE_INTESITY, 0, 100, 0, 255); // Mapa vrednosti 0-100 na PWM raspon 0-255
    analogWrite(PWM_OUTPUT_1, pwmValue);

    Serial.print("Brake state changed to: ");
    Serial.println(currentBrakeState);
    Serial.print("Setting PWM to: ");
    Serial.println(pwmValue);
    
    lastBrakeState = currentBrakeState;
  }
  if (currentPositionState != lastPositionState) {
    pwmValue = map(POSITION_INTESITY, 0, 100, 0, 255);
    analogWrite(PWM_OUTPUT_1, pwmValue);
    
    Serial.print("Position state changed to: ");
    Serial.println(currentPositionState);
    Serial.print("Setting PWM to: ");
    Serial.println(pwmValue);

    lastPositionState = currentPositionState;
  }
  delay(50);
}