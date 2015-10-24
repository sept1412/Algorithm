#include <iostream>

using namespace std;

void printArray (int *a, int len);
int r_quickSort (int *array, int sIdx, int fIdx);
int swap (int *lhs, int *rhs);

int swap (int &lhs, int &rhs) {
  int t = lhs;
  lhs = rhs;
  rhs = t;
  return 0;
}

int quickSort (int *array, int len) {
  return r_quickSort (array, 0, len-1);
}

int r_quickSort (int *array, int sIdx, int fIdx) {
  if (sIdx >= fIdx) 
    return 0;
  if (sIdx+1 == fIdx) {
    if (array[sIdx] > array[fIdx])
      swap (array[sIdx], array[fIdx]);
    return 0;
  }

  int pIdx = fIdx--;
  int start = sIdx, finish = pIdx;

  while (sIdx < fIdx) {
    while ((array[sIdx] < array[pIdx]) && (sIdx != pIdx)) {
      sIdx++;
    }
    
    while ((array[fIdx] > array[pIdx]) && (fIdx != pIdx)) {
      fIdx--;
    }
    
    if (array[sIdx] > array[fIdx] && sIdx < fIdx) {
      swap (array[sIdx], array[fIdx]);
    }
  }

  swap (array[sIdx], array[pIdx]);
  
  r_quickSort (array, start, sIdx-1);
  r_quickSort (array, sIdx, finish); 
  
  return 0;
}

void printArray (int *a, int len) {
  cout << "The array is ";
  for (int i = 0; i < len; i++ )
    cout << a[i] << " ";
  cout << endl;
}

int main () {
  int array[8] = {7, 2, 1, 6, 8, 5, 3, 4};
  printArray (array, 8); 

  quickSort (array, 8);
  cout << "After sorted" << endl;
  printArray (array, 8);
  return 0;
}
