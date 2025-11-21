# 🌱 Sistema de Irrigação Remota via Smartphone

Este projeto apresenta um sistema **teórico** de irrigação remota controlado por smartphone,
utilizando ESP32, relé e bomba de água. O objetivo é demonstrar como a **IoT** pode ser aplicada
na agricultura para otimizar o uso da água e facilitar o controle à distância.

---

## 🚀 Funcionalidades
- Controle remoto da bomba de água via aplicativo (Blynk ou interface web).
- Monitoramento opcional da umidade do solo.
- Possibilidade de automação da rega conforme necessidade.

---

## 🔧 Componentes utilizados
- ESP32 (Wi-Fi integrado)
- Módulo de relé
- Bomba de água / válvula solenoide
- Sensor de umidade do solo (opcional)
- Fonte de energia (tomada ou painel solar)

---

## 📲 Código de exemplo

```cpp
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPLxxxx"
#define BLYNK_AUTH_TOKEN "SEU_TOKEN"

char ssid[] = "SUA_REDE_WIFI";
char pass[] = "SENHA_WIFI";

int relePin = 5;

void setup() {
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V1) {
  int estado = param.asInt();
  digitalWrite(relePin, estado);
}

void loop() {
  Blynk.run();
}

---

## 📊 Fluxograma
O sistema funciona de forma simples: cada vez que o botão é pressionado, o estado da bomba alterna entre ligado e desligado.

![Fluxograma](docs/fluxograma.png)