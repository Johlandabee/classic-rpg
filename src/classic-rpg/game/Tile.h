#pragma once
#include "Colors.h"

namespace Engine {
   class Tile {

   public:
       // Default char = Space
       int display = 32;
       float layer = 0;

       ForegroundColors foregroundColor = FG_Gray;
       BackgroundColors backgroundColor = BG_Black;

       Tile();
       ~Tile();
   };
}
