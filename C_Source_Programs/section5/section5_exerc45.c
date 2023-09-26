#include <stdio.h>

int main() {

    int option;
    float kmh, mps;

    do {
        printf("*** CONVERTER (KM/H <-> M/S) ***\n\n");
        printf("Choose an option, please:\n\n1 - Convert Km/h to m/s;\n2 - Convert m/s to Km/h;\n3 - Exit.\n\n-> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the value in Km/h, please:\n");
            scanf("%f", &kmh);
            printf("\n%.2f km/h = %.2f m/s.\n\n", kmh, (kmh / 3.6));
            printf("================================\n\n");
            break;
        case 2:
            printf("\nEnter the value in m/s, please:\n");
            scanf("%f", &mps);
            printf("\n%.2f m/s = %.2f km/h.\n\n", mps, (mps * 3.6));
            printf("================================\n\n");
            break;
        default:
            printf("Finishing the program...\n");
            break;
        }

    } while (option != 3);

    return 0;

}