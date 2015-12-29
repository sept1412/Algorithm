#include <iostream>
#include <utility>

#include <cmath>

// Assumption# the rider have to start with his/her starting point and finish at his/her finishing point
//Shorter detour is 
//     A->C->D->B
//  or C->A->B->D
//
// **Both have to travel A-C and B-D route. The different is C-D or A-B
// That mean we have to calculate A-B or C-D is shorter
// if C-D is shorter then we start wih A
// otherwise we start with C

double PI () {return M_PI;}
int EARTH_RADIUS () {return 6371000;}
double degreeToRadian (const double d); // to use with sin, cos, etc..
double radianToDegree (const double r); 
double normalizeDegree (const double d); // convert to 0 - 359 range

class Location {
private:
  float m_latitude;   //in degree
  float m_longtitude; //in degree
public:
  Location (double la, double lo) : m_latitude (la), m_longtitude (lo) {};
  float latitude () const {return m_latitude;};
  float longtitude () const {return m_longtitude;};
  friend double getDistance (const Location l1, const Location l2); // in meters
  friend std::ostream& operator<< (std::ostream& os, const Location& l);
};

typedef std::pair<Location, Location> ride;

// ## SHORTER DETOUR ##
double shorterDetour (const ride & r1, const ride & r2)
{
  double d1 = getDistance (r1.first, r1.second);
  double d2 = getDistance (r2.first, r2.second);
  double start1ToStart2 = getDistance (r1.first, r2.first);
  double finish1ToFinish2 = getDistance (r1.second, r2.second);

  return start1ToStart2 + finish1ToFinish2 + ((d1>d2)?d2:d1);
}

// ## MAIN ##
int main () {
  Location ls1 (33.842475, -118.255463);
  Location lf1 (33.858442, -118.159332);
  Location ls2 (33.976392, -118.218384);
  Location lf2 (33.799691, -118.181992);
  std::cout << "Fist Distance is   : " << getDistance (ls1, lf1) << std::endl;
  std::cout << "Second Distance is : " << getDistance (ls2, lf2) << std::endl;
  std::cout << "Start to Start Distance is : " << getDistance (ls1, ls2) << std::endl;
  std::cout << "Stop to Stop Distance is   : " << getDistance (lf1, lf2) << std::endl; 
  double distance = shorterDetour (ride (ls1, lf1), ride (ls2, lf2));
  std::cout << "Shorter detour is  : " << distance << std::endl;
  return 0;
}

double nomalizeDegree (const double d)
{
  double tmp = d;
  while (tmp < 0)
  {
    tmp += 360;
  }

  while (tmp >= 360)
  {
    tmp -= 360;
  }
  return tmp;
}

double degreeToRadian (const double d)
{
  return d * (PI()/180);
}

double radianToDegree (const double r)
{
  return r * (180/PI());
}

double getDistance (const Location l1, const Location l2)
{
  double radLat1 = degreeToRadian (l1.latitude ());
  double radLat2 = degreeToRadian (l2.latitude ());
  double diffLat = degreeToRadian (l1.latitude() - l2.latitude());
  double diffLon = degreeToRadian (l1.longtitude() - l2.longtitude());
  double haversine = (sin (diffLat/2) * sin (diffLat/2))
                     + (cos (radLat1) * cos (radLat2) * sin (diffLon/2) * sin (diffLon/2));
  
  return EARTH_RADIUS () * 2 * atan2 (sqrt(haversine), sqrt(1 - haversine));
}

std::ostream& operator<< (std::ostream& os, const Location& l)
{
  os << "Latitude:" << l.latitude() << " " << "Longtitude:" << l.longtitude();
  return os;
}

