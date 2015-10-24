/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

| P   A   H   N
| A P L S I I G
| Y   I   R

And then read line by line: "PAHNALSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
| string convert (string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNALSIIGYIR"
*/

#include <iostream>
#include <string>

using namespace std;

//row start from 1 to max_row
//this function will return negative value when there is no under char
int number_of_under_char (int row, int max_row)
{
  return 2*((max_row - row)-1) + 1;
}

//row start from 1 to max_row
//this function will return negative value when there is no upper char
int number_of_upper_char (int row, int max_row)
{
  return number_of_under_char((max_row-row)+1, max_row);
}

string convert(string& text, int nRows)
{
  if (nRows == 1)
    return text;

  string converted_string = text;
  int sLen = text.size();
  int didx = 0;

  for (int row = 0; row < nRows; row++)
  {
    int nUnderChar = number_of_under_char (row+1, nRows);
    int nUpperChar = number_of_upper_char (row+1, nRows);
    int sidx = 0 + row;
    bool down_direction;
    
    if (nUnderChar > 0)
      down_direction = true;
    else
      down_direction = false;

    while (sidx < sLen)
    {
      converted_string[didx] = text[sidx];
      didx++;
      if (down_direction)
      {
        sidx += 1+nUnderChar;
        if (nUpperChar > 0)
          down_direction = false;
      }
      else
      {
        sidx += 1+nUpperChar;
        if (nUnderChar > 0)
          down_direction = true;
      }
    }
  }
  return converted_string;
}

int main()
{
  //string input("PAYPALISHIRING");
  string input("ABCD");
  cout << "Input is " << input << endl;
  cout << "Converted: " << convert(input, 2) << endl;

  return 0;
}

