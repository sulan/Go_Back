#ifndef CONFIGLOADER_HPP
#define CONFIGLOADER_HPP

#include <string>
#include <vector>
#include <sstream>
#include <allegro5/allegro.h>

const std::string ConfigFileName = "conf/conf.ini";

class Parameter;

/**
 *  Configuration loader singleton
 */

class ConfigLoader
{
  public:
    ~ConfigLoader();
    static ConfigLoader& instance ();

    template<typename T>
    T regisztral (Parameter* param,std::string section, std::string kulcs) {
      std::stringstream ss (al_get_config_value(_cfg, section.c_str(),kulcs.c_str));
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
    vector<Parameter*> _params;
    ConfigLoader();
};

extern ConfigLoader& configLoader;

/**
 *  A configfajlbol betoltendo paramterek tipusa
 *  Hasznalatra pl.:
 *  deklaracio:
 *    Paramater PcSzemSzin ("PC","SzemSzin");
 *  ertek:
 *    szemszin = PcSzemSzin();
 */

template<typename T>
class Parameter {
public:
  Parameter (std::string section, std::string kulcs)
   : _section{section}, _kulcs{kulcs} {
    _value = (ConfigLoader::instance()).regisztral(this,section,kulcs)
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
