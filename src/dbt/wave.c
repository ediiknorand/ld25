#include "wave.h"
#include "entity.h"
#include "map.h"
#include "../engine/engine.h"
#include <stdlib.h>
#include <time.h>

void wave_load()
{
  wave_cooldown = 0.0f;
  wave_n = 1;
}

void wave_summon(int n)
{
  int i = 0;
  srand(time(0));
  for(i = 0; i < n; i++)
    switch(rand()%4)
    {
    case 0: entity_spawn(ENTITY_SOLDIER, 0, rand()%MAP_HEIGHT); break;
    case 1: entity_spawn(ENTITY_SOLDIER, MAP_WIDTH-1, rand()%MAP_HEIGHT); break;
    case 2: entity_spawn(ENTITY_ARCHER, rand()%MAP_WIDTH, 0); break;
    case 3: entity_spawn(ENTITY_ARCHER, rand()%MAP_WIDTH, MAP_HEIGHT-1); break;
    }
  wave_n++;
}

void wave_refresh(double delta)
{
  wave_cooldown += delta;

  if(wave_cooldown < 15.0f+wave_n*0.1f)
    return;
  wave_summon(wave_n);
  wave_cooldown = 0.0f;
}

void wave_render()
{
  SDL_Rect dest;
  dest.x = 0;
  dest.y = 470;
  dest.h = 8;
  dest.w = (int)(float)wave_cooldown*640/(15.0f+wave_n*0.1f);
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 40, 40, 0));
}
