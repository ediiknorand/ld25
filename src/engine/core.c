#include <SDL/SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.h"

/* Init functions */
void engine_init_sdl()
{
  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
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
  engine_screen.delay = 10;

  engine_screen.surface = SDL_SetVideoMode(width, height, bpp, flags);
  if(!(engine_screen.surface))
  {
    fprintf(stderr, "Error: %s\n", SDL_GetError());
    exit(1);
  }
}

void engine_set_title(const char *title, const char *icon)
{
  SDL_WM_SetCaption(title, icon);
}

void engine_init_scene()
{
  /* place holder values */
  engine_scene.loaded = 0;
  engine_scene.load_fnc = NULL;
  engine_scene.unload_fnc = NULL;
  engine_scene.logic_fnc = NULL;
  engine_scene.render_fnc = NULL;
  engine_scene.data = NULL;
}

/* Main Loop */
void engine_main_loop()
{
  int running;
  Uint32 now, before;

  if(!(engine_scene.loaded))
  {
    fprintf(stderr, "Nothing loaded!\n");
    exit(1);
  }

  running = 1;
  before = SDL_GetTicks();
  while(running)
  {
    now = SDL_GetTicks();
    running = engine_logic_refresh((now - before)*0.001);
    //if(!running) break; /* Avoid unnecessary render refresh */
    if(!running) exit(0);
    engine_render_refresh((now - before)*0.001);
    before = now;
    SDL_Delay(engine_screen.delay); /* <- Why not Vsynced? */
  }
}


/* Generic Refresh Functions */
int engine_logic_refresh(double delta)
{
  Uint8 *keystate;
  SDL_PumpEvents();
  keystate = SDL_GetKeyState(NULL);
  return engine_scene.logic_fnc(engine_scene.data, keystate, delta);
}

void engine_render_refresh(double delta)
{
  engine_scene.render_fnc(engine_scene.data, delta);
  SDL_Flip(engine_screen.surface);
  SDL_FillRect(engine_screen.surface, NULL, 0);
}

/* Scene Loader Function */
void engine_load_scene(void *(*loadfnc)(void*), void *(*unloadfnc)(void*), 
                       int (*logicfnc)(void*,Uint8*,double), 
		       void (*renderfnc)(void*,double))
{
  if(engine_scene.loaded)
    engine_scene.data = engine_scene.unload_fnc(engine_scene.data);
  if(loadfnc && unloadfnc && logicfnc && renderfnc)
  {
    engine_scene.loaded = 1;
    engine_scene.load_fnc = loadfnc;
    engine_scene.unload_fnc = unloadfnc;
    engine_scene.logic_fnc = logicfnc;
    engine_scene.render_fnc = renderfnc;
  } else {
    fprintf(stderr, "NULL functions!\n");
    exit(1);
  }
  engine_scene.data = engine_scene.load_fnc(engine_scene.data);
}
