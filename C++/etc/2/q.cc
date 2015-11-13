#include <iostream>
#include <vector>
#include <fstream>

#define STOCK_VALUE_FILE "stocks.txt"
using namespace std;

int solution (const vector<int> stock_list)
{
  int profit = 0;
  int min = stock_list[0];
  for (int i = 0; i < stock_list.size(); i++)
  {
    if (min > stock_list[i])
      min = stock_list[i];
    if (stock_list[i] - min > profit)
      profit = stock_list[i] - min;
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

