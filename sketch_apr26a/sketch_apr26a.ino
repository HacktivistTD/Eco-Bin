
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

unsigned long previousMillis = 0;
const long interval = 1000;  // Interval in milliseconds (0.5 minute)
const int ledPin1 = 2;
const int ledPin2 = 4;
const int ledPin3 = 13;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  if (currentMillis - previousMillis >= interval) {
    // Update previousMillis to currentMillis
    previousMillis = currentMillis;

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(1000);
    // Sets the trigPin on HIGH state for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    // Turn off all LEDs before checking distance
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

    if (distance >= 6) {
      // Turn LED 1 on
      digitalWrite(ledPin1, HIGH);
    } else if (distance >= 4 && distance < 6) {
      // Turn LED 2 on
      digitalWrite(ledPin2, HIGH);
    } else if (distance <= 3) {
      // Turn LED 3 on
      digitalWrite(ledPin3, HIGH);
    }
  }
}