#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int population, i = 0;
    double pricekWh, gCons = 0, lowCons = 0, sumConsumptions1 = 0, sumConsumptions2 = 0, sumConsumptions3 = 0, averageConsumption = 0;

    struct consumerData { // Data type
        double kWhMCons;
        int consumerCode;
    }; // Struct definition

    struct consumerData consumer; // Declaration of the "consumer" variable which is the "consumerData" struct type

    printf("Enter the population number, please:\n");
    scanf("%d", &population);

    printf("Enter the kWh price ($), please:\n");
    scanf("%lf", &pricekWh);

    system("clear");

    printf("Inform the monthly consumption for the %dº consumer, please:\n", (i+1));
    scanf("%lf", &consumer.kWhMCons);

    printf("Enter the consumer code (1 - Residential, 2 - Comercial, 3 - Industrial) for the %dº consumer, please:\n", (i+1));
    scanf("%d", &consumer.consumerCode);

    while(consumer.consumerCode < 1 || consumer.consumerCode > 3){
        printf("The consumer code needs to be equal to or greater than 1, and equal to or smaller than 3. Enter a new consumer code for the %dº consumer, please:\n", (i+1));
        scanf("%d", &consumer.consumerCode);
    }

    if(consumer.consumerCode == 1) {
        sumConsumptions1 += consumer.kWhMCons;
    } else if(consumer.consumerCode == 2) {
        sumConsumptions2 += consumer.kWhMCons;
    } else {
        sumConsumptions3 += consumer.kWhMCons;
    }

    gCons = consumer.kWhMCons;
    lowCons = consumer.kWhMCons;

    for(i = 1; i < population; i++) {

        system("clear");

        printf("Inform the monthly consumption for the %dº consumer, please:\n", (i+1));
        scanf("%lf", &consumer.kWhMCons);

        printf("Enter the consumer code (1 - Residential, 2 - Comercial, 3 - Industrial) for the %dº consumer, please:\n", (i+1));
        scanf("%d", &consumer.consumerCode);

        while(consumer.consumerCode < 1 || consumer.consumerCode > 3){
            printf("The consumer code needs to be equal to or greater than 1, and equal to or smaller than 3. Enter a new consumer code for the %dº consumer, please:\n", (i+1));
            scanf("%d", &consumer.consumerCode);
        }

        if(gCons < consumer.kWhMCons) {
            gCons = consumer.kWhMCons;
        }

        if(lowCons > consumer.kWhMCons) {
            lowCons = consumer.kWhMCons;
        }

        if(consumer.consumerCode == 1) {
            sumConsumptions1 += consumer.kWhMCons;
        } else if(consumer.consumerCode == 2) {
            sumConsumptions2 += consumer.kWhMCons;
        } else {
            sumConsumptions3 += consumer.kWhMCons;
        }

    }

    averageConsumption = (double) (sumConsumptions1 + sumConsumptions2 + sumConsumptions3) / (double) population;
    
    system("clear");

    printf("*** FINAL RESULTS ***\n\n");
    printf("-> Total population: %d;\n", population);
    printf("-> KWh price ($): %.2lf;\n", pricekWh);
    printf("-> The greatest consumption was %.2lf ($ %.2lf);\n", gCons, (gCons * pricekWh));
    printf("-> The smallest consumption was %.2lf ($ %.2lf);\n", lowCons, (lowCons * pricekWh));
    printf("-> The population's average consumption was %.2lf ($ %.2lf);\n", averageConsumption, (averageConsumption * pricekWh));
    printf("-> Total consumption of the category 1 (Residential): %.2lf ($ %.2lf);\n", sumConsumptions1, (sumConsumptions1 * pricekWh));
    printf("-> Total consumption of the category 2 (Comercial): %.2lf ($ %.2lf);\n", sumConsumptions2, (sumConsumptions2 * pricekWh));
    printf("-> Total consumption of the category 3 (Industrial): %.2lf ($ %.2lf).\n", sumConsumptions3, (sumConsumptions3 * pricekWh));

    return 0;

}