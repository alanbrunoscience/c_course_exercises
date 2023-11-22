#include <stdio.h>

// Functions prototype
int dataInput();
void dataOutput(int rowsNumber);

int main() {

    int rowsNumber;

    rowsNumber = dataInput();

    dataOutput(rowsNumber);

    return 0;

}

int dataInput() {

    int rows;

    printf("Enter the rows' number, please: ");
    scanf("%d", &rows);

    return rows;

}

void dataOutput(int rowsNumber) {

    for(int i = 0; i <= rowsNumber; i++) {
        for(int j = 0; j < i; j++) {
            printf("!");
        }
        printf("\n");
    }
    
}