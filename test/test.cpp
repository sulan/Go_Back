#include <iostream>
#include <thread>
#include <chrono>
#include "../src/alhandler.hpp"
#include "../src/sub.hpp"
#include "../src/configloader.hpp"
#include "../src/medialoader.hpp"

using namespace std;

Parameter<unsigned> XX ("Test","Width");
Parameter<unsigned> YY ("","height");

void imgTest () {
  MediaLoader ml ("tst");
  shared_ptr<ALLEGRO_BITMAP> bmp = ml.getImg("dragon.png");
  for (int i = 0; i<5; ++i)  {
    al_draw_bitmap(bmp.get(),10,10,0);
    al_flip_display();
    this_thread::sleep_for(chrono::milliseconds(50));
  }
}

int main () {
  alHndl.open(XX(),YY());
  imgTest();
  this_thread::sleep_for(chrono::seconds(5));
  return 0;
}
