/**
 * Implement an algorithm to determine if a string has all unique characters what if you cannot use additional data structure.
 * 
 * using additional primitive data type
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
  // a long have 32 bit need 128 bit 
  unsigned long ascii_bit[4] = {0}; // = "abcdefghijklmnopqrstuvwxyz "; 
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
        unsigned long one_bit;

        if (i == 0)
	{
           printf ("one bit is %lu\n", one_bit);
           printf ("str[i] is %d\n", str[i]);
	}
 
  	if (str[i] < 0x100) 
	{
	  one_bit = 1 << str[i];
	  if (one_bit && ascii_bit[0])
	  {
		printN();
		return 0;
	  }
	  else
	  {
		ascii_bit[0] = ascii_bit[0] | one_bit;
	  }
	}
	else if (str[i] < 0x10000)
	{
	  one_bit = 1 << (str[i] >> 0x100);
	  if (one_bit && (unsigned long)ascii_bit[1] << 0x20)
	  {
		printN();
		return 0;
	  }
	  else
	  {
		ascii_bit[1] = ascii_bit[1] | (one_bit >> 0x20);
	  }
	}
	else if (str[i] < 0x1000000)
	{
	  one_bit = 1 << (str[i] >> 0x10000);
	  if (one_bit && (unsigned long)ascii_bit[2] << 0x40)
	  {
		printN();
		return 0;
	  }
	  else
	  {
		ascii_bit[2] = ascii_bit[2] | one_bit >> 0x40;
	  }
	}
	else
  	{
	  one_bit = 1 << (str[i] >> 0x1000000);
	  if (one_bit && (unsigned long)ascii_bit[3] << 0x60)
	  {
		printN();
		return 0;
	  }
	  else
	  {
		ascii_bit[3] = ascii_bit[3] | one_bit >> 0x60;
	  }
  	}
  }

  printU();
  return 0;
}
