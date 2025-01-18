#include <stdio.h>
#include <string.h>
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

void ReceberComando() {
    // Receber o comando 
    if (scanf("%9s", comando) > 0) {  // Limitar a leitura para evitar overflow
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
        } else {
            printf("Comando desconhecido: %s\n", comando);  // Mensagem para comando desconhecido
        }
    }
}

void InicializarPinos() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_put(LED_VERDE, 0);  

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_put(LED_AZUL, 0);  

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_put(LED_VERMELHO, 0);  

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);  
}

void AtivarLedVerde() {
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    printf("Led Verde Aceso\n");
}

void AtivarLedAzul() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 0);
    printf("Led Azul Aceso\n");
}

void AtivarLedVermelho() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 1);
    printf("Led Vermelho Aceso\n");
}

void AtivarLedBranco() {
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 1);
    printf("Led Branco Aceso\n");
}

void DesligarLeds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    printf("Todos os leds Desligados\n");
}

void AtivarBuzzer() {
    // Toca o Buzzer por 2 segundos
    gpio_put(BUZZER, 1);
    printf("Buzzer Ativo por 2 segundos\n"); 
    sleep_ms(2000);        
    gpio_put(BUZZER, 0);   
}