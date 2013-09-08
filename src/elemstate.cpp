#include "elemstate.hpp"
#include "alhandler.hpp"

using namespace std;

ElemState::ElemState(JatekElem* parent)
 : _parent{parent}
{
  //ctor
}

ElemState::~ElemState()
{
  //dtor
}

ElemState::ElemState (ElemState&& rval) {
  _shape = move(rval._shape);
  _parent = rval._parent;
}

ElemState& ElemState::operator=(ElemState&& rhs) {
  _shape = move(rhs._shape);
  _parent = rhs._parent;
}

void ElemState::sendMessage(MessageType t) {
  shared_ptr<MessageBody> m = new MessageBody {_parent, _shape, t};
  _parent->getSzint()->emitEvent(m);
}
