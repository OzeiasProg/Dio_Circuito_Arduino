
// Definição das portas
const int sensorPin = A0;    // Entrada analógica para o sensor de temperatura
const int motorPin = 8;      // Saída digital para o motor
const int ledPin = 13;       // Saída digital para o LED
const int buzzerPin = 2;     // Saída digital para a buzina

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Para monitorar a temperatura no Serial Monitor
}

void loop() {
  // Leitura do sensor
  int sensorValue = analogRead(sensorPin);
  
  // Conversão para temperatura aproximada (assumindo sensor LM35)
  float temperatura = (sensorValue*0.4868)-50.049;

  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  // Controle do motor
  if (temperatura > 30.0) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  // Controle do LED e buzina
  if (temperatura >= 50.0) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500); // Atualiza a cada meio segundo
}
