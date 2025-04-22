const int ledPin = 9;        // LED conectado ao pino PWM 9
const int micPin = A0;       // Microfone no pino analógico A0

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);        // Para depuração (opcional)
}

void loop() {
  // Lê o valor analógico do microfone (0 a 1023)
  int som = analogRead(micPin);

  // Mapeia o volume para o intervalo de brilho do LED (0 a 255)
  int brilhoMax = map(som, 0, 1023, 50, 255); // evita brilho muito fraco

  // Mostra o valor lido no monitor serial (opcional)
  Serial.println(som);

  // Fade in: aumenta o brilho de 0 até brilhoMax
  for (int brilho = 0; brilho <= brilhoMax; brilho++) {
    analogWrite(ledPin, brilho);
    delay(10);
  }

  // Fade out: reduz o brilho de brilhoMax até 0
  for (int brilho = brilhoMax; brilho >= 0; brilho--) {
    analogWrite(ledPin, brilho);
    delay(10);
  }

  delay(500); // pequena pausa antes do próximo ciclo
}
