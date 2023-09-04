#include <stdio.h>

int main() {

    float g1, g2, g3, wghtAverage;

    do {

        printf("Enter the laboratory work grade, please:\n");
        scanf("%f", &g1);

        printf("Enter the semester evaluation grade, please:\n");
        scanf("%f", &g2);

        printf("Enter the final exam grade, please:\n");
        scanf("%f", &g3);

        if(g1 < 0.0 ||  g1 >  10.0 || g2 < 0.0 ||  g2 >  10.0 || g3 < 0.0 ||  g3 >  10.0){
            printf("Invalid grades! The grades need to be between 0.0 and 10.0.");
        }

    } while(g1 < 0.0 ||  g1 >  10.0 || g2 < 0.0 ||  g2 >  10.0 || g3 < 0.0 ||  g3 >  10.0);

    wghtAverage = ((g1 * 2) + (g2 * 3) + (g3 * 5)) / 10.0;

    if(wghtAverage >= 0.0 && wghtAverage <= 2.9) {
        printf("Disapproved! The average is %.2f.\n", wghtAverage);
    } else if (wghtAverage >= 3.0 && wghtAverage <= 4.9) {
        printf("Summer School! The average is %.2f.\n", wghtAverage);
    } else {
        printf("Approved! The average is %.2f.\n", wghtAverage);
    }

    return 0;

}