#include <iostream>
#include <vector>

using namespace std;

int squares[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int newNumber (int number)
{
  int n = 0;
  while (number > 0)
  {
    n += squares[number%10];
    number /= 10;
  }

  return n;
}

bool happyNumber (int number)
{
  vector<bool> chk;

  chk.resize(number+1);

  while (number > 1)
  {
    if (chk[number])
      return false;
        
    chk[number] = true;
    number = newNumber (number);

    if (number > chk.size())
      chk.resize (number+1);
  }

  return number;
}

int main() 
{
  cout << happyNumber (930055043) <<endl;
  
  return 0;
}
