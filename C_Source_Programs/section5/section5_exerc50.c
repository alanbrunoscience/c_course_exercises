#include <stdio.h>

int main() {

    float heightChico = 150, heightZe = 110;
    int years = 1;

    while(heightZe <= heightChico) {
        heightChico += 2;
        heightZe += 3;
        years++;
    }

    printf("The number of years for Zé's height to be greater than Chico's height is %d years.\n", years);

    return 0;

}