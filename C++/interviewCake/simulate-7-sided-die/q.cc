#include <iostream>
#include <random>

using namespace std;

int rand7();

namespace {
  random_device rd;
  default_random_engine generator (rd());
  uniform_int_distribution<int> distribution (1, 5);
  auto rand5 = bind (distribution, generator);
}

int rand7() {
  int ret;
  do {
    ret = (rand5() - 1) * 5 + rand5();
  } while (ret > 21);
  return ret%7 + 1;
}

int main() {
  cout << "test" <<endl;
  int count[7] = {0};
 
  for (int i =0; i < 7000; i++)
  {
    count[rand7() -1]++;
  }
  
  for (int i = 0; i < 7; i++)
  {
    cout << " " << i+1 << " : " << count[i] << endl;
  }
  return 0;
}

