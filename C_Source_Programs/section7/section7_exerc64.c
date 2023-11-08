#include <stdio.h>
#include <unistd.h>

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

int main() {

    int option, array2DA[2][2] = {0}, array2DB[2][2] = {0}, array2DC[2][2] = {0}, array2DA1[2][2] = {0}, array2DB1[2][2] = {0}, size = sizeof(array2DA) / sizeof(array2DA[0]), k;

    do {

        clearScreen(); // Clear the screen and reset cursor position

        printf("*** MENU ***\n\n");
        printf("Choose one of the options below:\n\n");
        printf("1) Read the two two-dimensional arrays;\n");
        printf("2) Sum arrays A and B (A + B);\n");
        printf("3) Subtract arrays A and B (A - B);\n");
        printf("4) Add a constant to both arrays A and B;\n");
        printf("5) Print all the arrays (original and modified arrays);\n");
        printf("6) Exit.\n\n-> ");
        scanf("%d", &option);

        getchar(); // Consume the trailing newline character
    
        switch(option) {
            case 1:

                clearScreen(); // Clear the screen and reset cursor position

                printf("*** TWO-DIMENSIONAL ARRAY A ***\n\n");
                printf("Fill in the elements' value in each position below:\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        printf("array2DA[%d][%d]: ", i, j);
                        scanf("%d", &array2DA[i][j]);
                        array2DA1[i][j] = array2DA[i][j];
                    }
                }

                fflush(stdout); // Flush the output buffer

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key

                clearScreen(); // Clear the screen and reset cursor position

                printf("*** TWO-DIMENSIONAL ARRAY B ***\n\n");
                printf("Fill in the elements' value in each position below:\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        printf("array2DB[%d][%d]: ", i, j);
                        scanf("%d", &array2DB[i][j]);
                        array2DB1[i][j] = array2DB[i][j];
                    }
                }

                fflush(stdout); // Flush the output buffer

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 2:

                clearScreen();
                
                printf("*** A + B ***\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        array2DC[i][j] = array2DA[i][j] + array2DB[i][j];
                        printf("%d ", array2DC[i][j]);
                    }
                    printf("\n");
                }
                                
                fflush(stdout); // Flush the output buffer

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 3:

                clearScreen(); // Clear the screen and reset cursor position

                printf("*** A - B ***\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        array2DC[i][j] = array2DA[i][j] - array2DB[i][j];
                        printf("%d ", array2DC[i][j]);
                    }
                    printf("\n");
                }

                fflush(stdout); // Flush the output buffer
                                
                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 4:

                clearScreen(); // Clear the screen and reset cursor position

                printf("*** ADD A CONSTANT TO BOTH ARRAYS ***\n\n");

                printf("Enter the value of the constant to be added in both arrays, please: ");
                scanf("%d", &k);

                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        array2DA[i][j] += k;
                    }
                }

                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        array2DB[i][j] += k;
                    }
                }

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 5:

                clearScreen(); // Clear the screen and reset cursor position

                printf("*** ARRAY 2D A (ORIGINAL) ***\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        printf("%d ", array2DA1[i][j]);
                    }
                    printf("\n");
                }

                fflush(stdout); // Flush the output buffer
                
                printf("\n*** ARRAY 2D B (ORIGINAL) ***\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        printf("%d ", array2DB1[i][j]);
                    }
                    printf("\n");
                }

                fflush(stdout); // Flush the output buffer

                printf("\n*** ARRAY 2D A (MODIFIED WITH THE ADD OR NOT OF THE CONSTANT) ***\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        printf("%d ", array2DA[i][j]);
                    }
                    printf("\n");
                }

                fflush(stdout); // Flush the output buffer
                
                printf("\n*** ARRAY 2D B (MODIFIED WITH THE ADD OR NOT OF THE CONSTANT) ***\n\n");
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        printf("%d ", array2DB[i][j]);
                    }
                    printf("\n");
                }

                fflush(stdout); // Flush the output buffer

                printf("\nPress Enter to continue...");
                while(getchar() != '\n'); // Wait for Enter key
                break;

            case 6:
                
                clearScreen(); // Clear the screen and reset cursor position

                printf("Finishing the program...\n");

                break;

            default:

                clearScreen(); // Clear the screen and reset cursor position

                printf("Invalid Option! Choose an option between 1 to 6...\n");

                sleep(3); // Sleep for a shorter time
                
                break;
        }
        
    } while(option != 6);

    return 0;

}