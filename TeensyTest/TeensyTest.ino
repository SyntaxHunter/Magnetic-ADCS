// constant pin numbers
const int ledPin = 13;    // the number of the LED pin

char incomingByte = 'F';
int ledStatus = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  while(!Serial); // wait for serial port to connect
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (incomingByte == 'O' && ledStatus == 0) {
    // turn LED on:
    Serial.println("Turning LED on");
    digitalWrite(ledPin, HIGH);
    ledStatus = 1;
  } else if (incomingByte == 'F' && ledStatus == 1) {
    // turn LED off:
    Serial.println("Turning LED off");
    digitalWrite(ledPin, LOW);
    ledStatus = 0;
  }
}
