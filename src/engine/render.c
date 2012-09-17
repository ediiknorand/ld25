#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "render.h"
#include "core.h"

/* Init Render */
void engine_init_render(int flags)
{
  int initted=IMG_Init(flags);
  if((initted & flags) != flags)
  {
    fprintf(stderr, "Error: %s.\n", IMG_GetError());
    exit(1);
  }
}

/* Quit Render */
void engine_quit_render()
{
  IMG_Quit();
}

/* Load image */
SDL_Surface *engine_load_image(char *filename)
{
  SDL_Surface *aux = IMG_Load(filename);
  SDL_Surface *image = NULL;
  if(!aux)
  {
    fprintf(stderr, "Error: Can't load %s.\n%s.\n", filename, IMG_GetError());
    exit(1);
  }
  image = SDL_DisplayFormatAlpha(aux);
  SDL_FreeSurface(aux);
  return image;
}

/* Unload image */
void engine_unload_image(SDL_Surface *image)
{
  SDL_FreeSurface(image);
}

/* Render function */
void engine_render_surface(SDL_Surface *src_surface, SDL_Rect *src_rect, SDL_Rect *dest_rect)
{
  SDL_BlitSurface(src_surface, src_rect, engine_screen.surface, dest_rect);
}

/* Create surface */
SDL_Surface *engine_create_surface(Uint32 flags, int w, int h, int alpha)
{
  Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  if(alpha)
    amask = 0x000000ff;
  else
    amask = 0;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  if(alpha)
    amask = 0xff000000;
  else
    amask = 0;
#endif
  return SDL_CreateRGBSurface(flags, w, h, 32, rmask, gmask, bmask, amask);
}
