#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_list.h"

// Function to initialize the array of linked lists
// void initialize_lists(Contact* contact_list[]) {
//     for (int i = 0; i < 26; i++) {
//         contact_list[i] = NULL;
//     }
// }

void name_formatter(char name[]) {
    // Convert first character to uppercase if it's lowercase
    if (name[0] >= 'a' && name[0] <= 'z') {
        name[0] -= 32;
    } else if (strcmp(&name[0], "ä") == 0) {
        strcpy(&name[0], "Ä");
    } else if (strcmp(&name[0], "á") == 0) {
        strcpy(&name[0], "Á");
    } else if (strcmp(&name[0], "à") == 0) {
        strcpy(&name[0], "À");
    } else if (strcmp(&name[0], "â") == 0) {
        strcpy(&name[0], "Â");
    } else if (strcmp(&name[0], "ã") == 0) {
        strcpy(&name[0], "Ã");
    } else if (strcmp(&name[0], "ç") == 0) {
        strcpy(&name[0], "Ç");
    } else if (strcmp(&name[0], "é") == 0) {
        strcpy(&name[0], "É");
    } else if (strcmp(&name[0], "ê") == 0) {
        strcpy(&name[0], "Ê");
    } else if (strcmp(&name[0], "ë") == 0) {
        strcpy(&name[0], "Ë");
    } else if (strcmp(&name[0], "è") == 0) {
        strcpy(&name[0], "È");
    } else if (strcmp(&name[0], "í") == 0) {
        strcpy(&name[0], "Í");
    } else if (strcmp(&name[0], "î") == 0) {
        strcpy(&name[0], "Î");
    } else if (strcmp(&name[0], "ï") == 0) {
        strcpy(&name[0], "Ï");
    } else if (strcmp(&name[0], "ì") == 0) {
        strcpy(&name[0], "Ì");
    } else if (strcmp(&name[0], "ñ") == 0) {
        strcpy(&name[0], "Ñ");
    } else if (strcmp(&name[0], "ö") == 0) {
        strcpy(&name[0], "Ö");
    } else if (strcmp(&name[0], "ó") == 0) {
        strcpy(&name[0], "Ó");
    } else if (strcmp(&name[0], "ô") == 0) {
        strcpy(&name[0], "Ô");
    } else if (strcmp(&name[0], "ò") == 0) {
        strcpy(&name[0], "Ò");
    } else if (strcmp(&name[0], "ü") == 0) {
        strcpy(&name[0], "Ü");
    } else if (strcmp(&name[0], "ú") == 0) {
        strcpy(&name[0], "Ú");
    } else if (strcmp(&name[0], "û") == 0) {
        strcpy(&name[0], "Û");
    } else if (strcmp(&name[0], "ù") == 0) {
        strcpy(&name[0], "Ù");
    } else if (strcmp(&name[0], "ý") == 0) {
        strcpy(&name[0], "Ý");
    }

    // Convert remaining characters to lowercase if they are uppercase
    for (int i = 1; name[i] != '\0'; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        } else if (strcmp(&name[i], "Ä") == 0) {
            strcpy(&name[i], "ä");
        } else if (strcmp(&name[i], "Á") == 0) {
            strcpy(&name[i], "á");
        } else if (strcmp(&name[i], "À") == 0) {
            strcpy(&name[i], "à");
        } else if (strcmp(&name[i], "Â") == 0) {
            strcpy(&name[i], "â");
        } else if (strcmp(&name[i], "Ã") == 0) {
            strcpy(&name[i], "ã");
        } else if (strcmp(&name[i], "Ç") == 0) {
            strcpy(&name[i], "ç");
        } else if (strcmp(&name[i], "É") == 0) {
            strcpy(&name[i], "é");
        } else if (strcmp(&name[i], "Ê") == 0) {
            strcpy(&name[i], "ê");
        } else if (strcmp(&name[i], "Ë") == 0) {
            strcpy(&name[i], "ë");
        } else if (strcmp(&name[i], "È") == 0) {
            strcpy(&name[i], "è");
        } else if (strcmp(&name[i], "Í") == 0) {
            strcpy(&name[i], "í");
        } else if (strcmp(&name[i], "Î") == 0) {
            strcpy(&name[i], "î");
        } else if (strcmp(&name[i], "Ï") == 0) {
            strcpy(&name[i], "ï");
        } else if (strcmp(&name[i], "Ì") == 0) {
            strcpy(&name[i], "ì");
        } else if (strcmp(&name[i], "Ñ") == 0) {
            strcpy(&name[i], "ñ");
        } else if (strcmp(&name[i], "Ö") == 0) {
            strcpy(&name[i], "ö");
        } else if (strcmp(&name[i], "Ó") == 0) {
            strcpy(&name[i], "ó");
        } else if (strcmp(&name[i], "Ô") == 0) {
            strcpy(&name[i], "ô");
        } else if (strcmp(&name[i], "Ò") == 0) {
            strcpy(&name[i], "ò");
        } else if (strcmp(&name[i], "Ü") == 0) {
            strcpy(&name[i], "ü");
        } else if (strcmp(&name[i], "Ú") == 0) {
            strcpy(&name[i], "ú");
        } else if (strcmp(&name[i], "Û") == 0) {
            strcpy(&name[i], "û");
        } else if (strcmp(&name[i], "Ù") == 0) {
            strcpy(&name[i], "ù");
        } else if (strcmp(&name[i], "Ý") == 0) {
            strcpy(&name[i], "ý");
        }
    }
}