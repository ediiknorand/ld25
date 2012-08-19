#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "theme.h"

GUITheme *guiCreateTheme(Uint32 bg, SDL_Color *text, char *font_filename, int ptsize)
{
  GUITheme *theme = malloc(sizeof(GUITheme));
  if(!theme)
  {
    fprintf(stderr, "GUI-theme: Cannot create a theme\n");
    exit(1);
  }
  theme->bg_color = bg;
  memcpy(&(theme->text_color), text, sizeof(SDL_Color));
  theme->font = TTF_OpenFont(font_filename, ptsize);
  if(!(theme->font))
  {
    fprintf(stderr,"TTF Error: %s\n",TTF_GetError());
    exit(1);
  }
  return theme;
}

void guiDestroyTheme(GUITheme *theme)
{
  TTF_CloseFont(theme->font);
  free(theme);
}

