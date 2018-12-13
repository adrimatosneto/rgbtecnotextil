// Monitor de temperatura interna do CIT (local dos servidores).
// Quando a temperatura estiver maior que 22º o LED RGB ficará vermelho, assim alertando de forma visual a temperatura interna da sala
// Quando a temperatura for menor que 23º o LED RGB ficará azul demonstrando que a temperatura está satisfatória.

#include <DHT.h>
#include <DHT_U.h>

uint32_t delayMS;

#define DHTPIN            2 
#define DHTTYPE           DHT22

#define PINODHT 2     // qual pino usaremos para comunicação com DHT
#define TIPODHT DHT22   // qual DHT vamos usar. Nocaso, um DHT22(AM2302/ AM2321)
 
DHT dht(PINODHT, TIPODHT);    // configuraçãoes do DHT

#define RED 3 // Define o pino 3 com PWM como RED
#define BLUE 5 // Define o pino 5 com PWM como BLUE
#define GREEN 6 // Define o pino 6 com PWM como GREEN

int red = 255, green = 255, blue = 255; // valores de 0 a 255 (variá-los para obter cores diferentes).
 
// ------------- Inicialização de DHT e os LEDS ---------------------------//
 
void setup() {
  
//Inicializa o DHT
  dht.begin();
  
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}
 
// ------------------- Lê e mostra informações -------------------- //
 
void loop() {
  //analogWrite (RED, red); // Envia o sinal de "red" para o terminal de cor vermelha do LED
 
  // Ler a temperatura ou humidade leva cerca de 250 milisegundos!
  int h = dht.readHumidity();
  // Lê a temperatura em Celsius (padrão)
  int t = dht.readTemperature();

  Serial.print("Umidade = ");
  Serial.print(h);
  Serial.print("% ");

  Serial.print("Temperatura = ");
  Serial.print(t);
  Serial.print("º ");

  digitalWrite (BLUE, HIGH);
  digitalWrite (GREEN, LOW);
  digitalWrite (RED, LOW);
 
  // Analise de temperatura.
  if (t > 22) {
    digitalWrite (RED, HIGH); // Envia o sinal de "red" para o terminal de cor vermelha do LED
    digitalWrite (BLUE, LOW); // Desliga o azul
    digitalWrite (GREEN, LOW); // Desliga o verde
    Serial.println("VERMELHO = QUENTE");
  }
  if (t < 10){ // Caso o cabo de dados desligue.
    digitalWrite (RED, HIGH); // Envia o sinal de "red" para o terminal de cor vermelha do LED
    digitalWrite (BLUE, LOW); // Desliga o azul
    digitalWrite (GREEN, LOW); // Desliga o verde
    Serial.println("CABO DESLIGADO!");
  }

  delay (5000);
  }

  
