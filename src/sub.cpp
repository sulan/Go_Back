#include "sub.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

/**
  * Vektor
  */

Vektor::Vektor (double ax, double ay)
 : x(ax),y(ay) {
}

Vektor::Vektor () {
}

const Vektor Vektor::operator+ (const Vektor& rhs) const {
  return Vektor(x+rhs.x,y+rhs.y);
}

const Vektor Vektor::operator- (const Vektor& rhs) const {
  return Vektor(x-rhs.x,y-rhs.y);
}

const Vektor Vektor::operator* (const double& rhs) const {
  return Vektor(x*rhs,y*rhs);
}

const double Vektor::abs () const {
  return sqrt(x*x+y*y);
}

/**
  * Aprobb programozastechnikai rutinok
  */

void fatal (string s) {
  //cerr<<"[ ERROR ] "<<s<<endl<<"Shutting down..."<<endl;
  fprintf(stderr,"[ ERROR ] %s\nAborting...\n",s.c_str());
  std::abort();
}
