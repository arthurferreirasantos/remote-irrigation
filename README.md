# 🌱 Sistema de Irrigação Remota (Simulação com Botão Toggle)

Este projeto demonstra um sistema de irrigação remota utilizando **ESP32** e simulação no **Wokwi**.  
O LED representa o relé/bomba e o botão físico simula o comando remoto.  
Cada clique no botão alterna o estado da bomba entre **ligado** e **desligado**.

---

## 📂 Estrutura do Repositório
remote-irrigation/ 
├── src/ 
│ └── irrigation.ino # Código principal (versão toggle com botão) 
├── docs/ 
│ ├── esquema.png # Esquema elétrico do circuito 
│ └── fluxograma.png # Fluxograma do funcionamento 
└── README.md # Documentação principal

---

## 🖥️ Simulação
Este projeto foi desenvolvido de forma teórica e testado em simuladores online.

- [Simulação no Wokwi](https://wokwi.com/projects/448263757206533121)

---

## 🔧 Circuito
- **LED (simula bomba/relé):**
  - Anodo (+) → GPIO 5 do ESP32  
  - Catodo (–) → GND, com resistor de 220Ω em série  

- **Botão:**
  - Um terminal → GPIO 4 do ESP32  
  - Outro terminal → GND do ESP32  

---

## 💻 Código (irrigation.ino)

```cpp
// Sistema de Irrigação Remota - Versão Toggle com Botão
// LED representa o relé/bomba
// Cada clique no botão alterna o estado da bomba

int relePin  = 5;   // GPIO 5 -> LED (representa bomba/relé)
int botaoPin = 4;   // GPIO 4 -> Pushbutton

bool estadoBomba = false;   // Estado inicial: desligada
bool ultimoEstadoBotao = HIGH; // Botão não pressionado

void setup() {
  pinMode(relePin, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP);  // Usa resistor interno
  digitalWrite(relePin, LOW);       // Bomba desligada inicialmente
}

void loop() {
  int leituraBotao = digitalRead(botaoPin);

  // Detecta transição: botão foi pressionado (de HIGH para LOW)
  if (leituraBotao == LOW && ultimoEstadoBotao == HIGH) {
    estadoBomba = !estadoBomba; // Alterna estado
    digitalWrite(relePin, estadoBomba ? HIGH : LOW);
    delay(200); // Pequeno atraso para evitar múltiplos cliques (debounce)
  }

  ultimoEstadoBotao = leituraBotao;
}

---

## 📊 Fluxograma
O sistema funciona de forma simples: cada vez que o botão é pressionado, o estado da bomba alterna entre ligado e desligado.