int red = 14;
int green = 13;
int yellow = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED as an output.
  pinMode(13, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  delay(1000);                       // wait for a second

  digitalWrite(green, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  delay(1000);                       // wait for a second

  digitalWrite(green, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(1000);                       // wait for a second
}

