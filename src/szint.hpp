#ifndef SZINT_HPP
#define SZINT_HPP

#include "alhandler.hpp"
#include "gamesave.hpp"
#include "terkep.hpp"
#include "medialoader.hpp"

class JatekElem;
class PC;
struct MessageBody;

struct Cella {
  JatekElem* elol, hatul;
};

class Szint
{
  public:
    Szint(std::string nev);
    ~Szint();
    Szint (const Szint&);
    Szint& operator= (const Szint&);
    Szint (Szint&&);
    Szint& operator= (Szint&&);
    void handle (const ALLEGRO_EVENT& ev);
    void torol (JatekElem* kit);
    void regisztral (JatekElem* kit);
    void emitEvent (std::shared_ptr<MessageBody>);
    const Cella& getCella (CellaKoord hol) const {
      return _cellaRacs[hol.x][hol.y];
    }
    MediaLoader* getMLoader () const {
      return &_szintMLoader;
    }
    void updateCheckPoint ();
    void loadFromFile ();
    void saveToFile();
  protected:
  private:
    std::string _nev;
    ALLEGRO_EVENT_SOURCE _evsrc;
    std::vector<JatekElem*> _elemek;
    PC* _pc;
    Szint _lastCheckPoint;
    Terkep _terkep;
    MediaLoader _szintMLoader;
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
