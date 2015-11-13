#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <string>

class Driver {
  protected:
    std::string m_name;
  public:
    virtual const bool setName (const std::string & name) = 0;
    virtual const std::string name (void) const {return m_name;}
};

#endif

