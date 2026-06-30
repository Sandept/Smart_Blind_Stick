#define trigPin 8
#define echoPin 9
#define buzzer 6
#define vibrator 2

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(vibrator, OUTPUT);

  digitalWrite(vibrator, LOW);
  noTone(buzzer);
  Serial.begin(9600);
}   
void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read echo
  duration = pulseIn(echoPin, HIGH, 30000); // No object found
  if (duration == 0) {
    noTone(buzzer);
    digitalWrite(vibrator, LOW);
    return;
  }

    // Distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

    // Out of range
  if (distance < 2 || distance > 100) {
    noTone(buzzer);
    digitalWrite(vibrator, LOW);
    delay(100);
    return;
  }

  // Vibrator ON only when very close
  if (distance <= 10) {
    digitalWrite(vibrator, HIGH);
  } else {
    digitalWrite(vibrator, LOW);
  }

  // Faster beep when object gets closer
  int beepDelay = map(distance, 2, 100, 50, 500);
  tone(buzzer, 2500);
  delay(80);
  noTone(buzzer);
  delay(beepDelay);
}