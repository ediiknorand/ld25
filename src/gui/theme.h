#ifndef H_GUI_THEME_H
#define H_GUI_THEME_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
  Uint32 bg_color;
  SDL_Color text_color;
  TTF_Font *font;
} GUITheme;

GUITheme *guiCreateTheme(Uint32 bg, SDL_Color *text, char *font_filename, int ptsize);
void guiDestroyTheme(GUITheme *theme);

#endif
