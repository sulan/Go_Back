#ifndef MEDIALOADER_HPP
#define MEDIALOADER_HPP

#include <map>
#include <string>
#include <memory>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

class MediaLoader
{
  public:
    MediaLoader(std::string fnev);
    ~MediaLoader();
    std::shared_ptr<ALLEGRO_BITMAP> getFile (std::string nev) const {
      return _imgs.at(nev);
    }
    std::shared_ptr<ALLEGRO_SAMPLE> getFile (std::string nev) const {
      return _samples.at(nev);
    }
  protected:
  private:
    std::map<std::string,std::shared_ptr<ALLEGRO_BITMAP>> _imgs;
    std::map<std::string,std::shared_ptr<ALLEGRO_SAMPLE>> _samples;
    std::string _fnev;
    void loadFromFile (std::string fnev);
};

#endif // MEDIALOADER_HPP
