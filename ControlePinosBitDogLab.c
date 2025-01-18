#include <stdio.h>
#include "pico/stdlib.h"

void AtivarLedVerde();
void AtivarLedAzul();
void AtivarLedVermelho();
void AtivarLedBranco();
void DesligarLeds();
void AtivarBuzzer();
void ReceberComando();

char comando[10];  // Buffer para armazenar comandos

int main() {
    stdio_init_all();
    InicializarPinos();
    
    while (true) {
        ReceberComando();
    }
}


