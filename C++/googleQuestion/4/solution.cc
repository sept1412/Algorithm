#include <iostream>
#include <cstdlib>

using namespace std;

int hf;

enum EggStatus {undamaged, broken};

EggStatus dropAt (int floor) {
  return (floor <= hf) ? undamaged : broken;
}

int findHighestFloor () {
  int threshold = 14;
  int drop_floor = 0, last_floor = 0;

  for (int i = 0; i < 14; i++)
  {
    drop_floor += (threshold - i);

    if (drop_floor > 100 || dropAt (drop_floor) == broken)
      break;
 
    last_floor = drop_floor;
  }
  
  for (int i = last_floor + 1; i <= drop_floor; i++)
  {
    if (i == 101 || dropAt (i) == broken)
      return i - 1;
  }
  return 100;
}
    

int main (int argc, char** argv) {

/*  do {
    cout << "Please insert the highest floor to drop : ";
    cin >> hf;
  } while (hf < 0 || hf > 100);  */
  hf = atoi (argv[1]);

  cout << "Highest floor drop is " << findHighestFloor () << endl;
  return 0;
}
  

  
