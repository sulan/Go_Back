#include "al_sub.hpp"
#include "alhandler.hpp"

bool hasBeenClosed() {
  ALLEGRO_EVENT ev;
  while (al_get_next_event(alHndl.evque(),&ev)) {
    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      return true;
    }
  }
  return false;
}

Vektor waitForClick() {
  if (hasBeenClosed()) {
    std::exit(EXIT_SUCCESS);
  }
  ALLEGRO_EVENT ev;
  while (1) {
    al_wait_for_event(alHndl.evque(),&ev);
    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      std::exit(EXIT_SUCCESS);
    }
    if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP
        && ev.mouse.button == 1) {
      return Vektor(ev.mouse.x,ev.mouse.y);
    }
  }
}
