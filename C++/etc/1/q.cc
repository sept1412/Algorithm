#include <iostream>
#include <vector>
using namespace std;

vector<int> & solution (vector<int> & lhs, vector<int> & rhs)
{
  if (lhs.size() == 0)
        return lhs = rhs;
  if (rhs.size() == 0)
	return lhs;

  vector<int> result;
  int lIdx, rIdx, ov = 0, tmp;
  for (lIdx = lhs.size()-1, rIdx = rhs.size()-1
       ; lIdx >= 0 && rIdx >=0
       ; lIdx--, rIdx--)
  {
        int tmp = lhs[lIdx] + rhs[rIdx] + ov;
  	result.push_back (tmp%10);
        ov = tmp/10;
  }
	
  while (lIdx >= 0)
  {
    tmp = lhs[lIdx] + ov;    
    result.push_back (tmp%10);
    ov = tmp/10;
    lIdx--;
  }
  while (rIdx >= 0)
  {
    tmp = rhs[rIdx] + ov;
    result.push_back (tmp%10);
    ov = tmp/10;
    rIdx--;
  }

  if (ov>0)
    result.push_back (ov);

  reverse (result.begin(), result.end());
  lhs = result;
  return lhs;
}
  
    
int main()
{
  vector<int> l;
  vector<int> r;
  int in;
  cout << "Please insert 1st input:";
  cin >> in;
  
  while (in > 0)
  {
    l.push_back(in%10);
    in /= 10;
  }
  cout << "Please insert 2nd input:";
  cin >> in;
  while (in >0)
  {
    r.push_back(in%10);
    in /= 10;
  }
  reverse (l.begin(), l.end());
  reverse (r.begin(), r.end());

  solution (l, r);

  for (int i = 0; i < l.size(); i++)
  {
    cout << l[i] << " " ;
  }
  cout <<endl; 
  return 0;
} 
