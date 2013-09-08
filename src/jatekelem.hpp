#ifndef JATEKELEM_HPP
#define JATEKELEM_HPP

#include <fstream>
#include "sub.hpp"
#include "elemstate.hpp"

enum JatekElemTipus {
  JEHarcolo,
  JELetra,
  JEDoboz,
  JEEletBoost,
  JEHalal,
  JELovedek,
  JEPontSzerzo,
  JECheckPoint,
  JEFegyver
};

class JatekElem
{
  public:
    JatekElem(Szint* sz);
    virtual ~JatekElem();
    CellaKoord hol_vagy () const {
      return _hely;
    }
    Szint* getSzint () const {
      return _szint;
    }
    virtual void draw () const = 0;
    void changeState (ElemState uj);
    virtual void saveToFile () = 0;
    virtual JatekElemTipus tipus () const;
    virtual void onTimer () {}
    virtual void onMsg () {}
  private:
    Szint* _szint;
    CellaKoord _hely;
    ElemState _state;
  protected:
};

class Letra : public JatekElem {
public:
  Letra (CellaKoord alja, unsigned hossz);
  Letra (ifstream& f);
  virtual ~Letra ();
  virtual JatekElemTipus tipus () const {
    return JELetra;
  }
protected:
  unsigned _hossz;
};

class EletBoost : public JatekElem {
public:
  EletBoost (CellaKoord hol, unsigned mennyi);
  EletBoost (ifstream& f);
  virtual ~EletBoost ();
  virtual JatekElemTipus tipus () const {
    return JEEletBoost;
  }
protected:
  unsigned _mennyi;
};

class Halal : public JatekElem {
public:
  Halal (const ElemShape& shape);
  Halal (ifstream& f);
  virtual ~Halal ();
  virtual JatekElemTipus tipus () const {
    return JEHalal;
  }
};

class Doboz : public JatekElem {
public:
  Doboz (CellaKoord hol, JatekElem* tartalom);
  Doboz (ifstream& f);
  virtual ~Doboz ();
  virtual JatekElemTipus tipus () const {
    return JEDoboz;
  }
protected:
  JatekElem* _tartalom;
};

class PontSzerzo : public JatekElem {
public:
  PontSzerzo (CellaKoord hol, unsigned mennyi);
  PontSzerzo (ifstream& f);
  virtual ~PontSzerzo ();
  virtual JatekElemTipus tipus () const {
    return JEPontSzerzo;
  }
protected:
  unsigned mennyi;
};

class Lovedek : public JatekElem {
public:
  Lovedek (CellaKoord hol, CellaKoord irany, int seb, int sebzes);
  Lovedek (ifstream& f);
  virtual ~Lovedek();
  virtual JatekElemTipus tipus () const {
    return JELovedek;
  }
protected:
  CellaKoord _irany;
  int _seb;
  int _sebzes;
};

class CPoint : public JatekElem {
public:
  CPoint (CellaKoord hol);
  CPoint (ifstream& f);
  virtual ~CPoint ();
  virtual JatekElemTipus tipus () const {
    return JECheckPoint;
  }
};

class Fegyver : public JatekElem {
public:
  Fegyver (CellaKoord hol, const FegyverSpec& fs);
  Fegyver (ifstream &f);
  virtual ~Fegyver ();
  virtual JatekElemTipus tipus () const {
    return JEFegyver;
  }
protected:
  FegyverSpec _fs;
};

class Harcolo : public JatekElem {
public:
  Harcolo (CellaKoord hol);
  Harcolo (ifstream& f);
  virtual ~Harcolo ();
  virtual JatekElemTipus tipus () const {
    return JEHarcolo;
  }
protected:
  int sebzes;
  int elet;
};

class PC : public Harcolo {
};

#endif // JATEKELEM_HPP
