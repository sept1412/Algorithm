#ifndef __CAR_H__
#define __CAR_H__

class Car {
  protected:
    int m_topspeed;
    int m_acceleration;
    int m_handling;
    int m_speed;
    bool m_nitro;

  public:
    virtual const int topspeed (void) const {return m_topspeed;}
    virtual const int speed (void) const {return m_speed;}
    virtual const int acceleration (void) const {return m_acceleration;}
    virtual const int handling (void) const {return m_handling;}
    virtual const bool hasUsedNitro (void) const {return m_nitro;}
};

#endif
    
