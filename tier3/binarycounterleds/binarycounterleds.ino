#include <math.h>
#define VAR_IN_PIN 8
#define BITS 4

int val = 0;
int lastIn = 0;

void out()
{
  int x = BITS;
  int temp = val % (int)pow(2, BITS);
  while (--x >= 0)
  {
    int res;
    digitalWrite(x, res = temp >= pow(2, x) ? 1 : 0);
    if (res)
      temp -= pow(2, x);
  }
}

void setup()
{
  pinMode(VAR_IN_PIN, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int read = digitalRead(VAR_IN_PIN);
  if (read != lastIn)
  {
    if (read == 1)
    {
      val++;
      out();
    }
    lastIn = read;
  }
  // val++;
  // out();
  delay(50);
}
