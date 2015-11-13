#ifndef __RACE_BUILDER_H__
#define __RACE_BUILDER_H__

#include "Challenger.h"
#include "Race.h"
#include "Track.h"

class RaceBuilder {
public:
  virtual void buildRace ();
  virtual void setChallenger (const Challenger & challenger) const;
  virtual void setTrack (const Track & track) const;
  virtual Race * getRace () = 0;
};

#endif
