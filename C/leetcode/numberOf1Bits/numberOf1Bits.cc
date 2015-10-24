#include <iostream>
#include <cstdint>

using namespace std;

int main () 
{
  int count = 0;
  uint32_t n = 123;
  cout << bitset<16>(n) << endl;

  for (int num = n; num > 0; num = num >> 1)
  {
    if (num & 1)
	count++;
  }
  cout << count << endl;
  return 0;
}

