#include <stdio.h>
#include <stdlib.h>

void copy_file(const char *origin, const char *destiny);

int main() {

    char origin[] = "example13.c";
    char destiny[] = "cpy_file.cpy";

    copy_file(origin, destiny);

    return 0;

}

void copy_file(const char *origin, const char *destiny) {

    unsigned char buffer[1024];
    int bytes_read;

    FILE *f_origin, *f_dest;

    if((f_origin = fopen(origin, "rb")) == NULL)
        return;

    if((f_dest = fopen(destiny, "wb")) == NULL)
        return;

    do {
        bytes_read = fread(buffer, sizeof(char), sizeof(buffer), f_origin); // Reading blocks of bytes.

        fwrite(buffer, sizeof(char), bytes_read, f_dest); // Writing blocks of bytes.

    } while(bytes_read);

    fclose(f_origin);

    fclose(f_dest);

}