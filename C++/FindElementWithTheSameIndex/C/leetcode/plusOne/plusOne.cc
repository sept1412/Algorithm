#include <vector>
#include <iostream>

using namespace std;

int plusOne (vector<int> &vec, int idx)
{
  if (vec[idx] == 9)
  {
    vec[idx] = 0;
    return 1;
  }
  vec[idx]++;
  return 0;
}

int main() 
{
  vector<int> v;
  v.push_back(1);v.push_back(0);

  int idx = v.size() - 1;
  while (plusOne (v, idx) == 1)
  {
    idx--;
  }

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  return 0;
}
