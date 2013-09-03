#ifndef ELEMSTATE_HPP
#define ELEMSTATE_HPP

#include "szint.hpp"

class Sprite;

/**
 * Fegyver specifikaciok
 */

struct FegyverSpec {
  int seb;                                                                      //tavfegyvernel a lovedek sebessege (kozelinel 0)
  int sebzes;
  std::vector<Sprite*> uj_spriteszett;
};

/**
 * Elem State
 */

class ElemState
{
  public:
    ElemState();
    virtual ~ElemState();
    ElemState (const ElemState&& rhs);
    ElemState& operator= (const ElemState&& rhs);
    virtual void onTimer () = 0;
    virtual void onMsg (const MessageBody& msg) = 0;
  private:
    JatekElem *_parent;
    ElemShape _shape;
    //Sprite _sprite;
    void sendMessage ();
  protected:
};

#endif // ELEMSTATE_HPP