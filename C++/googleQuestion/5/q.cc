#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

#define INPUT_FILE "input.txt"

using namespace std;

struct Interval {
  int start;
  int end;
  Interval (int s, int e) : start (s), end (e) {}
};

ostream &operator<< (ostream &os, const Interval &i) {
  return os << "{" << i.start << ", " << i.end <<"}";
}

vector<Interval> mergeIntervals (const vector<Interval> &intervals);
namespace {
  bool intervalcmp (Interval lhs, Interval rhs)
  { return lhs.start < rhs.start; }
}

vector<Interval> mergeIntervals (const vector<Interval> &intervals)
{
  vector<Interval> sol, tmp (intervals);
  int start = 0, end = -1;

  if (intervals.size() <= 0) return sol;
  sort (tmp.begin(), tmp.end(), intervalcmp);
  
  start = tmp[0].start; end = tmp[0].end;
  for (Interval i: tmp) 
  {
    if (i.start <= end) 
    {
      if (i.end > end)
        end = i.end;
    }
    else
    {
      sol.push_back (Interval (start, end));
      start = i.start;
      end = i.end;
    }
  }
  sol.push_back (Interval (start, end));
  return sol;
}

int main() {
  ifstream f(INPUT_FILE);
  if (!f.is_open())
  {
    cout << "can not open " << INPUT_FILE << endl;
    return -1;
  }
  
  vector<Interval> intervals;
  int start, end;
  while (!f.eof()) {
    f >> start;
    if (f.fail()) break;
    f >> end;
    if (f.fail()) break;
    intervals.push_back (Interval(start, end));
  }

  for (Interval i : intervals) {
    cout << i << " ";
  } cout << endl;

  vector<Interval> res = mergeIntervals (intervals);
  for (Interval i : res) {
    cout << i << " ";
  } cout << endl;

  return 0;
}

