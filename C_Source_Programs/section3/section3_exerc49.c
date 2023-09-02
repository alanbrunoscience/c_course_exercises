#include <stdio.h>

int main() {

    // Variables declaration
    int hourInit, minInit, secInit, totSec, hoursDur, minDur, secsDur;
    int hourFin = 0, minFin = 0, secFin;

    // Data Input
    do {
        printf("=== CURRENT TIME ===\n");
        printf("=> Initial Hour: ");
        scanf("%d", &hourInit);
        printf("=> Initial Minute: ");
        scanf("%d", &minInit);
        printf("=> Initial Second: ");
        scanf("%d", &secInit);

        if(hourInit < 0 || hourInit > 23 || minInit < 0 || minInit > 59 || secInit < 0 || secInit > 59) {
            printf("\n*** This is not a valid entry. The hour needs to be between 0 and 23, the minutes need to be between 0 and 59, and the seconds need to be between 0 and 59. ***\n\n");
        }

    } while (hourInit < 0 || hourInit > 23 || minInit < 0 || minInit > 59 || secInit < 0 || secInit > 59);

    printf("\n");

    printf("=== DURATION ===\n");
    printf("=> Number of seconds: ");
    scanf("%d", &secsDur);

    // Transforming the total number of seconds in hour, minutes, and seconds
    if(secsDur >= 3600) {
        hoursDur = secsDur / 3600;
        secsDur %= 3600;

        if(secsDur >= 60) {
            minDur = secsDur  / 60;
            secsDur %= 60;
        }

    } else {
        if(secsDur >= 60) {
            minDur = secsDur  / 60;
            secsDur %= 60;
        }
    }

    // Calculating the equivalent time duration
    if(hoursDur > 24) {
        hoursDur %= 24;
    }

    // Calculating the experience end time
    secFin = secInit + secsDur;

    if (secFin > 59) {
        secFin -= 60;
        minFin = 1;
    }

    minFin += (minInit + minDur);

    if (minFin > 59) {
        minFin -= 60;
        hourFin = 1;
    }

    hourFin += (hourInit + hoursDur);

    if (hourFin <= 23) {
        printf("\n");
        printf("=== END TIME ===\n");
        printf("=> %d:%d:%d\n", hourFin, minFin, secFin);
    } else {
        hourFin -= 24;

        if(hourFin == 24) {
            printf("\n");
            printf("=== END TIME ===\n");
            printf("=> 00:%d:%d\n", minFin, secFin);
        } else {
            printf("\n");
            printf("=== END TIME ===\n");
            printf("=> %d:%d:%d\n", hourFin, minFin, secFin);
        }
    }

    return 0;

}