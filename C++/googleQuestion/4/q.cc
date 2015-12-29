#include <iostream>

using namespace std;

enum EggStatus {undamaged = 0, broken};

EggStatus dropEggsAt (int floor_number) {
  static int highest_undamaged_floor = 55;
  return (floor_number <= highest_undamaged_floor) ? undamaged : broken;
}

int main() {
  int hf= 0;
  EggStatus es = undamaged;
  int threshold = 10;
  int floor = 0;
  
  while (es == undamaged) {
    floor += threshold;
    es = dropEggsAt (floor);
  }

  for (int i = floor - threshold + 1; i < floor; i++)
  {
    if (dropEggsAt (i) == broken)
    {
      hf =  i - 1;
      break;
    }
  }
  cout << "highest floor is " << hf << endl;
  
  return 0;
}
