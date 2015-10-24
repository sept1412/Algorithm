/*
    You are a renowned thief who has recently switched from stealing precious metals to stealing cakes because of the insane profit margins. You end up hitting the jackpot, breaking into the world's largest privately owned stock of cakes -- the vault of the Queen of England.
    While Queen Elizabeth has a limited number of types of cake, she has an unlimited supply of each type.

    Each type of cake has a weight and a value, stored in tuples with two positions:
  1. An integer representing the weight of the cake in kilograms
  2. An integer representing the monetary value of the cake in British pounds

|For example:
| # weighs 7 kilograms and has a value of 160 pounds
| (7, 160)
|
| # weighs 3 kilograms and has a value of 90 pounds
| (3, 90)

You brought a duffel bag that can hold limited weight, and you want to make off with the most valuable haul possible.

Write a function max_duffel_bag_value() that takes an array of cake tuples and a weight capacity, and returns the maximum monetary value the duffel bag can hold.

|For example:
| cake_tuples = [(7, 160), (3, 90), (2, 15)]
| capacity = 20
|
| max_duffel_bag_value (cake_tuples, capacity)
| # return 555 (6 of the middle type of cake and 1 of the last type of cake)

Weights and values may be any non-negative integer. Yes, it's weird to think about cakes that weigh nothing or duffel bags that can't hold anything. But we're not just super mastermind criminals - we're also meticulous about keeping our algorithms flexible and comprehensive.
*/


#include <iostream>
#define T_WEIGHT 0
#define T_VALUE 1


using namespace std;

int main()
{
  int bag_caps;
  int *best_values;
  int cake_tuples[3][2] = {{5,9}, {3, 6}, {2, 2}};

  cout << "Input the bag capacity: ";
  cin >> bag_caps;
  cout << "The bag capacity is " << bag_caps << endl;
  
  best_values = new int[bag_caps+1];
  for (int i = 0; i <= bag_caps; ++i)
  {
    best_values[i] = 0;
  }
  
 // cout << "[t0, 0]: " << cake_tuples[0][0] << " [t0, 1]: " << cake_tuples[0][1] << " [t1, 0]: " << cake_tuples[1][0] << endl;
  
  for (int i = 1; i <= bag_caps; ++i)
  {
    int max_value = 0;
    for (int tuples = 0; tuples < 3; tuples++)
    {
      int idx = i - cake_tuples[tuples][T_WEIGHT];
      if (idx >= 0)
      {
        int value = cake_tuples[tuples][T_VALUE] + best_values[idx];
        if (value > max_value)
          max_value = value;
      }
    }
    cout << "max is " << max_value << endl;
    best_values[i] = max_value;
  }  
  
  cout << "The best_values is " << best_values[bag_caps] << endl;
  delete[] best_values;
  return 0;
}

