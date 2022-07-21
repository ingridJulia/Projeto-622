// Inclui a biblioteca
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Define o endereço LCD para 0x27 para um display de 16 caracteres e 2 linhas
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Define a entrada analogica do sensor de solo com o valor "0"
#define SENSOR_SOLO A0
// Define que o pino digital do buzzer é o “52”
#define PINO_BUZZER 52

// Recebe a leitura feita no pino analógico
int LeituraSensor;

// Função setup é executada apenas uma vez
void setup()
{
  // Inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600); 
  // Configuração do pino como entrada
  pinMode(PINO_BUZZER, OUTPUT);
  // Configuração do pino como saida
  pinMode(SENSOR_SOLO, INPUT);

  
  }
 
// Função loop é para executar repetidamente o código
void loop()
{

  // inicializa o LCD
  lcd.init();
  //liga a luz de fundo
  lcd.backlight();
  // Posição do cursor
  lcd.setCursor(1, 0);
  
  LeituraSensor = analogRead(SENSOR_SOLO);

//No estado seco
if (LeituraSensor >= 1000) {
digitalWrite (PINO_BUZZER, LOW); 
lcd.print("Status:seco");

//No estado umido
} else {
digitalWrite (PINO_BUZZER, HIGH);
lcd.print("Status:umido");

}
//Aguardar 1000 milissegundos
delay(1000);
}
