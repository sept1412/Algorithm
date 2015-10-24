#include <sstream>
#include <iostream>

using namespace std;

int main() {
  stringstream ss;
  ss << 123 << "  test " << endl;
  cout << ss.str();
  ss.str("");
  ss.clear();
  ss << 456;
  cout << ss.str() <<endl;
  return 0;
}
