// Projeto Teórico: Sistema de Irrigação Remota via Smartphone
// Autor: Arthur
// Objetivo: Controlar uma bomba de irrigação remotamente usando ESP32 e aplicativo Blynk

#define BLYNK_TEMPLATE_ID "TMPLxxxx"   // Substitua pelo seu Template ID do Blynk
#define BLYNK_DEVICE_NAME "IrrigacaoRemota"
#define BLYNK_AUTH_TOKEN "SEU_TOKEN"   // Substitua pelo token gerado no app Blynk

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Configuração da rede Wi-Fi
char ssid[] = "SUA_REDE_WIFI";   // Nome da rede Wi-Fi
char pass[] = "SENHA_WIFI";      // Senha da rede Wi-Fi

// Pino do relé (simulando a bomba de água)
int relePin = 5;

void setup() {
  // Configura o pino do relé como saída
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW); // Inicialmente desligado

  // Conecta ao Wi-Fi e ao servidor Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V1) {
  // Recebe o comando do aplicativo (botão virtual V1)
  int estado = param.asInt();
  digitalWrite(relePin, estado); // Liga ou desliga o relé
}

void loop() {
  // Mantém a conexão com o Blynk ativa
  Blynk.run();
}