#include <stdio.h>

// Functions prototype
void x(int y);

int main() {

    int a = 0;

    x(a);

    printf("%d\n", a);

    return 0;

}

void x(int y) {
    y = 2;
}