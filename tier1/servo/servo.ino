#include <Servo.h>

#define SERVO 2

Servo s;
bool on = true;

using namespace std;

void setup()
{
  Serial.begin(9600);

  s.attach(SERVO);
  s.write(0);
}

void loop()
{
  if (!on)
    return;
}