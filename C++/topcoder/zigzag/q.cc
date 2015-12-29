#include <iostream>
#include <fstream>
#include <vector>

#define INPUT_FILE_NAME "input.txt" 
using namespace std;

int getInput (vector<int> &input)
{
  fstream f(INPUT_FILE_NAME);
  if (!f.is_open ())
  {
    f.close ();
    cout << "Can not open " << INPUT_FILE_NAME << endl;
    return -1;
  }
  int tmp;
  f >> tmp;
  while (!f.eof () && !f.fail ())
  {
    input.push_back (tmp);
    f >> tmp;
  }
  f.close ();
  for (auto i: input)
    cout << i << ' ';
  cout <<endl;
  return 0;
}

int maxPossibleZigzag (vector<int> &zig, vector<int> &input, int idx, bool positive);

int main() {
  vector<int> input;
  if (getInput (input) != 0)
  {
    cout << " Can not get input " << endl; return -1;
  }
  
  vector<int> neg (input.size(), 0);
  vector<int> pos (input.size(), 0);
  for (int i = input.size() -1; i >= 0; i--)
  {
    cout << "number: " << input[i] << endl;
    neg[i] = maxPossibleZigzag (pos, input, i, false);
    cout << "neg: ";
    for (auto n:neg)
      cout << n << ' ';
    cout << endl;
    pos[i] = maxPossibleZigzag (neg, input, i, true);
    cout << "pos: ";
    for (auto n:pos)
      cout << n << ' ';
    cout << endl;
  } 

  int max = 0;
  for (auto n : neg) 
  {
     if (n > max) max = n;
  }
  for (auto n : pos)
  {
     if (n > max) max = n;
  }
  cout << "Longest zigzag is " << max << endl;
  return 0;
}

int maxPossibleZigzag (vector<int> &zig, vector<int> &input, int idx, bool positive)
{
  if (zig.size() == 0 || idx >= zig.size())
    return 0;

  int max = 1;
  int number = input[idx];
  for (int i = idx + 1; i < zig.size(); i++)
  {
    if (positive)
    {
      if (number > input[i] && zig[i] >= max)
        max = zig[i] + 1;
    }
    else
    {
      if (number < input[i] && zig[i] >= max)
        max = zig[i] + 1;
    }
  }

  return max;
}
