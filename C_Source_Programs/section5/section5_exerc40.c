#include <stdio.h>

int main() {

    int i = 1;
    float num = 0, major, minor;

    printf("Enter the %dº value, please:\n", i);
    scanf("%f", &num);

    if(num < 0) {
        printf("Major: ND\n");
        printf("Minor: ND\n");
    } else {
        major = num;
        minor = num;
        while(num >= 0) {
            printf("Enter the %dº value, please:\n", i);
            scanf("%f", &num);
            i++;
            
            if(num > major) {
                major = num;
            }

            if(num < minor && num >= 0) {
                minor = num;
            }
        }
        printf("Major: %.2f\n", major);
        printf("Minor: %.2f\n", minor);
    }

    return 0;

}