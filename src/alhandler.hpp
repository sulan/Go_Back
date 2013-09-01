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

class AlHandler
{
  public:
    ~AlHandler();
    static AlHandler& instance ();
    ALLEGRO_DISPLAY* display() const {return _display;}
    ALLEGRO_TIMER* timer() const {return _timer;}
    ALLEGRO_EVENT_QUEUE* evque () const {return _evque;}
    ALLEGRO_FONT* font () const {return _font;}
    unsigned getxx () const {return _xx;}
    unsigned getyy () const {return _yy;}
    double   getseb() const {return _seb;}
    bool open (unsigned xx, unsigned yy, bool fullscreen = false);
    void setTimer (double seb);
    //Nem masolhato
    AlHandler (const AlHandler&) = delete;
    AlHandler& operator= (const AlHandler&) = delete;
  protected:
  private:
    ALLEGRO_DISPLAY     *_display;
    ALLEGRO_TIMER       *_timer;
    ALLEGRO_EVENT_QUEUE *_evque;
    ALLEGRO_FONT        *_font;
    unsigned _xx,_yy;
    double _seb;

    AlHandler();
    void physSetUp ();
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
