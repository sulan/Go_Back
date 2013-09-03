#ifndef SZINT_HPP
#define SZINT_HPP

#include "alhandler.hpp"
#include "checkpoint.hpp"
#include "terkep.hpp"

class JatekElem;
class PC;

struct Cella {
  JatekElem* elol, hatul;
};

class Szint
{
  public:
    Szint();
    ~Szint();
    void handle (const ALLEGRO_EVENT& ev);
    void torol (JatekElem* kit);
    void regisztral (JatekElem* kit);
    ALLEGRO_EVENT_SOURCE* getEventSource () const {
      return &_evsrc;
    }
    const Cella& getCella (CellaKoord hol) const {
      return _cellaRacs[hol.x][hol.y];
    }
    void updateCheckPoint ();
  protected:
  private:
    ALLEGRO_EVENT_SOURCE _evsrc;
    std::vector<JatekElem*> _elemek;
    PC* _pc;
    CheckPoint _lastCheckPoint;
    Terkep _terkep;
    std::vector<std::vector<Cella> > _cellaRacs;
};

/**
 * Jatekbeli uzenetek
 */

enum MessageType {
  MsgHit,
  MsgStep
};

struct MessageBody {
  JatekElem* sender;
  const ElemShape& terulet;
  MessageType tipus;
};

#endif // SZINT_HPP
