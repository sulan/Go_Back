#include "medialoader.hpp"
#include <physfs.h>
#include "sub.hpp"

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
    shared_ptr<ALLEGRO_BITMAP> p ( al_load_bitmap(f.c_str()), al_destroy_bitmap);
    _imgs[string{*i}] = move(p);
  }
  PHYSFS_freeList(rc);

  dir = "data/snd/"+fnev+"/";
  rc = PHYSFS_enumerateFiles(dir.c_str());
  for (char** i = rc; *i!=NULL; ++i) {
    string f = dir+string{*i};
    shared_ptr<ALLEGRO_SAMPLE> p (al_load_sample(f.c_str()), al_destroy_sample);
    _samples[string{*i}] = move(p);
  }
  PHYSFS_freeList(rc);
}

