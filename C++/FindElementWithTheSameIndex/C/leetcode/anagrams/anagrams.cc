#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct mapValue
{
  int value;
  int index;
};
typedef std::unordered_map<std::string, mapValue> string_map;

int main()
{
  std::vector<std::string> input;
  std::vector<std::string> output;
  string_map m;

  input.push_back ("abc");
  input.push_back ("acb");
  
  //copy input to v
  std::vector<std::string> v = input;
  output = input;

//  std::cout << v[0] << std::endl;
//  std::sort(v[0].begin(), v[0].end());
//  std::cout << v[0] << std::endl;

  for (int i = 0; i < v.size(); i++) 
  {
     std::sort(v[i].begin(), v[i].end());
     m[v[i]].value++;
     m[v[i]].index = i;
  }

  int i = 0;
  for (auto kv : m)
  {
    std::cout << "#" << i << " is " << kv.first.value << std::endl;
    i++;
  }

  std::cout << "number of " << v[0] << " is " << m[v[0]].value << std::endl;
  return 0;
}
