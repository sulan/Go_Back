#ifndef AL_SUB_HPP
#define AL_SUB_HPP

#include <allegro5/allegro.h>
#include "sub.hpp"

/**
 *  Returns true if user has closed window
 */

bool hasBeenClosed ();

/**
 *  Waits for clicking, returns position
 *  click defined as release of button
 *  warning: upon window closure, exits program
 */

Vektor waitForClick ();


#endif //header guard
