#include <stdio.h>

int main () {

    float salaryCarlos = 1000, salaryJohn = 1000 / 3;
    int month = 0;

    while(salaryJohn <= salaryCarlos) {
        salaryJohn += salaryJohn * 0.05;
        salaryCarlos += salaryCarlos * 0.02;
        month++;
    }

    printf("The number of months that John's salary will equal or exceed Carlos' salary is %d.\n", month);

    return 0;

}