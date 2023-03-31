#include <Servo.h>

/*
 * Description:
 * Example for setting the minimal and maximal angle.
 */ 

static const int servoPin = 13;
int motor1Pin1 = 22; 
int motor1Pin2 = 21; 
int enable1Pin = 23; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 100;

Servo servo1;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // configure LED PWM functionalitites
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
   serve();
   // motor();
}
void serve()
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
void motor()
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
