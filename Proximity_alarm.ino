#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PING  6
#define LED_PINR  5
#define LED_PINB  3
#define THRESHOLD_CM1 30
#define THRESHOLD_CM2 20
#define THRESHOLD_CM3 10
#define BUZZER_PIN 11
void setup() {
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(LED_PINR,OUTPUT);
  pinMode(LED_PING,OUTPUT);
  pinMode(LED_PINB,OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}
long getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;  // convert to cm
}

void loop() {
  long dist = getDistanceCM();

  if (dist > 0 && dist < THRESHOLD_CM3) {
    digitalWrite(LED_PING, HIGH);
    tone(BUZZER_PIN, 1000);
  } else {
    digitalWrite(LED_PING, LOW);
    noTone(BUZZER_PIN);
  }
   if (dist > THRESHOLD_CM3 && dist < THRESHOLD_CM2) {
    digitalWrite(LED_PINR, HIGH);
  } else {
    digitalWrite(LED_PINR, LOW);
  }
   if (dist > THRESHOLD_CM2 && dist < THRESHOLD_CM1) {
    digitalWrite(LED_PINB, HIGH);
  } else {
    digitalWrite(LED_PINB, LOW);
  }

  delay(100);

}
