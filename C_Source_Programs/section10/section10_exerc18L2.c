#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Functions prototype
void data_input(float *radius);
void sphere_calc(float *radius, float *area, float *volume);
void print_results(float *area, float *volume);

int main() {

    float *radius, *area, *volume;

    // Allocate memory dynamically for variables stipulated
    radius = (float *)calloc(1, sizeof(float));
    area = (float *)calloc(1, sizeof(float));
    volume = (float *)calloc(1, sizeof(float));

    // Validating memory allocation
    if(radius == NULL || area == NULL || volume == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // Calling the functions
    data_input(radius);
    sphere_calc(radius, area, volume);
    print_results(area, volume);

    // Freeing allocated memory
    free(radius);
    free(area);
    free(volume);

    return 0;

}

void data_input(float *radius) {

    printf("*** DATA INPUT ***\n\n");
    printf("Enter the radius value of the sphere, please: ");
    scanf("%f", radius);

}

void sphere_calc(float *radius, float *area, float *volume) {

    *area = 4.0 * ( M_PI ) * pow(*radius, 2.0);
    *volume = 4.0 / 3.0 * ( M_PI ) * pow(*radius, 3.0);

}

void print_results(float *area, float *volume) {

    printf("\n*** RESULTS ***\n\n");
    printf("-> Sphere area: %.2f;\n", *area);
    printf("-> Sphere volume: %.2f.\n", *volume);

}
