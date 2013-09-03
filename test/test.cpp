#include <iostream>
#include <chrono>
#include "../src/alhandler.hpp"
#include "../src/sub.hpp"
#include "../src/configloader.hpp"
#include "../src/medialoader.hpp"

#ifdef __WIN32           // hulye MinGW
  #include <Windows.h>
  #define sleep_for(x) Sleep(x)
#else                    //tegyuk fel, hogy ez mar rendesen kezeli a szalakat
  #include <thread>
  #define sleep_for(x) this_thread::sleep_for(chrono::milliseconds(x))
#endif

using namespace std;

Parameter<unsigned> XX ("Test","Width");
Parameter<unsigned> YY ("","height");

void imgTest () {
  MediaLoader ml ("tst");
  shared_ptr<ALLEGRO_BITMAP> bmp = ml.getImg("dragon.png");
  for (int i = 0; i<5; ++i)  {
    al_draw_bitmap(bmp.get(),10,10,0);
    al_flip_display();
    sleep_for(50);
  }
}

int main () {
  alHndl.open(XX(),YY());
  imgTest();
  sleep_for(1000);
  return 0;
}
