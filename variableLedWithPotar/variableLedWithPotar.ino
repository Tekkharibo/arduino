int blueLed = 3;
int analogPin = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(blueLed, OUTPUT);
}

void loop() {
  int i = 0;
  int j = 0;
  int k = 0;
  int val = 0;
  bool turn = true;
  while (1)  {
    val = analogRead(analogPin);
    analogWrite(blueLed, 255 - (val / 4));
    Serial.println(val);
    delay(10);
  }
}
