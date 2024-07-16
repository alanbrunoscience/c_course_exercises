#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>


int main() {

  if (setlocale(LC_ALL, "") == NULL) {
    fwprintf(stderr, L"Failed to set locale\n");
    return 1;
  }

  FILE *fptr;
  wchar_t ch;

  if((fptr = fopen("contacts.txt", "r")) == NULL) {
    wprintf(L"\n\n-> Unable to read this file. Finishing the program...\n");
    exit(1);
  }

  while((ch = fgetwc(fptr)) != EOF) {
    if(ch == 10) {
      wprintf(L"\n");
    } else {
      wprintf(L"%ld ", ch);
    }
  }

  fclose(fptr);

  wprintf(L"\n\n-> Report read successfully!\n");

  return 0;

}