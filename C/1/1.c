/**
 * Implement an algorithm to determine if a string has all unique characters what if you cannot use additional data structure.
 * 
 * using additional array
 */

#include <stdio.h>
#include <string.h>

void printU()
{
  printf ("The string have all unique character\n");
}

void printN()
{
  printf ("The string do not have all unique character\n");
}

int main()
{
  char str[100];
  unsigned char ascii[128] = {0}; // = "abcdefghijklmnopqrstuvwxyz "; 
  int i = 0;
  unsigned long str_len;

  //Get Input string
  printf ("Type string input: ");
  scanf ("%s", str);
  printf ("%s\n", str);

  str_len = strlen(str);

  //using additional array
  if (str_len > 128)
  {
    printN();
    return 0;
  }

  for (i = 0; i < str_len; i++)
  { 
	if (ascii[str[i]] == 1)
        {
          printN();
          return 0;
        } 
        else
        {
          ascii[str[i]] = 1;
        } 
  }

  printU();
  return 0;
}
