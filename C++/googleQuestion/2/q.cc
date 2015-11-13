#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const vector<int> input = {2, 3, 4};
const int n = 2;

bool solution (vector< vector<int> >& sol, const vector<int>& input, const int n);
void printVector (const vector<int>& v);

bool solution (vector< vector<int> >& sol, const vector<int>& input, const int n)
{
  double total = pow ((double)input.size(), (double)n);

  for (int i = 0; i < total; i++)
  {
    int number = i;
    vector<int> tmp;
    for (int j = 0; j < n; j++)
    {
      int idx = number % input.size();
      tmp.push_back (input[idx]);
      number /= input.size();
    }
    sol.push_back(tmp);
  }
  return true;
}

int main()
{
  cout << " -- INPUT -- " << endl;
  printVector (input);
  cout << "N = " << n << endl << endl;

  vector< vector<int> > sol;
  solution (sol, input, n);

  for (int i = 0; i < sol.size(); i++)
  {
    printVector (sol[i]);  
  }
  return 0;
}

void printVector (const vector<int>& v)
{
  cout << "Vec value : ";
  for (int i = 0; i < v.size()-1;i++)
    cout << v[i] << ", ";
  cout << v[v.size()-1] << endl;
}
