#include "alhandler.hpp"
#include "sub.hpp"


AlHandler& alHndl = AlHandler::instance();

AlHandler::AlHandler()
  : _xx(0),_yy(0),_seb(0), _timer{nullptr}, _display{nullptr}
{
  if (!al_init()) fatal("Couldn't init allegro5");
  if (!al_install_keyboard()) fatal("Couldn't install keyboard");
  if (!al_install_mouse()) fatal("Couldn't install mouse");
  if (!al_init_primitives_addon()) fatal("Couldn't init primitives addon");
  al_init_font_addon();
  if (!al_init_image_addon()) fatal("Couldn't init image addon");
  _evque   = al_create_event_queue();
  al_register_event_source(_evque,al_get_keyboard_event_source());
  al_register_event_source(_evque,al_get_mouse_event_source());
  al_register_event_source(_evque,al_get_display_event_source(_display));
  _font = al_create_builtin_font();
}

bool AlHandler::open(unsigned xx, unsigned yy, bool fullscreen = false) {
  if (_display) {
    al_set_display_flag(_display,ALLEGRO_FULLSCREEN,fullscreen);
    if (al_resize_display(_display,xx,yy) ) {
      _xx = xx; _yy = yy;
      return true;
    } else {
      return false;
    }
  } else {
    al_set_new_display_flags(fullscreen?ALLEGRO_FULLSCREEN:ALLEGRO_WINDOWED);
    _display = al_create_display(xx,yy);
    if (_display) {
      _xx = xx; _yy = yy;
      return true;
    } else {
      return false;
    }
  }
}

void AlHandler::setTimer (double seb) {
  if (_timer) {
    al_set_timer_speed(_timer,seb);
    _seb = seb;
  } else {
    _timer = al_create_timer(seb);
    al_register_event_source(_evque,al_get_timer_event_source(_timer));
    al_start_timer(_timer);
    _seb = seb;
  }
}

AlHandler::~AlHandler()
{
  al_destroy_font(_font);
  al_destroy_event_queue(_evque);
  al_shutdown_image_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
}

AlHandler& AlHandler::instance() {
  static AlHandler ah;
  return ah;
}

ALLEGRO_DISPLAY* AlHandler::display() const {
  return _display;
}

ALLEGRO_TIMER* AlHandler::timer() const {
  return _timer;
}

ALLEGRO_EVENT_QUEUE* AlHandler::evque () const {
  return _evque;
}

ALLEGRO_FONT* AlHandler::font () const {
  return _font;
}

unsigned AlHandler::getxx () const {
  return _xx;
}

unsigned AlHandler::getyy () const {
  return _yy;
}

double   AlHandler::getseb() const {
  return _seb;
}


/**
  * Szinek
  */

const ALLEGRO_COLOR SzinFeher = al_map_rgb(255,255,255);
const ALLEGRO_COLOR SzinFekete = al_map_rgb(0,0,0);
const ALLEGRO_COLOR SzinPiros = al_map_rgb(255,0,0);
const ALLEGRO_COLOR SzinZold = al_map_rgb(0,255,0);
const ALLEGRO_COLOR SzinKek = al_map_rgb(0,0,255);
