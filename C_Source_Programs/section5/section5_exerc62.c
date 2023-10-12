#include <stdio.h>
#include <string.h>

int main() {

    char *units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *tensI[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tensII[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *hundreds[] = {"", "One hundred", "Two hundred", "Three hundred", "Four hundred", "Five hundred", "Six hundred", "Seven hundred", "Eight hundred", "Nine hundred"};
    char *thousands[] = {"One thousand"};

    int sumDigits = 0;

    for(int num = 1; num <= 1000; num++) {
        if (num > 0 && num < 10) {
            printf("%ld + ", strlen(units[num]));
            sumDigits += strlen(units[num]);
        } else if(num >= 10 && num < 20) {
            printf("%ld + ", strlen(tensI[num - 10]));
            sumDigits += strlen(tensI[num - 10]);
        } else if(num >= 20 && num < 100) {
            if(num % 10 == 0) {
                printf("%ld + ", strlen(tensII[num / 10]));
                sumDigits += strlen(tensII[num / 10]);
            } else {
                printf("%ld + ", (strlen(tensII[num / 10]) + strlen(units[num % 10])));
                sumDigits += (strlen(tensII[num / 10]) + strlen(units[num % 10]));
            }
        } else if(num >= 100 && num < 1000) {
            if(num % 100 == 0){
                printf("%ld + ", (strlen(hundreds[num / 100]) - 1));
                sumDigits += (strlen(hundreds[num / 100]) - 1);
            } else {
                if((num % 100) > 0 && (num % 100) < 10) {
                    printf("%ld + ", (strlen(hundreds[num / 100]) + strlen(units[num % 100]) + 2));
                    sumDigits += (strlen(hundreds[num / 100]) + strlen(units[num % 100] + 2));
                } else if((num % 100) >= 10 && (num % 100) < 20) {
                    printf("%ld + ", (strlen(hundreds[num / 100]) + strlen(tensI[num % 10]) + 2));
                    sumDigits += (strlen(hundreds[num / 100]) + strlen(tensI[num % 10] + 2));
                } else if((num % 100) >= 20 && (num % 100) < 100) {
                    if(num % 10 == 0) {
                        printf("%ld + ", (strlen(hundreds[num / 100]) + strlen(tensII[(num / 10) % 10]) + 2));
                        sumDigits += (strlen(hundreds[num / 100]) + strlen(tensII[(num / 10) % 10] + 2));
                    } else {
                        printf("%ld + ", (strlen(hundreds[num / 100]) + strlen(tensII[(num / 10) % 10]) + strlen(units[num % 10]) + 2));
                        sumDigits += (strlen(hundreds[num / 100]) + strlen(tensII[(num / 10) % 10]) + strlen(units[num % 10]) + 2);
                    }
                }
            }
        } else {
            printf("%ld = ", (strlen(thousands[0]) - 1));
            sumDigits += (strlen(thousands[0]) - 1);
        }
        
    }

    printf("%d\n", sumDigits);

    return 0;

}