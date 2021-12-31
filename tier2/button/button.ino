#define PIN 8
int pin = 0;

void setup()
{
  pinMode(PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  pin = digitalRead(PIN) == 1 ? 0 : 1;
  digitalWrite(LED_BUILTIN, pin);
  delay(50);
}
