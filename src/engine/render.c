#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "engine-render.h"
#include "engine-core.h"

/* Init Render */
void engine_render_init(int flags)
{
  int initted=IMG_Init(flags);
  if((initted & flags) != flags)
  {
    fprintf(stderr, "Error: %s.\n", IMG_GetError());
    exit(1);
  }
}

/* Quit Render */
void engine_render_quit()
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
void engine_render_image(SDL_Surface *src_surface, SDL_Rect *src_rect, SDL_Rect *dest_rect)
{
  SDL_BlitSurface(src_surface, src_rect, engine_screen.surface, dest_rect);
}
