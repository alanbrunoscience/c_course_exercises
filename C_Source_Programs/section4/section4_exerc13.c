#include <stdio.h>

int main () {

    float g1, g2, g3, wghtAverage;

    printf("Enter the first grade, please:\n");
    scanf("%f", &g1);

    printf("Enter the second grade, please:\n");
    scanf("%f", &g2);

    printf("Enter the third grade, please:\n");
    scanf("%f", &g3);

    wghtAverage = ((g1 * 1) + (g2 * 1) + (g3 * 2)) / 4;

    if (wghtAverage >= 60){
        printf("Approved.\n");
    } else{
        printf("Disapproved.\n");
    }

    return 0;

}