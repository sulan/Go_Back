#ifndef TERKEP_HPP
#define TERKEP_HPP

#include "alhandler.hpp"

class Terkep
{
  public:
    Terkep();
    ~Terkep();
    //Kepernyore
    void draw () const;
    //Rajzoljon ide
    void beDrawn (ALLEGRO_BITMAP* kep, Vektor hova);
  protected:
  private:
    ALLEGRO_BITMAP* _bmp;
};

#endif // TERKEP_HPP
