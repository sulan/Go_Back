#include "configloader.hpp"
#include "alhandler.hpp"

ConfigLoader::ConfigLoader()
{
  //physfs es allegro init miatt kell
  AlHandler::instance();
  _cfg = al_load_config_file(ConfigFileName.c_str());
  if (!_cfg) {
    fatal("Couldn't load configuration file");
  }
}

ConfigLoader::~ConfigLoader()
{
  al_destroy_config(_cfg);
}

ConfigLoader& ConfigLoader::instance() {
  static ConfigLoader cl;
  return cl;
}
