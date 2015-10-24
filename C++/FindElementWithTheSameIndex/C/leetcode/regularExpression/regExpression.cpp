#include <iostream>
#include <string>

using namespace std;

//string is the source
//start_index is the starting point
//the_char is the finding char
//validate is the
int findChar (string s, int start_index, char the_char, char validate) {
  for (int i = start_index; i < s.size(); i++)
  {
    if (s[i] == the_char)
      return i;
    if (validate != '.' && s[i] != validate)
      return -1;
  }
  return i;
}

char getValidateChar (sring p, int start_index) {
  if (p[start_index] == '.')
    return '.';

  for (int i = start_index; i < p.size() - 1; i+=2)
  {
    if (p[i+1] == '*')

  }
}

//get single char expression
int getSingleCharExpression (string p, int start_index) {
  char tmp = p[start_index];
  for (int i = start_index; i < p.size() - 1; i+=2)
  {
    if (p[i+1] != '*')
      return i;
  }
}

/*
get the valid char to scan
*/
//validate = getValidateChar(p, pIdx);

/*
update pIdx
*/
//pIdx = getSingleCharExpression(p, pIdx);

/*
scan source to find the next one
*/
//if (pIdx >= psize) sIdx = nextChar (s, sIdx, validate, validate)
//else sIdx = nextChar (s, sIdx, validate, p[pIdx]);

int countChar (string s, int start_index, char p, bool left) {
   int count = 0;
   if (!left) {
       while (start_index >= 0 && s[start_index] == p) {
           start_index--;
           count++;
       }
   } else {
       int len = s.size();
       while (start_index < len && s[start_index] == p) {
           start_index++;
           count++;
       }
   }
   return count;
}

bool isMatch(string s, string p)
{
  int ssize = s.size(), psize = p.size(), sIdx, pIdx;

  //cout << "-- right side --" << endl;
  for (pIdx = psize - 1, sIdx = ssize - 1
       ; pIdx >= 0 && sIdx >= 0; pIdx--, sIdx--)
  {
    //cout << "sidx is " << sIdx << endl;
    //cout << "pidx is " << pIdx << endl;
    if (p[pIdx] == '*')
    {
      //cout << "break" << endl;
      break;
    }
    else if (p[pIdx] != '.' && p[pIdx] != s[sIdx]) return false;
    //cout << "pidx is "<< pIdx << endl;
  }
  //cout << "pidx is " << pIdx << " and sidx is "<<sIdx <<endl;
  //if check all of them
  if (pIdx < 0)
  {
    return sIdx < 0;
  }

  //cout << "-- left side --" << endl;
  //Start check from the left hand side.
  psize = pIdx + 1; ssize = sIdx + 1;
  sIdx = 0; pIdx = 0;
  //cout << "psize is " << psize << " ssize is "<<ssize<<endl;
  while (pIdx < psize && sIdx < ssize)
  {
    //cout << "pidx is " <<pIdx <<endl;
    //cout << "sidx is "<<sIdx<<endl;
    //cout << "s is " <<s[sIdx]<<endl;
    if (pIdx < psize-1 && p[pIdx+1] == '*')
    {
      //cout << "p is " <<p[pIdx]<<p[pIdx+1]<<endl;
      if (p[pIdx] == '.')
      {
        while (pIdx < psize - 3 && p[pIdx + 3] == '*')
          pIdx += 3;

        if (pIdx+2 == psize) return true;
        while (s[sIdx] != p[pIdx+2] && p[pIdx+2] != '.')
        {
          //cout << "sidx is "<<sIdx<<endl;

          sIdx++;
          cout << "sidx is "<<sIdx<<endl;
          cout << "s is " <<s[sIdx]<<endl;
        }
      }
      else
      {
        if (p[pIdx+2] != '.' && p[pIdx+2] != p[pIdx])
        {
          while (s[sIdx] == p[pIdx])
          {
            sIdx++;
            cout << "sidx is "<<sIdx<<endl;
            cout << "s is " <<s[sIdx]<<endl;
          }
        }
      }
      pIdx += 2;
    }
    else
    {
      if ((p[pIdx] != '.') && p[pIdx] != s[sIdx])
      {
        return false;
      }
      pIdx++; sIdx++;
    }
  }
  cout << "pidx is " << pIdx << " sidx is " <<sIdx<<endl;
  //remove * expression
  while (p[pIdx + 1] == '*') pIdx += 2;
  if (pIdx >= psize)
  {
    return sIdx >= ssize;
  }
  return false;
}

//if find pidx + 1 == * then look at the other that do not have '*'
// then try to match it


int main () {
  //        0123456789012345678
  string s("a a bcbcbcaccbcaabc");
  string p(".*a*a a*.*b*. c*.*a*");

"a a a"
"a a "

"aaabbbcccd"
"a*b*c*.*d"

"aaa bbb ccc d"
"a* b* c* d*"
//p
// * mean what is validat

  bool b = isMatch (s, p);
  cout << s << " is " <<  (b ? "match ":"not match ") << p << endl;
  return 0;
}
