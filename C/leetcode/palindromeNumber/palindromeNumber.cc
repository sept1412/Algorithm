#include <iostream>

using namespace std;

long sizeOfInt (int i)
{
  long s = 1;
  while (i > 0)
  {
    i /= 10;
    s *= 10;
  }
  return s;
}

bool isPalindrome (int x) {
  if (x==0)
    return true;
  if (x < 0)
    return false;

  long s = sizeOfInt(x)/10;
  cout << "s is " << s <<endl;
  while (x > 0)
  {
    if (x%10 != x/s)
    {
      cout << "x is "<<x<<endl;
      cout << "s is "<<s<<endl;

      return false;
    }
    x %= s;
    x /= 10;
    s /= 100;
  }
  return true;
}    

int main()
{
  cout << isPalindrome (1000000001) << endl;
  return 0;
}

