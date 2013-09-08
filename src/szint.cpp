#include "szint.hpp"
#include <algorithm>

using namespace std;

Szint::Szint(string nev)
 : _nev{nev}
{
  //ctor
}

Szint::~Szint()
{
  //dtor
}

void Szint::handle (const ALLEGRO_EVENT& ev) {
  if (ev.type == ALLEGRO_EVENT_TIMER) {
    for_each(_elemek.begin(),_elemek.end(),[](JatekElem* ez){ez->OnTimer();});
    for_each(_elemek.begin(),_elemek.end(),[](JatekElem* ez){ez->draw()});
  }
}

void Szint::torol (JatekElem* kit) {
  vector<JatekElem*>::iterator i = find(_elemek.begin(),_elemek.end(),kit);
  if (i == _elemek.end()) {
    logstderr("Nemletezo elemet probaltunk torolni"+to_string(kit));
    return;
  }
  (*i) = _elemek[_elemek.size()-1];
  _elemek.pop_back();
  delete kit;
}

void Szint::regisztral (JatekElem* kit) {
  _elemek.push_back(kit);
}

void Szint::updateCheckPoint () {
  _lastCheckPoint = *this;
}

void Szint::loadFromFile () {
}

void Szint::saveToFile() {
}
