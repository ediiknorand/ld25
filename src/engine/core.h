#include <SDL/SDL.h>

#ifndef H_ENGINE_CORE_H
#define H_ENGINE_CORE_H

/* Structures */
typedef struct
{
  int width, height, bpp;
  Uint32 flags;
  SDL_Surface *surface;
} Engine_screen;

typedef struct
{
  int loaded;
  void (*load_fnc)();
  void (*unload_fnc)();

  int (*logic_fnc)(Uint8*, Uint32);
  void (*render_fnc)(Uint32);
} Engine_scene;

/* Global Vars */
Engine_screen engine_screen;
Engine_scene engine_scene;

/* Init functions */
void engine_init_sdl();
void engine_init_screen(int width, int height, int bpp, Uint32 flags);

/* Main Loop */
void engine_main_loop();

/* Generic Refresh Functions */
int engine_logic_refresh(Uint32 delta);
void engine_render_refresh(Uint32 delta);

/* Scene Loader Function */
void engine_load_scene(void (*loadfnc)(), void (*unloadfnc)(), int (*logicfnc)(Uint8*,Uint32), void (*renderfnc)(Uint32));

#endif
