#include <stdio.h>

int main () {

    int withdraw, count100 = 0, count50 = 0, count20 = 0, count10 = 0, count5 = 0, count2 = 0, count1 = 0;

    printf("Enter the withdraw value ($), please:\n");
    scanf("%d", &withdraw);

    while(withdraw > 0) {
        
        if(withdraw / 100 != 0) {
            count100 = withdraw / 100;
            withdraw -= (count100 * 100);
        }

        if(withdraw / 50 != 0) {
            count50 = withdraw / 50;
            withdraw -= (count50 * 50);
        } 
        
        if(withdraw / 20 != 0) {
            count20 = withdraw / 20;
            withdraw -= (count20 * 20);
        } 
        
        if(withdraw / 10 != 0) {
            count10 = withdraw / 10;
            withdraw -= (count10 * 10);
        } 
        
        if(withdraw / 5 != 0) {
            count5 = withdraw / 5;
            withdraw -= (count5 * 5);
        } 
        
        if(withdraw / 2 != 0) {
            count2 = withdraw / 2;
            withdraw -= (count2 * 2);
        } 
        
        if(withdraw / 1 != 0) {
            count1 = withdraw / 1;
            withdraw -= (count1 * 1);
        }

    }

    printf("\n*** NUMBER OF BANKNOTES ***\n\n");
    printf("-> 100 Dollar Bills: %d;\n", count100);
    printf("-> 50 Dollar Bills: %d;\n", count50);
    printf("-> 20 Dollar Bills: %d;\n", count20);
    printf("-> 10 Dollar Bills: %d;\n", count10);
    printf("-> 5 Dollar Bills: %d;\n", count5);
    printf("-> 2 Dollar Bills: %d;\n", count2);
    printf("-> 1 Dollar Bills: %d.\n", count1);

    return 0;

}