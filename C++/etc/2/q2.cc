#include <iostream>
#include <vector>
#include <fstream>

#define STOCK_VALUE_FILE "stocks.txt"
using namespace std;

bool is_localMinimum (const vector<int> & list, int idx)
{
  if (idx < 0 || idx >= list.size())
    return false;
  if (idx == 0 && list.size() == 1)
    return true;
  
  if ( ((idx != list.size()-1) || (list[idx+1] >= list[idx]))
      && ((idx != 0) || (list[idx-1] >= list[idx])) )
  {
    return true;
  }
  return false;
}

bool is_localMaximum (const vector<int> & list, int idx)
{
  if (idx < 0 || idx >= list.size())
    return false;
  if (idx == 0 && list.size() == 1)
    return true;

  if ( ((idx != list.size() - 1) || (list[idx+1] <= list[idx]))
      && ((idx != 0) || (list[idx-1] <= list[idx])) )
  {
    return true;
  }
  return false;
}

int solution (const vector<int> stock_list)
{
  int profit = 0;
  int min = stock_list[0];
  for (int i = 1; i < stock_list.size(); i++)
  {
    if (stock_list[i] < stock_list[i-1])
    {
      profit += ((stock_list[i-1] > min) ? stock_list[i-1] - min : 0);
      min = stock_list[i];
    }
  }
  return profit;
}

int main() {
  ifstream stocks_file;
  stocks_file.open (STOCK_VALUE_FILE);
  if (!stocks_file.is_open())
  {
    cout << "can not open file " << STOCK_VALUE_FILE << endl;
    return -1;
  }
  
  int val = 0;
  vector<int> stock_vals;
  while (stocks_file >> val) {
    stock_vals.push_back (val);
  }
  stocks_file.close();

  cout << "stock values are :";
  for (int i = 0; i < stock_vals.size(); i++)
  {
    cout << stock_vals[i] << " ";
  }
  cout << endl;
  
  cout << "profit is " << solution(stock_vals) << endl; 
  return 0;
}

