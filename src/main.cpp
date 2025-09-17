#include <Arduino.h>
#include <Servo.h>

// Documentação: https://docs.arduino.cc/libraries/servo/
Servo myServo;

int porta_motor = 9;
int porta_potenciometro = A0;

// Roda ao iniciar:
void setup()
{
  myServo.attach(porta_motor);
}

// Documentação do map: https://docs.arduino.cc/language-reference/en/functions/math/map/

// Roda em loop:
void loop()
{
  // lê o valor do potenciometro
  int valor_potenciometro = analogRead(porta_potenciometro);
  // recebe o valor do potenciometro (0 - 1023)
  // e converte para o motor (0 - 180)
  int valor_motor = map(valor_potenciometro, 0, 1023, 0, 180);
  // manda o sinal para o motor
  myServo.write(valor_motor);
  delay(15);
}