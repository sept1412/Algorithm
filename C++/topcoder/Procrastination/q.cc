#include <iostream>
#include <cmath>

using namespace std;

long findFinalAssignee (long n) {
  long assignee = n;
  for (int i = 2; i*2 <= assignee; i++)
  {
    cout << i << endl;
    if (assignee % i == 0)
    {
      assignee++;
    }
    else if ( (assignee-1) % i == 0)
    {
      assignee--;
    } 
  }
  return assignee;
}

int main ()
{
  long input = 0;
  while (input < 2 || input > 10000000000l)
  {
    cout << "Please insert input between 2 and 10^10 : ";
    cin >> input;
  }
  
  cout << "Result is : " << findFinalAssignee (input) << endl;
  return 0;
}
