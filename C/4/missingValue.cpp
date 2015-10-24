/*
Find the missing number from an array of numbers that are sorted and each is an increment by 1 from the previous number.
*/

#include <iostream>
#include <fstream>
#include <vector>
#define INPUT_FILE_NAME "input.txt"

using namespace std;

int find_missing_value (vector<int> &inputs) {
  int missing_value;
  int size = inputs.size();
  int front = inputs.front();
  int back = inputs.back();
  int middle = (front + back)/2;
  
  if (back == (size + front)-1) 
    return -1;

  while (inputs[middle]+2 != inputs[middle + 1]) {
    if (middle == 0)
      return 0;
    if (inputs[middle] == (middle + front)) {
      //the missing value is on the right  
      middle += size/2 + 1;
    } else {
      //the missing value is on the left
      middle = size/2 + 1;
    }
    size++;
    size /= 2;
  } 
  
  return inputs[middle] + 1;
}

int main ()
{
  ifstream ifs(INPUT_FILE_NAME);
  vector<int> inputs;
  int T;
  
  if (!ifs.is_open())
  {
    cout << "Unable to open " << INPUT_FILE_NAME << endl;
    return 0;
  }
  
  ifs >> T; 
  cout << "Number of Input is : " << T << endl;

  for (int i = 0; i < T; i++)
  {
    int tmp;
    ifs >> tmp;
    inputs.push_back(tmp);
    cout << " " << tmp;
  }
  cout << endl;
  
  cout << "The missing value is " << find_missing_value(inputs) << endl;
  
  return 0;
}
