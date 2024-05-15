const int trigPin = 22;
const int echoPin = 21;
unsigned long duration; // Changed to unsigned long to handle larger values
int distance;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW); // Ensure the trigger pin is low before the pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // Measure the duration of the echo pulse
  distance = duration * 0.034 / 2; // Calculate distance based on the duration
  
  Serial.print("Duration: ");
  Serial.print(duration); // Print the duration for debugging
  Serial.print(" microseconds, Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000);
}
