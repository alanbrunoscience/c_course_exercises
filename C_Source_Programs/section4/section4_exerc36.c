#include <stdio.h>

int main(){

    float valueSale;
    
    printf("Enter the value sale, please:\n");
    scanf("%f", &valueSale);

    if(valueSale >= 100000){
        printf("The comission is $ %.2f\n", (700 + (valueSale * 0.16)));
    } else if(valueSale >= 80000 && valueSale < 100000) {
        printf("The comission is $ %.2f\n", (650 + (valueSale * 0.14)));
    } else if(valueSale >= 60000 && valueSale < 80000) {
        printf("The comission is $ %.2f\n", (600 + (valueSale * 0.14)));
    } else if(valueSale >= 40000 && valueSale < 60000) {
        printf("The comission is $ %.2f\n", (550 + (valueSale * 0.14)));
    } else if(valueSale >= 20000 && valueSale < 40000) {
        printf("The comission is $ %.2f\n", (500 + (valueSale * 0.14)));
    } else {
        printf("The comission is $ %.2f\n", (400 + (valueSale * 0.14)));
    }

    return 0;

}