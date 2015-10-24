/*
 * Implement a function void reverse (char *str) in C or C++ which reverses a null-terminated string.
 */

#include <stdio.h>
#include <string.h>

void reverses (char *str)
{
  str_len (str);
}

int main() {
  char str[100];

  printf ("Input string: ");
  scanf ("%s", str);
  
  reverses(str);
  printf ("%s\n", str);
  return 0;
}
