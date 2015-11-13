#include "GoogleRaceBuilder.h"

#define GRB GoogleRaceBuilder

GRB::GoogleRaceBuilder () {
  _p_race == null;
}

GRB::~GoogleRaceBuilder () {}

virtual void GRB::buildRace () {
  _p_race = new GoogleRace();
}

virtual void GRB::setChallenger (const Challenger & challenger) const {
  _p_race->setChallenger (challenger, _p_race->challengerNumber() * 200);
}

virtual void GRB::setTrack (const Track & track) {
  _p_race->addTrace (track);
}

virtual Race & GRB::getRace () {
  return *_p_race;
}

