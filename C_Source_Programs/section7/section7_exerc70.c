#include <stdio.h>
#include <ctype.h>

int main() {

    char array2D[3][3], move, prevMove = '0';
    int size = sizeof(array2D) / sizeof(array2D[0]), countMove = 0, countMoveX = 0, countMoveY = 0, row = 0, column = 0, player = 1, countX, countY;

    // Resetting all positions of the array2D
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            array2D[i][j] = '0';
        }
    }

    // Entering play values
    printf("*** TIC TAC TOE ***\n\n");

    while(countMove < 9) {
        
        printf("*** %dº PLAYER ****\n\n", player);
        printf("%dº move (x or y): ", countMove + 1);
        scanf(" %c", &move);

        move = toupper(move);

        // Validating move
        while(move != 'X' && move != 'Y') {

            printf("\n*** The move made is wrong. The move needs to be x or y. Enter the %dº move again ***\n-> ", countMove + 1);
            scanf(" %c", &move);
            move = toupper(move);

        }

        // Validating which player is making the move
        while(prevMove == move) {
            if(move == 'X') {
                printf("\n'%c' was already played in the last move. The only allowed value is 'y'. Enter this value, please: ", prevMove);
                scanf(" %c", &move);
                move = toupper(move);

                while(move != 'X' && move != 'Y') {
                    printf("\n*** The move made is wrong. The move needs to be x or y. Enter the %dº move again ***\n-> ", countMove + 1);
                    scanf(" %c", &move);
                    move = toupper(move);
                }

            } else {
                printf("\n'%c' was already played in the last move. The only allowed value is 'x'. Enter this value, please: ", prevMove);
                scanf(" %c", &move);
                move = toupper(move);

                while(move != 'X' && move != 'Y') {
                    printf("\n*** The move made is wrong. The move needs to be x or y. Enter the %dº move again ***\n-> ", countMove + 1);
                    scanf(" %c", &move);
                    move = toupper(move);
                }
            }
        }

        // Entering coordinates of move
        printf("\nCoordinate Position:\n\n");
        printf("-> Row: ");
        scanf("%d", &row);
        printf("-> Column: ");
        scanf("%d", &column);

        // Validating if the coordinates is valid and if the position was already filled
        while(row < 0 || row > 2 || column < 0 || column > 2 || array2D[row][column] != '0') {
            
            if(row < 0 || row > 2 || column < 0 || column > 2)  {
                printf("\n*** The range of coordinate position is wrong. The row and column need to be between 0 and 2 (including). Enter the new coordinate position value, please ***\n\n");
                printf("-> Row: ");
                scanf("%d", &row);
                printf("-> Column: ");
                scanf("%d", &column);
            }

            if(array2D[row][column] != '0') {
                printf("\n*** This position is already filled. Enter a new coordinate position, please ***\n\n");
                printf("-> Row: ");
                scanf("%d", &row);
                printf("-> Column: ");
                scanf("%d", &column);
            }

        }

        array2D[row][column] = move;

        prevMove = move;

        //=========================================================================

        // Checking if any player won the game
        if(countMoveX >= 2 || countMoveY >= 2) {

            // Scrolling through the rows of the matrix
            for(int i = 0; i < size; i++) {
                countX = 0;
                countY = 0;
                for(int j = 0; j < size; j++) {
                    if(array2D[i][j] == 'X') {
                        countX++;
                    } else if(array2D[i][j] == 'Y') {
                        countY++;
                    }
                }

                if(countX == 3) {
                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);

                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;

                } else if(countY == 3) {
                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);

                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;
                }
            }

            // Scrolling through the columns of the matrix
            for(int i = 0; i < size; i++) {
                countX = 0;
                countY = 0;
                for(int j = 0; j < size; j++) {
                    if(array2D[j][i] == 'X') {
                        countX++;
                    } else if(array2D[j][i] == 'Y') {
                        countY++;
                    }
                }

                if(countX == 3) {
                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);

                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;

                } else if(countY == 3) {
                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);

                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;
                }

            }

            // Scrolling through the main diagonal of the matrix

            int countXMD = 0;
            int countYMD = 0;

            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    if(i == j) {
                        if(array2D[i][j] == 'X') {
                            countXMD++;
                        } else if(array2D[i][j] == 'Y') {
                            countYMD++;
                        }
                    }
                }

                if(countXMD == 3) {

                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);
                    
                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;

                } else if(countYMD == 3) {

                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);

                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;

                }

            }

            // Scrolling through the secondary diagonal of the matrix

            int countXSD = 0;
            int countYSD = 0;

            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    if((i + j) == (size - 1)) {
                        if(array2D[i][j] == 'X') {
                            countXSD++;
                        } else if(array2D[i][j] == 'Y') {
                            countYSD++;
                        }
                    }
                }

                if(countXSD == 3) {

                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);
                    
                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;

                } else if(countYSD == 3) {

                    printf("\n*** The %dº player won the game. Congratulations! ***\n", player);

                    printf("\n=========\n\n");

                    for(int i = 0; i < size; i++) {
                        for(int j = 0; j < size; j++) {
                            printf(" %c ", array2D[i][j]);
                        }
                        printf("\n");
                    } 

                    printf("\n=========\n\n");

                    return 0;

                }

            }

        }

        // Data output 
        printf("\n=========\n\n");

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                printf(" %c ", array2D[i][j]);
            }
            printf("\n");
        } 

        printf("\n=========\n\n");

        //=========================================================================

        countMove++;

        if(move == 'X') {
            countMoveX++;
        } else {
            countMoveY++;
        }

        if(player == 1) {
            player++;
        } else {
            player--;
        }
        
    }

    return 0;

}