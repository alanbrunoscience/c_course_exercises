#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Functions prototype
void reverseString(char stringNum[]);
bool isPalindrome(char stringNum[]);

int main() {

    int palindromeNum = 0, firstNum = 0, secNum = 0;

    for(int i = 100; i <= 999; i++){
        for(int j = 100; j <= i; j++) {
            int mult = i * j;

            char stringNum[7];

            // Using sprintf to convert integer to string
            sprintf(stringNum, "%d", mult);

            // Call the function to validate if the number is palindrome or not
            bool palindrome = isPalindrome(stringNum);

            if(palindrome && mult > palindromeNum){
                palindromeNum = mult;
                firstNum = i;
                secNum = j;
            }
        }
    }

    printf("The largest palindromic number formed from the multiplication of three-digit numbers is %d, the result of multiplication between %d and %d.\n", palindromeNum, firstNum, secNum);
    
    return 0;

}

// Functions Definition

void reverseString(char stringNum[]) {
    int length = strlen(stringNum);
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        // Swap characters at start and end
        char temp = stringNum[start];
        stringNum[start] = stringNum[end];
        stringNum[end] = temp;
        
        // Move pointers towards the center
        start++;
        end--;

    }
}

bool isPalindrome(char stringNum[]) {

    char stringInverted[7];
    strcpy(stringInverted, stringNum);
    reverseString(stringInverted);

    if(strcmp(stringNum, stringInverted) == 0) {
        return true;
    } else {
        return false;
    }

}