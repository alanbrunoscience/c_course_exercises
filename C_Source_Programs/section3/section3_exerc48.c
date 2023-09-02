#include <stdio.h>

int main() {

    int sec, hours = 0, minutes = 0;

    printf("Enter the number of seconds, please:\n");
    scanf("%d", &sec);

    if(sec >= 3600) {
        hours = sec / 3600;
        sec %= 3600;

        if(sec >= 60) {
            minutes = sec  / 60;
            sec %= 60;
        }

    } else {
        if(sec >= 60) {
            minutes = sec  / 60;
            sec %= 60;
        }
    }
     
    printf("%d:%d:%d.\n", hours, minutes, sec);

    return 0;

}