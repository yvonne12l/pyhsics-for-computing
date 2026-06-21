int led =13;
int pir =7;
int pirdato;

void setup ()
{
  pinMode (led, OUTPUT);
  pinMode(pir,INPUT);
}

void loop()
{
  pirdato = digitalRead(pir);
  if (pirdato == HIGH)
  {
      digitalWrite(led, HIGH);
  }
  else
  {
      digitalWrite(led, LOW);
  }
  delay(10);
}
