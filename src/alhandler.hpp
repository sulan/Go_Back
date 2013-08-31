#ifndef ALHANDLER_HPP
#define ALHANDLER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "sub.hpp"

/**
  * AlHandler
  */

class AlHandler : private Uncopyable
{
  public:
    ~AlHandler();
    static AlHandler& instance ();
    ALLEGRO_DISPLAY* display() const;
    ALLEGRO_TIMER* timer() const;
    ALLEGRO_EVENT_QUEUE* evque () const;
    ALLEGRO_FONT* font () const;
    unsigned getxx () const;
    unsigned getyy () const;
    double   getseb() const;
    bool open (unsigned xx, unsigned yy, bool fullscreen);
    void setTimer (double seb);
  protected:
  private:
    ALLEGRO_DISPLAY     *_display;
    ALLEGRO_TIMER       *_timer;
    ALLEGRO_EVENT_QUEUE *_evque;
    ALLEGRO_FONT        *_font;
    unsigned _xx,_yy;
    double _seb;

    AlHandler();
};

/**
  * Globalis singleton
  */

extern AlHandler& alHndl;


/**
  * Szinek
  */

extern const ALLEGRO_COLOR SzinFeher;
extern const ALLEGRO_COLOR SzinFekete;
extern const ALLEGRO_COLOR SzinPiros;
extern const ALLEGRO_COLOR SzinZold;
extern const ALLEGRO_COLOR SzinKek;


#endif // ALHANDLER_HPP
