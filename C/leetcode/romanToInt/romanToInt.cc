#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <initializer_list>

using namespace std;

typedef unordered_map<char, int> rtoi_map;
rtoi_map map;

void tolowerString (string&s)
{
  for (int i = 0; i < s.size(); i++)
  {
    s[i] = tolower (s[i]);
  }
}

int romanToInt (string &s)
{
  int val = 0;
  tolowerString (s);

  for (int i = 0; i < s.size(); i++)
  {
    if (i+1 < s.size() && map[s[i]] < map[s[i+1]])
      val -= map[s[i]];
    else
      val += map[s[i]];
  }
      
  return val;
}

void mapInit()
{
  map['i'] = 1;
  map['v'] = 5;
  map['x'] = 10;
  map['l'] = 50;
  map['c'] = 100;
  map['d'] = 500;
  map['m'] = 1000;
}

int main()
{
  mapInit();
  string s("DCCCXC");
  
  for (auto kv: map)
  {
    cout << "key is " <<  kv.first << " value is " << kv.second << endl;
  }

  cout << "int of " << s << " is " << romanToInt (s) << endl;  
  
  return 0;
}
