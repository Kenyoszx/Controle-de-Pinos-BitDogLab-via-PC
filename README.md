# Controle-de-Pinos-BitDogLab-via-PC

Este projeto permite o controle de LEDs e um buzzer da placa educacional BitDogLab 6.4 ou utilizando um microcontrolador Raspberry Pi Pico com 3 leds e 1 buzzer. O usuário pode enviar comandos via terminal para ativar diferentes LEDs ou o buzzer.

## Funcionalidade

### Componentes

- **LEDs**: Três LEDs (verde, azul e vermelho) que podem ser ativados individualmente ou em conjunto.
- **Buzzer**: Um buzzer que pode ser acionado por um comando específico.

### Comandos Aceitos

O sistema aceita os seguintes comandos:

- `verde`: Ativa o LED verde.
- `azul`: Ativa o LED azul.
- `vermelho`: Ativa o LED vermelho.
- `branco`: Ativa todos os LEDs (verde, azul e vermelho).
- `desligar`: Desliga todos os LEDs.
- `buzzer`: Aciona o buzzer por 2 segundos.
- `bootsel`: Reseta a placa para o modo bootsel

### Estrutura do Código

- **Funções Principais**:
  - `InicializarPinos()`: Configura os pinos do microcontrolador para os LEDs e o buzzer.
  - `ReceberComando()`: Lê os comandos do usuário e chama a função correspondente para ativar o LED ou o buzzer.
  - `AtivarLedVerde()`, `AtivarLedAzul()`, `AtivarLedVermelho()`, `AtivarLedBranco()`: Funções para ativar os LEDs correspondentes.
  - `DesligarLeds()`: Desliga todos os LEDs.
  - `AtivarBuzzer()`: Aciona o buzzer por 2 segundos.
  - `ModoBootsel()`: Reseta a placa para o modo bootsel

### Requisitos

- BitDogLab 6.4 <br/>
   **ou**
- Raspberry Pi Pico RP2040
- LEDs (verde, azul, vermelho)
- Buzzer
- Resistores
- Fios de conexão

### Conexões

- **Pinos dos LEDs**:
  - LED Verde: `LED_VERDE` (pino 11)
  - LED Azul: `LED_AZUL` (pino 12)
  - LED Vermelho: `LED_VERMELHO` (pino 13)

- **Pino do Buzzer**:
  - Buzzer: `BUZZER` (pino 21)

### Compilação e Execução

1. Certifique-se de que o ambiente de desenvolvimento do Raspberry Pi Pico está configurado.
2. Compile o código usando o CMake.
3. Carregue o código no Raspberry Pi Pico.
4. Conecte os componentes conforme descrito nas conexões.
5. Execute o código e envie comandos via terminal para controlar os LEDs e o buzzer.

### Mensagens de Status

O programa imprime mensagens no console para indicar qual LED foi ativado ou se o buzzer está ativo. Isso ajuda a monitorar a operação do sistema.

### Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir um problema ou enviar um pull request.
