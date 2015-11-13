#ifndef __CAR_FACTORY_H__
#define __CAR_FACTORY_H__

#include "Car.h"

class CarFactory {
public:
  Car * makeCar () = 0;
};

#endif

