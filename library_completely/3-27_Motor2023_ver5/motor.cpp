#include "motor.h"
Motor::Motor() { 
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
  
  ledcSetup(CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcSetup(CHANNEL_1, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcSetup(CHANNEL_2, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcSetup(CHANNEL_3, LEDC_BASE_FREQ, LEDC_TIMER_BIT);

  ledcAttachPin(AIN1, CHANNEL_0);//right motor pwm
  ledcAttachPin(AIN2, CHANNEL_1);
  ledcAttachPin(BIN1, CHANNEL_2);//left motor pwm
  ledcAttachPin(BIN2, CHANNEL_3);
}
void Motor::forward(uint32_t pwm) {
  if (pwm > VALUE_MAX) {
    pwm = VALUE_MAX;
  }
  ledcWrite(0, pwm);
  ledcWrite(1, 0);
  ledcWrite(2, pwm);
  ledcWrite(3, 0);
}
void Motor::Rforward(uint32_t pwm) {
  if (pwm > VALUE_MAX) {
    pwm = VALUE_MAX;
  }
  ledcWrite(0, pwm);
  ledcWrite(1, 0);
}
void Motor::Lforward(uint32_t pwm) {
  if (pwm > VALUE_MAX) {
    pwm = VALUE_MAX;
  }
  ledcWrite(2, pwm);
  ledcWrite(3, 0);
}
void Motor::back(uint32_t pwm) {
  if (pwm > VALUE_MAX) {
    pwm = VALUE_MAX;
  }
  ledcWrite(0, 0);
  ledcWrite(1, pwm);
  ledcWrite(2, 0);
  ledcWrite(3, pwm);
}

void Motor::brake(uint32_t pwm) {
  ledcWrite(CHANNEL_0, 255);
  ledcWrite(CHANNEL_1, 255);  
  ledcWrite(CHANNEL_2, 255);
  ledcWrite(CHANNEL_3, 255);  
}
