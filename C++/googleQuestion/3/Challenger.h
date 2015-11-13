#ifndef __CHALLENGER_H__
#define __CHALLENGER_H__

class Challenger {
protected:
  Car * _car;
  Driver * _driver;
public:
  virtual Car * getCar () const;
  virtual Driver * getDriver () const;
  virtual void setCar (const Car * const c);
  virtual void setDriver (const Driver * const d);
};

#endif

