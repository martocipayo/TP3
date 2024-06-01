int boton = 2;

void setup() {
  pinMode(boton, INPUT);
  pinMode(A2, INPUT);
  pinMode(9, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(boton) == LOW) {
   
    analogWrite(9, 255);
    analogWrite(10, 255);
    analogWrite(11, 255);

    Serial.println("Tiene 5 s para configurar el color del led....");
    delay(5000); 

   
    int redValue = map(analogRead(A0), 0, 1023, 0, 255);
    int greenValue = map(analogRead(A1), 0, 1023, 0, 255);
    int blueValue = map(analogRead(A2), 0, 1023, 0, 255);

   
    analogWrite(9, redValue);
    analogWrite(10, greenValue);
    analogWrite(11, blueValue);

    Serial.print("El led esta usando esta configuración de colores RGB: (");
    Serial.print(redValue);
    Serial.print(", ");
    Serial.print(greenValue);
    Serial.print(", ");
    Serial.print(blueValue);
    Serial.println(")");

    delay(5000); 

    
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);

  
    while (digitalRead(boton) == LOW) {
      delay(10);
    }
  }
}