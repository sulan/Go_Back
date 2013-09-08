#ifndef GAMESAVE_HPP
#define GAMESAVE_HPP

#include <string>   /*       Probaljuk meg, hogy a szintet magat mentjuk el

class JatekElem;
class PC;

class GameSave
{
  public:
    GameSave(std::string fnev);
    ~GameSave();
    void loadFromFile ();
    void saveToFile ();
  protected:
  private:
    std::string _fnev;
    std::string _palya;
    std::vector<JatekElem*> _elemek;
    PC* _pc;
};                    */

#endif // GameSave_HPP
