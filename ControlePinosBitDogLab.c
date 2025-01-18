#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21

void AtivarLedVerde();
void AtivarLedAzul();
void AtivarLedVermelho();
void AtivarLedBranco();
void DesligarLeds();
void AtivarBuzzer();
void InicializarPinos();
void ReceberComando();

char comando[10];  // Buffer para armazenar comandos

int main() {
    stdio_init_all();
    InicializarPinos();
    
    while (true) {
        ReceberComando();
    }
}
void ReceberComando(){
    // Receber o comando 
    if (scanf("%s", comando) > 0) {
        if (strcmp(comando, "verde") == 0) {
            AtivarLedVerde();
        } else if (strcmp(comando, "azul") == 0) {
            AtivarLedAzul();
        } else if (strcmp(comando, "vermelho") == 0) {
            AtivarLedVermelho();
        } else if (strcmp(comando, "branco") == 0) {
            AtivarLedBranco();
        } else if (strcmp(comando, "desligar") == 0) {
            DesligarLeds();
        } else if (strcmp(comando, "buzzer") == 0) {
            AtivarBuzzer();
        }
    }
}
void InicializarPinos(){
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}
