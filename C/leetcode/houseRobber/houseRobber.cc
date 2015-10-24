#include <vector>
#include <iostream>

using namespace std;

class robInfo {
  int m_lastHouse;
  int m_amount;
public:
  int lastHouse();
  int amount();
  robInfo (int lastHouse, int amount);
};

int robInfo::lastHouse()
{
  return m_lastHouse;
}

int robInfo::amount()
{
  return m_amount;
}

robInfo::robInfo (int lastHouse, int amount)
{
  m_lastHouse = lastHouse;
  m_amount = amount;
}

int main () 
{
  vector<robInfo> mem;
  mem.push_back(robInfo(10, 10));

  cout << mem[0].amount() << endl;
  return 0;
}
