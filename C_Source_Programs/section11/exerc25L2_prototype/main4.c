#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MAX_NAME_LENGTH 100 // Define a maximum name length

int main() {

  setlocale(LC_ALL, "");

  wchar_t name[MAX_NAME_LENGTH]; // Array to store user input

  wprintf(L"Enter your name: ");
  fwscanf(stdin, L" %ls[^\n]", name); // Read user input with wide characters

  wprintf(L"Before implementing towupper function: %ls\n", name);

  for (size_t i = 0; i < wcslen(name); i++) {
      name[i] = towupper(name[i]);
  }

  wprintf(L"After implementing towupper function: %ls\n", name);

  return 0;
}