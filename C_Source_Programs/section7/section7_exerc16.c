#include <stdio.h>
#include <unistd.h>

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

int main() {
    float numbers[5];
    int option, size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº real number (numbers[%d]), please: ", (i+1), i);
        scanf("%f", &numbers[i]);
    }

    do {
        clearScreen(); // Clear the screen and reset cursor position

        printf("*** OPTIONS ***\n\n");
        printf("1 - Show the array elements in direct order;\n");
        printf("2 - Show the array elements in reverse order;\n");
        printf("3 - Rewrite the elements of the array;\n");
        printf("4 - Exit the program.\n\n-> ");
        scanf("%d", &option);
        
        getchar(); // Consume the trailing newline character

        switch(option) {
            case 1:
                clearScreen(); // Clear the screen and reset cursor position

                printf("|");

                for(int i = 0; i < size; i++) {
                    printf(" %.2f |", numbers[i]);
                }

                fflush(stdout); // Flush the output buffer

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 2:
                clearScreen(); // Clear the screen and reset cursor position

                printf("|");

                for(int i = size - 1; i >= 0; i--) {
                    printf(" %.2f |", numbers[i]);
                }

                fflush(stdout); // Flush the output buffer

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 3:
                clearScreen(); // Clear the screen and reset cursor position

                for(int i = 0; i < size; i++) {
                    printf("Enter the %dº real number (numbers[%d]), please: ", (i+1), i);
                    scanf("%f", &numbers[i]);
                }

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 4:
                clearScreen(); // Clear the screen and reset cursor position

                printf("Finishing the program...\n");

                break;

            default:
                clearScreen(); // Clear the screen and reset cursor position

                printf("You chose an invalid option! Choose an option between 1 and 4, please.\n");

                sleep(3); // Sleep for a shorter time

                break;
        }

    } while (option != 4);

    return 0;
}