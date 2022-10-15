boolean button_flag = 0;
boolean button;
boolean led_enabled = 0;
unsigned long last_pressed; // время последнего нажатия для устранения дребезга кнопки

void setup() {
  pinMode(3, INPUT_PULLUP); // встроенная подтяжка
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  button = !digitalRead(3); //считываю положение кнопки
  if (button == 1 && button_flag == 0 && millis() - last_pressed > 50){ //50 миллисекунд на дребезг
      button_flag = 1;
      Serial.println("Button pressed");
      led_enabled = !led_enabled;
      digitalWrite (13, led_enabled);
      last_pressed = millis();
  }
  if (button == 0 && button_flag == 1){
      button_flag = 0;
      Serial.println("Button released");
  }
}
