void setup() {
  pinMode(10, INPUT);
  pinMode(12, INPUT_PULLUP); // встроенная подтяжка
  pinMode(13, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  boolean button1 = !digitalRead(12); // инверсия для корректной работы с подтяжкой
  boolean button2 = digitalRead(13);

  if (button1){ // управление кнопкой от 12 пина напряжением на 13 пине + диод
    digitalWrite (13,1);
  }
  else {digitalWrite (13,0);
  }
