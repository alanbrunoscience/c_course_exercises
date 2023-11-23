#include <stdio.h>

// Functions prototype
void incrementa(int *valor);

int main() {

    // Quando declaramos uma variável, a linguagem C aloca um espaço em memória para colocar este valor
    int contador = 10;
    int *contador_ptr = &contador;

    printf("Antes de incrementar.\n");
    printf("O contador vale %d\n", contador);
    printf("O endereço de memória é %p\n\n", contador_ptr);

    // Cópia por valor
    incrementa(contador_ptr);

    printf("Depois de incrementar.\n");
    printf("O contador vale %d\n", contador);
    printf("O endereço de memória é %p\n\n", contador_ptr);

    return 0;

}

void incrementa(int *valor) {

    printf("Antes de incrementar.\n");
    printf("O contador vale %d\n", *valor);
    printf("O endereço de memória é %p\n\n", valor);

    printf("Depois de incrementar.\n");
    printf("O contador vale %d\n", ++(*valor));
    printf("O endereço de memória é %p\n\n", valor);

}