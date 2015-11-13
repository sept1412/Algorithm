#include "MotorSport.h"

#include <vector>

static Race & MotorSport::CreateRace (
  RaceBuilder &builder
  , const std::vector<Challenger> challengers
  , const Track & track)
{
  builder.buildRace();
  builder.setTrack (track);
  for (std::vector<Challenger>::iterator it = challengers.begin()
       ; it != challengers.end()
       ; it++)
  {
     builder.setChallenger (*it);
  }
  return builder.getRace();
}

