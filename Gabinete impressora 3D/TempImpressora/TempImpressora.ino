#include "DHT.h"

#define DHTPIN 2     // Pino onde o sensor DHT11 está conectado
#define DHTTYPE DHT11   // Define o tipo do sensor como DHT11
#define Potpin 0

// Inicializa o objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// Define os pinos para os LEDs
const int ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLeds = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste do sensor DHT11!");
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  dht.begin();

  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  delay(1500);
  // Aguarda alguns segundos entre as medições
  // A leitura da temperatura ou umidade leva cerca de 250 milissegundos
  // A leitura do sensor pode demorar até 2 segundos (é um sensor lento)
  float t = dht.readTemperature();

  // Verifica se a leitura falhou e sai da função para tentar novamente
  if (isnan(t)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  // Lógica para acender os LEDs de acordo com a temperatura
  // Desliga todos os LEDs antes de acender os corretos
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);

  if (t >= 2 && t < 20) {
    digitalWrite(ledPins[0], HIGH);
  } else if (t >= 20 && t < 25) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
  } else if (t >= 25 && t < 30) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
  } else if (t >= 30 && t < 35) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
  } else if (t >= 35 && t < 40) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
    digitalWrite(ledPins[4], HIGH);
  } else if (t >= 40) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
    digitalWrite(ledPins[4], HIGH);
    digitalWrite(A4, HIGH);
  }
   
  
  int LeituraPot = analogRead(Potpin);
  Serial.print("LeituraPot:");
  Serial.println(LeituraPot);
  int alvoTemp = map(LeituraPot, 0, 1025, 20, 50);
  Serial.print("Temperatura alvo:");
  Serial.println(alvoTemp);

  if (alvoTemp >= 20 && alvoTemp < 25) {
    digitalWrite(ledPins[5], HIGH);
  } else if (alvoTemp >= 25 && alvoTemp < 30) {
    digitalWrite(ledPins[5], HIGH);
    digitalWrite(ledPins[6], HIGH);
  } else if (alvoTemp >= 30 && alvoTemp < 35) {
    digitalWrite(ledPins[5], HIGH);
    digitalWrite(ledPins[6], HIGH);
    digitalWrite(ledPins[7], HIGH);
  } else if (alvoTemp >= 35 && alvoTemp < 40) {
    digitalWrite(ledPins[5], HIGH);
    digitalWrite(ledPins[6], HIGH);
    digitalWrite(ledPins[7], HIGH);
    digitalWrite(ledPins[8], HIGH);
  } else if (alvoTemp >= 40 && alvoTemp < 45) {
    digitalWrite(ledPins[5], HIGH);
    digitalWrite(ledPins[6], HIGH);
    digitalWrite(ledPins[7], HIGH);
    digitalWrite(ledPins[8], HIGH);
    digitalWrite(ledPins[9], HIGH);
  } else if (alvoTemp >= 45) {
    digitalWrite(ledPins[5], HIGH);
    digitalWrite(ledPins[6], HIGH);
    digitalWrite(ledPins[7], HIGH);
    digitalWrite(ledPins[8], HIGH);
    digitalWrite(ledPins[9], HIGH);
    digitalWrite(A5, HIGH);
  }
}