#ifndef SUB_HPP
#define SUB_HPP

#include <string>
#ifdef __DEBUG__
  #include <iostream>
#endif

/**
  * Normal, linearis algebraban alkalmazott 2D vektor, normal muveletekkel
  */

struct Vektor {
  double x,y;
  Vektor (double ax, double ay);
  Vektor ();
  const Vektor operator+ (const Vektor& rhs) const ;
  const Vektor operator- (const Vektor& rhs) const ;
  inline Vektor& operator+= (const Vektor& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  inline Vektor& operator-= (const Vektor& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  const Vektor operator* (const double& rhs) const ;
  inline Vektor& operator*= (const double& rhs) {
    x *= rhs; y *= rhs;
    return *this;
  }
  const double abs () const ;
};

/**
  *  Aprobb programozastechnikai rutinok
  */

void fatal (std::string s);
template<typename T>
inline void logstderr (T s) {
  #ifdef __DEBUG__
    std::cerr<<"[  LOG  ] "<<s<<std::endl;
  #endif
}

#endif //header guard
