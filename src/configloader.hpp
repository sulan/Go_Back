#ifndef CONFIGLOADER_HPP
#define CONFIGLOADER_HPP

#include <string>
#include <vector>
#include <sstream>
#include <allegro5/allegro.h>

class OsParameter;

/**
 *  Configuration loader singleton
 */

class ConfigLoader
{
  public:
    ~ConfigLoader();
    static ConfigLoader& instance ();
    const std::string ConfigFileName = "conf/conf.ini";

    template<typename T>
    T regisztral (OsParameter* param,std::string section, std::string kulcs) {
      const char * c = section.c_str();
      const char *c2 = kulcs.c_str();
      std::stringstream ss (al_get_config_value(_cfg, c,c2));
      T eredm;
      ss>>eredm;
      _params.push_back(param);
      return eredm;
    }
    ConfigLoader (const ConfigLoader&) = delete;
    ConfigLoader& operator= (const ConfigLoader&) = delete;
  protected:
  private:
    ALLEGRO_CONFIG* _cfg;
    std::vector<OsParameter*> _params;
    ConfigLoader();
};

extern ConfigLoader& configLoader;

/**
 *  A configfajlbol betoltendo parameterek tipusa
 *  Hasznalatra pl.:
 *  deklaracio:
 *    Paramater PcSzemSzin ("PC","SzemSzin");
 *  ertek:
 *    szemszin = PcSzemSzin();
 */

//Megj.: a modosithatosag miatt lehet, hogy kesobb valtozik, de az interface marad

class OsParameter {
public:
  OsParameter () {}
  virtual ~OsParameter () {}
  OsParameter (const OsParameter&) = delete;
  OsParameter& operator= (const OsParameter&) = delete;
};

template<typename T>
class Parameter : public OsParameter {
public:
  Parameter (std::string section, std::string kulcs)
   : _section{section}, _kulcs{kulcs} {
    _value = (ConfigLoader::instance()).regisztral<T>(this,section,kulcs);
  }
  ~Parameter () {
  }
  //Nem masolhato
  Parameter (const Parameter&) = delete;
  Parameter& operator= (const Parameter&) = delete;
  const T operator() () {
    return _value;
  }
  friend class ConfigLoader;
private:
  T _value;
  std::string _section;
  std::string _kulcs;
};

#endif // CONFIGLOADER_HPP
