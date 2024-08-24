/* bmw-pwm-lights: Main firmware
 - WHAT IT DOES
 - SEE the comments after "//" on each line below
 - CONNECTIONS: ESP32
   - 
   - 
 - V1.00 08/22/2024
   Questions: */

// define ports
#define PWM_OUTPUT_1 12
#define PWM_OUTPUT_2 14
#define INPUT_POSITION 35
#define INPUT_BRAKE 34

// define const
int BRAKE_INTESITY = 100; // from 0 - 100 
int POSITION_INTESITY = 50; // from 0 - 100 

int DEBUG_SERIAL_BAUNDRATE = 9600;

int pwmValue = 0;
int LIGHT_POSITION;
int LIGHT_BRAKE;

void setup() {
  pinMode(INPUT_BRAKE, INPUT);
  pinMode(INPUT_POSITION, INPUT);
  pinMode(PWM_OUTPUT_1, OUTPUT);
  analogWrite(PWM_OUTPUT_1, pwmValue);
  Serial.begin(DEBUG_SERIAL_BAUNDRATE);
}

void loop() {
  LIGHT_POSITION = digitalRead(INPUT_POSITION);
  LIGHT_BRAKE = digitalRead(INPUT_BRAKE);

  if(LIGHT_POSITION == 1 && LIGHT_BRAKE == 0) {
    pwmValue = map(POSITION_INTESITY, 0, 100, 0, 255);
    analogWrite(PWM_OUTPUT_1, pwmValue);
  }

  if(LIGHT_POSITION == 0 && LIGHT_BRAKE == 0) {
    analogWrite(PWM_OUTPUT_1, 0);
  }

  if(LIGHT_BRAKE == 1) {
    pwmValue = map(BRAKE_INTESITY, 0, 100, 0, 255);
    analogWrite(PWM_OUTPUT_1, pwmValue);
  }

  Serial.print("POSITION");
  Serial.print(" : ");
  Serial.print(LIGHT_POSITION);
  Serial.print("  ");
  Serial.print("BRAKE");
  Serial.print(" : ");
  Serial.println(LIGHT_BRAKE);
  delay(100);
}