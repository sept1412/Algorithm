#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void printVector (const vector<int> &v, int sIdx, int size);

bool isIndexMatchWithValue (const vector<int> &v, int sIdx, int size)
{
  if (size <= 0) return false;
  
  printVector (v, sIdx, size); 
  cout << "sIdx is " << sIdx << " :size is " << size <<endl<<endl;

  int mid = sIdx + (size-1)/2;
  if (v[mid] == mid)
    return true;
  else if (v[mid] < mid)
    return isIndexMatchWithValue (v, mid+1, size/2);
  else
    return isIndexMatchWithValue (v, sIdx, (size-1)/2);
}

int main (int argc, char **argv)
{
  //get input
  vector<int> input;
  for (int i = 1; i < argc; i++)
  {
    input.push_back (atoi (argv[i]));
  }
  //sort it
  sort (input.begin(), input.end());
  printVector (input, 0, input.size());

  cout << endl;
  cout << "Is matching ? "
       << (isIndexMatchWithValue (input, 0, input.size()) ? "Yes" : "No")
       << endl; 
  return 0;
}
  
void printVector (const vector<int> &v, int sIdx, int size)
{
  cout << "The vector value is : ";
  int fin = sIdx + size;
  for (int i = sIdx; i <  fin - 1; i++)
  {
    cout << v[i] << ", ";
  }
  cout << v[fin-1] << endl;
}
