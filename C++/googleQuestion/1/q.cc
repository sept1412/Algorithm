/*
the solution here is by doing divide and conquer

basically it is merge sort with special feature to track how many element on the right side has higher value than the current node.

algorithm
1. if there is only 1 or less element then return.
2. otherwise split the input into 2 part and called each part recursively.
3. combine
   3.1 now each part suppose to be sorted
   3.2 mark the first element from left and right part.
   3.3 put the lower value element in the result.
   3.4 but if the lower value element is on the left part then increase the tracked value (data.result) equal to number of elements left on the right part. 

*** This code have to compile using [-std=c++11] flag 
    ex. g++ -std=c++11 -o q q.cc
*/
#include <iostream>
#include <vector>

using namespace std;

//const vector<int> input = {3, 4, 5, 9, 2, 1, 3};
//const vector<int> input = {3, 4};
const vector<int> input = {3, 4, 3, 4, 3, 4, 3};

struct data {
  int index;
  int result;
  int value;
};

void printData (const vector<data>& v);
void printVector (const vector<int>& v);
bool prepareData (vector<data>& d, const vector<int> input);
bool _r_solution (vector<data> & dat, int start, int end);

bool solution (vector<int>& sol, const vector<data>& dat, int start, int end)
{
  vector<data> tmp(dat);
  _r_solution (tmp, start, end);
  
  sol.clear();
  sol.resize(dat.size());
  for (int i = 0; i < tmp.size(); i++)
  {
    sol[tmp[i].index] = tmp[i].result;
  }
  return true;
}

bool _r_solution (vector<data>& dat, int start, int end)
{
  if (start >= end)
    return true;

  int mid = (start + end)/2;
  _r_solution (dat, start, mid);
  _r_solution (dat, mid + 1, end);

  int lhs = start, rhs = mid+1;
  vector<data> tmp;
  while (lhs <= mid && rhs <= end)
  {
    if (dat[lhs].value < dat[rhs].value)
    {
      dat[lhs].result += ((end - rhs) + 1);
      tmp.push_back(dat[lhs]);
      lhs++;
    }
    else
    {
      tmp.push_back (dat[rhs]);
      rhs++;
    }
  }
  for (;rhs<=end;rhs++) tmp.push_back(dat[rhs]);
  for (;lhs<=mid;lhs++) tmp.push_back(dat[lhs]);

  for (int i = start; i <= end; i++)
  {
    dat[i].index = tmp[i - start].index;
    dat[i].result = tmp[i - start].result;
    dat[i].value = tmp[i - start].value;
  }
    
  return true;
}

int main()
{
  cout << "input array:" << endl;
  printVector (input);
  
  vector<data> vec;
  prepareData (vec, input);
//  printData (vec);
  
  vector<int> sol(input.size());
  solution (sol, vec, 0, vec.size() - 1);
  cout << endl << "solution array:" << endl;
  printVector (sol);
//  printData (vec);
 
  return 0;
}

bool prepareData (vector<data>& d, const vector<int> input)
{
  d.clear();
  for (int i = 0; i < input.size(); i++)
  {
    data tmp;
    tmp.index = i;
    tmp.result = 0;
    tmp.value = input[i];
    d.push_back(tmp);
  }
  return true;
}

void printData (const vector<data>& v)
{
  cout << "Data value is :";
  for (int i = 0; i < v.size()-1; i++)
  {
    cout << v[i].value << ", ";
  }
  cout << v[v.size()-1].value << endl;
  
  cout << "Data result is :";
  for (int i = 0; i < v.size()-1; i++)
  { 
    cout << v[i].result << ", ";
  }
  cout << v[v.size()-1].result << endl;
}

void printVector (const vector<int>& v)
{
  cout << "Vector value is :";
  for (int i = 0; i < v.size() - 1; i++)
    cout << v[i] << ", ";
  cout << v[v.size()-1] << endl;
}
