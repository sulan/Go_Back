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
    ElemState (ElemState&& rhs);
    ElemState& operator= (ElemState&& rhs);
    virtual void onTimer () = 0;
    virtual void onMsg (const MessageBody& msg) {}
    virtual void draw () const = 0;
  private:
  protected:
    ElemShape _shape;
    //Sprite _sprite;
    void sendMessage (MessageType t);
};

/**
 *  Utodok
 */

class StateLetra : public ElemState {
public:
  StateLetra (Letra* parent) : _parent{parent} {}
  virtual ~StateLetra() {}
  virtual void onTimer () {}
  virtual void onMsg (const MessageBody& msg) {}
  virtual void draw () const;
protected:
  Letra* _parent;
};

#endif // ELEMSTATE_HPP
