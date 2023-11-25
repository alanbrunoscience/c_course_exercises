#include <stdio.h>

int main() {

    int n1, n2;

    printf("Enter the 1º integer value, please:\n");
    scanf("%d", &n1);

    printf("Enter the 2º integer value, please:\n");
    scanf("%d", &n2);

    printf("\n\n*** VARIABLES ADDRESS ***\n\n");
    printf("-> First Variable's Content: %d / Address: %p;\n", n1, &n1);
    printf("-> Second Variable's Content: %d / Address: %p.\n", n2, &n2);

    if(&n1 > &n2) {
        printf("\nThe content of the variable allocated at the largest address is %d, and its address is %p.\n", n1, &n1);
    } else {
        printf("\nThe content of the variable allocated at the largest address is %d, and its address is %p.\n", n2, &n2);
    }

    return 0;

}