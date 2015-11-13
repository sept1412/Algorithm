#ifndef __MOTOR_SPORT_H__
#define __MOTOR_SPORT_H__

#include <vector>
#include "RaceBuilder.h"

class MotorSport {
public:
  static Race & CreateRace (RaceBuilder &builder
			    , const std::vector<Challenger> challengers
			    , const Track & track);
};
  
#endif
