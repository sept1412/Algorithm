#ifndef __GOOGLE_RACE_BUILDER_H__
#define __GOOGLE_RACE_BUILDER_H__

#include "Challenger.h"
#include "GoogleRace.h"
#include "Race.h"
#include "RaceBuilder.h"
#include "Track.h"

class GoogleRaceBuilder: public RaceBuilder {
public:
  GoogleRaceBuilder ();
  ~GoogleRaceBuilder ();
  virtual void buildRace ();
  virtual void setChallenger (const Challenger & challenger) const;
  virtual void setTrack (const Track & track) const;
  virtual Race * getRace ();
protected:
  GoogleRace * _p_race;
};
