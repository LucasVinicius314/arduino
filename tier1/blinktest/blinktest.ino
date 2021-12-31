void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  // digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  // digitalWrite(2, LOW);
  delay(1000);
}
