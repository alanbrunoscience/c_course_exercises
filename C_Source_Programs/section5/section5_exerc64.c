#include <stdio.h>

int main() {

    char *units[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *tensI[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tensII[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *hundreds[] = {"", "One hundred", "Two hundred", "Three hundred", "Four hundred", "Five hundred", "Six hundred", "Seven hundred", "Eight hundred", "Nine hundred"};
    char *thousands[] = {"One thousand"};

    int num;

    printf("Enter a number between 0 and 1000:\n");
    scanf("%d", &num);

    while(num < 0 || num > 1000) {
        printf("\n*** The number entered in not valid. Enter a new number between 0 and 1000, please ***\n-> ");
        scanf("%d", &num);
    }

    if(num == 0) {
        printf("%d = %s\n", num, units[num]);
    } else if(num > 0 && num < 10) {
        printf("%d = %s\n", num, units[num]);
    } else if(num >= 10 && num < 20) {
        printf("%d = %s\n", num, tensI[num - 10]);
    } else if(num >= 20 && num < 100) {
        if(num % 10 == 0) {
            printf("%d = %s\n", num, tensII[num / 10]);
        } else {
            printf("%d = %s-%s\n", num, tensII[num / 10], units[num % 10]);
        }    
    } else if(num >= 100 && num < 1000) {
        if(num % 100 == 0){
            printf("%d = %s\n", num, hundreds[num / 100]);
        } else {
            if((num % 100) > 0 && (num % 100) < 10) {
                printf("%d = %s and %s\n", num, hundreds[num / 100], units[num % 100]);
            } else if((num % 100) >= 10 && (num % 100) < 20) {
                printf("%d = %s and %s\n", num, hundreds[num / 100], tensI[num % 10]);
            } else if((num % 100) >= 20 && (num % 100) < 100) {
                if(num % 10 == 0) {
                    printf("%d = %s and %s\n", num, hundreds[num / 100], tensII[(num / 10) % 10]);
                } else {
                    printf("%d = %s and %s-%s\n", num, hundreds[num / 100], tensII[(num / 10) % 10], units[num % 10]);
                }
            }
        }
    } else {
        printf("%d = %s\n", num, thousands[0]);
    }

    return 0;

}