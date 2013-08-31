#include "medialoader.hpp"
#include <physfs.h>

using namespace std;

MediaLoader::MediaLoader(string fnev)
 : _fnev{fnev}
{
  loadFromFile(fnev);
}

MediaLoader::~MediaLoader()
{
  //dtor
}

void MediaLoader::loadFromFile(string fnev) {
  string dir = "data/img/"+fnev+"/";
  char** rc = PHYSFS_enumerateFiles(dir.c_str());
  for (char** i = rc; *i!=NULL; ++i) {
    string f = dir+string{*i};
    _imgs[fnev] = al_load_bitmap(f.c_str());
  }
  PHYSFS_freeList(rc);

  dir = "data/snd/"+fnev+"/";
  rc = PHYSFS_enumerateFiles(dir.c_str());
  for (char** i = rc; *i!=NULL; ++i) {
    string f = dir+string{*i};
    _samples[fnev] = al_load_sample(f.c_str());
  }
  PHYSFS_freeList(rc);
}


