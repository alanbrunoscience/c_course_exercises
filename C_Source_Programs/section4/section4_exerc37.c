#include <stdio.h>

int main() {

    int hoursEntry, minutesEntry, hoursExit, minutesExit, totalHours, totalMinutes;
    float price = 0;

    do {

        printf("Enter two integer numbers separated by a space to represent hours and minutes (e.g. 12 50) of entry, respectively:\n");
        if (scanf("%d %d", &hoursEntry, &minutesEntry) != 2) {
            printf("Invalid input format!\n");
            return 1;
        }

        printf("Enter two integer numbers separated by a space to represent hours and minutes (e.g. 12 50) of exit, respectively:\n");
        if (scanf("%d %d", &hoursExit, &minutesExit) != 2) {
            printf("Invalid input format!\n");
            return 1;
        }

        if(hoursEntry < 0 || hoursEntry > 23 || hoursExit < 0 || hoursExit > 23 || minutesEntry < 0 || minutesEntry > 59 || minutesExit < 0 || minutesExit > 59){
            printf("\n*** Invalid hours or minutes format. The hours need to be greater or equal to 0 and smaller than 24 (not included), and the minutes greater or equal to 0 and smaller than 60 (not included). Enter the correct format again ***\n\n");
        }
        
    } while(hoursEntry < 0 || hoursEntry > 23 || hoursExit < 0 || hoursExit > 23 || minutesEntry < 0 || minutesEntry > 59 || minutesExit < 0 || minutesExit > 59);

    if(hoursExit < hoursEntry) {
        
        if(minutesEntry > 0) {
            totalHours = (24 - hoursEntry - 1) + hoursExit;
            totalMinutes = (60 - minutesEntry) + minutesExit;

            if(totalMinutes >= 60) {
                totalHours += 1;
                totalMinutes -= 60;
            }

        } else {
            totalHours = (24 - hoursEntry) + hoursExit;
            totalMinutes = minutesExit;
        }

    } else if (hoursEntry == hoursExit) {

        if(minutesExit < minutesEntry) {
            if(minutesEntry > 0) {
                totalHours = (24 - hoursEntry - 1) + hoursExit;
                totalMinutes = (60 - minutesEntry) + minutesExit;

                if(totalMinutes >= 60) {
                    totalHours += 1;
                    totalMinutes -= 60;
                }
            } else {
                totalHours = (24 - hoursEntry) + hoursExit;
                totalMinutes = minutesExit;
            }

        } else {
            totalHours = 0;
            totalMinutes = minutesExit - minutesEntry;
        }

    } else {

        totalHours = hoursExit - hoursEntry;

        if(minutesEntry > 0) {
            totalHours = hoursExit - hoursEntry - 1;
            totalMinutes = (60 - minutesEntry) + minutesExit;

            if(totalMinutes >= 60) {
                totalHours += 1;
                totalMinutes -= 60;
            }

        } else {
            totalHours = hoursExit - hoursEntry;
            totalMinutes = minutesExit;
        }

    }

    for(int i = totalHours; i >= 0; i--){

        if (i >= 5) {
            price += 2;
        } else if (i >= 3) {
            price += 1.4;
        } else if (i >= 1) {
            price += 1.0;
        }

    }

    if(totalHours == 0) {
        price = 1.0;
    }

    if(totalHours >= 5 && totalMinutes > 0) {
        price += 2.0;
    } else if(totalHours >= 3 && totalHours < 5 && totalMinutes > 0) {
        price += 1.4;
    } else if(totalHours >= 1 && totalHours < 3 && totalMinutes > 0) {
        price += 1.0;
    }

    printf("DURATION: %d h %d min 00 sec\n", totalHours, totalMinutes);
    printf("PRICE: $ %.2f\n", price);

    return 0;

}
