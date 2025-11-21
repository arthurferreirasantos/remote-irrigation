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