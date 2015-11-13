#ifndef __RACE_H__
#define __RACE_H__

#include "Challenger.h"
#include "Record.h"
#include "Track.h"

class Race {
public:
  virtual void addChallenger (const Challenger * const challenger);
  virtual void addTrack (const Track * const track);
  virtual void start ();
  virtual Record * getRecord () = 0;
};

#endif

