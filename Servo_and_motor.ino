#include <Servo.h> //includes a servo setting

/*
 * Description:
 * Example for setting the minimal and maximal angle while Motor is running
 */ 

static const int servoPin = 13; //for servo
Servo servo1;

int motor1Pin1 = 22; //for Dc motor
int motor1Pin2 = 21; //for Dc motor
int enable1Pin = 23; //for Dc motor

// Setting PWM properties for motor
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 100;



void setup() {
  // sets the pins as outputs for motor:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // configure LED PWM functionalitites for servo
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
    Serial.begin(115200);
    servo1.attach(
        servoPin, 
        Servo::CHANNEL_NOT_ATTACHED, 
        45,
        120
    );
}

void loop() {
   serve(); // this the file for servo in loop
    motor(); // this the file for motor in loop
}
void serve() // this the file for servo in loop
{
  for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
}
void motor() // this the file for dc motor in loop
{

  // Move DC motor forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  while (dutyCycle < 100){
    
    ledcWrite(pwmChannel, dutyCycle);   
    dutyCycle = dutyCycle + 2;
    delay(2000);
  }
  while (dutyCycle < 200){
    
    ledcWrite(pwmChannel, dutyCycle);   
    dutyCycle = dutyCycle + 2;
    delay(200);
  }
   while (dutyCycle <255){
    
    ledcWrite(pwmChannel, dutyCycle);   
    dutyCycle = dutyCycle + 45; //dutycyle = 245
    delay(10000);
  }
  
  dutyCycle = 100;
}
