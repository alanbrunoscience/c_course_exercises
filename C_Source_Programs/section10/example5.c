#include <stdio.h>

int main() {

    /*   0    1    2    3    4
    * --------------------------
    * |    |    |    |    |    |
    * --------------------------
    */

    int valores[5];

    for(int i = 0; i < 5; i++) {
        printf("Informe o %d/5 valor: ", (i+1));
        scanf("%d", &valores[i]);
    }

    printf("\nOs valores informados foram: \n\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\n", valores[i]);
    }

    printf("\n");
    printf("%p %d\n", &valores[0], valores[0]);
    // Na linguagem C, quando fazemos a declaração de um array, a linguagem C cria um ponteiro na memória, que aponta para a primeira posição do array
    printf("%p %d\n", valores, valores[0]);
    

    return 0;

}