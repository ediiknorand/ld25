#include <SDL/SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "engine-core.h"

/* Init functions */
void engine_init_sdl()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "Error: %s\n", SDL_GetError());
    exit(1);
  }
  atexit(SDL_Quit);
}

void engine_init_screen(int width, int height, int bpp, Uint32 flags)
{
  /* Init engine_screen struct */
  engine_screen.width = width;
  engine_screen.height = height;
  engine_screen.bpp = bpp;
  engine_screen.flags = flags;

  engine_screen.surface = SDL_SetVideoMode(width, height, bpp, flags);
  if(!(engine_screen.surface))
  {
    fprintf(stderr, "Error: %s\n", SDL_GetError());
    exit(1);
  }
}

void engine_init_scene()
{
  /* place holder values */
  engine_scene->loaded = 0;
  engine_scene->load_fnc = NULL;
  engine_scene->unload_fnc = NULL;
  engine_scene->logic_fnc = NULL;
  engine_scene->render_fnc = NULL;
}

/* Main Loop */
void engine_main_loop()
{
  int running;
  Uint32 now, before;

  if(!(engine_scene->loaded))
  {
    fprintf(stderr, "Nothing loaded!\n");
    exit(1);
  }

  running = 1;
  before = SDL_GetTicks();
  while(running)
  {
    now = SDL_GetTicks;
    running = engine_logic_refresh(now - before);
    if(!running) break; /* Avoid unnecessary render refresh */
    engine_render_refresh(now - before);
    before = now;
    SDL_Delay(10); /* <- Why not Vsynced? */
  }
}


/* Generic Refresh Functions */
int engine_logic_refresh(Uint32 delta)
{
  Uint8 *keystate = SDL_GetKeyState(NULL);
  return engine_scene->logic_fnc(keystate, delta);
}

void engine_render_refresh(Uint32 delta)
{
  engine_scene->render_fnc(delta);
  SDL_Flip(engine_screen.surface);
  SDL_FillRect(engine_screen.surface, NULL, 0);
}

/* Scene Loader Function */
void engine_load_scene(void (*loadfnc)(), void (*unloadfnc)(), int (*logicfnc)(Uint8*,Uint32), void (*renderfnc)(Uint32))
{
  if(engine_scene->loaded)
    engine_scene->unload_fnc();
  if(loadfnc && unloadfnc && logicfnc && renderfnc)
  {
    engine_scene->loaded = 1;
    engine_scene->load_fnc = loadfnc;
    engine_scene->unload_fnc = unloadfnc;
    engine_scene->logic_fnc = logicfnc;
    engine_scene->render_fnc = renderfnc;
  } else {
    fprintf(stderr, "NULL functions!\n");
    exit(1);
  }
  engine_scene->load_fnc();
}
