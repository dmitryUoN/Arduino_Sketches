unsigned long timer;

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (millis() - timer > 1000) {
       timer = millis();
       Serial.println("Big Ass!!!");
  }
}
