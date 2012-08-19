#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "text.h"

/* - - - */
void engine_init_text()
{
  if(TTF_Init()==-1)
  {
    fprintf(stderr,"TTF Error: %s\n",TTF_GetError());
    exit(1);
  }
}

void engine_quit_text()
{
  TTF_Quit();
}

/* - - - */
TTF_Font *engine_load_font(char *filename, int ptsize)
{
  TTF_Font *font = TTF_OpenFont(filename, ptsize);
  if(!font)
  {
    fprintf(stderr, "TTF Error: %s\n",TTF_GetError());
    exit(1);
  }
  TTF_SetFontOutline(font, 0);
  return font;
}

void engine_unload_font(TTF_Font *font)
{
  TTF_CloseFont(font);
}

/* - - - */
void engine_config_style(TTF_Font *font, int style)
{
  TTF_SetFontStyle(font, style);
}

/* - - - */
SDL_Surface *engine_render_text(TTF_Font *font, char *text, SDL_Color *fg)
{
  SDL_Surface *aux = TTF_RenderText_Solid(font, text, *fg);
  SDL_Surface *text_surface = SDL_DisplayFormatAlpha(aux);

  SDL_FreeSurface(aux);
  return text_surface;
}
