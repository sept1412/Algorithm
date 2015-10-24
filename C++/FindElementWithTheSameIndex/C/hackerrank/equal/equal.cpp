/*
Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. She is biased to wards her friends and may have distributed the chocolates unequally. One of the program managers gets to know this and orders Christy to make sure everyone gets equal number of chocolates.

But to make things difficult for the intern, she is ordered to equalize the number of chocolates for every colleague in the following manner, 

For every operation, she can choose one of her colleagues and can do one of the three things. 
 (i) She can give one chocolate to every colleague other than chosen one.
 (ii) She can give two chocolates to every colleague other than chosen one.
 (iii) She can give five chocolates to every colleague other than chosen one.

Calculate minimum number of such operations needed to ensure that every colleague has the same number of chocolates.

[Input Format]

T lines, each containing the minimum number of operations needed to make sure all colleagues have the same number of chocolates.

[Constraints]

1 <= T <= 100 
1 <= N <= 10000
Number of initial chocolates each colleague has < 1000

[Sample Input]
|1
|4
|2 2 3 7

[Sample Output]
|2

[Explanation]
1st operation: Christy increases all elements by 1 except 3rd one
2 2 3 7 -> 3 3 3 8
2nd operation: Christy increases all element by 5 except last one

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define INPUT_FILE_NAME "input.txt"

using namespace std;

int min_operation_of_pair (int lhs, int rhs)
{
  int min = 0;
  int total_op;

  if (lhs > rhs)
  {
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
  }
  
  total_op = rhs - lhs;
  min += total_op/5;
  total_op = total_op%5;

  min += total_op/2;
  total_op = total_op%2;

  min += total_op;
  
  return min;
}

int minimum_operation (vector<int> colleague_chocos)
{
  int count_operations = 0;
  int min = *min_element (colleague_chocos.begin(), colleague_chocos.end());

  for (vector<int>::iterator it = colleague_chocos.begin()
       ; it != colleague_chocos.end()
       ; ++it)
  {
    count_operations += min_operation_of_pair(min, *it);
  }
  
  return count_operations;
}

int main ()
{
  ifstream finput;
  int T, N;
  int number_operations = 0;
  
  finput.open (INPUT_FILE_NAME);
  if (!finput.is_open())
  {
    cout << "Unable to open the input file" << endl;
    return -1;
  }

  finput >> T;
  cout << "Number of test cases: " << T << endl;

  for (int i = 0; i < T; i++)
  {
    cout << "Test case Number: " << i+1 << endl;
    int choco, min;
    vector<int> colleague_chocos;
    finput >> N;
    
    cout << "[" << i+1 << "]" <<  " Number of colleague: " << N << endl;
    
    cout << "[" << i+1 << "]";
    for (int j = 0; j < N; j++)
    {
      finput >> choco;
      cout << " " << choco;
      colleague_chocos.push_back(choco);
    }
    min = minimum_operation (colleague_chocos);
    cout << endl << "[" << i+1 << "]" << " Minimum operations is " << min << endl << endl;
  }

  return 0;
}
