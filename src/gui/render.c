#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "window.h"
#include "theme.h"
#include "../engine/core.h"

void guiRenderWinRect(GUIWindow *w)
{
  SDL_FillRect(engine_screen.surface, w->wrect, w->theme->bg_color);
}

void guiRenderWindow(GUIWindow *w)
{
  int i;
  guiRenderWinRect(w);
  for(i = 0; i < w->filled; i++)
    guiRenderField(w->field[i], w->theme);
}

void guiRenderField(GUIField *field, GUITheme *theme)
{
  SDL_Surface *s;

  switch(field->ctype)
  {
  case 0: /* Content is a surface */
    SDL_BlitSurface(field->content.icon->surface, field->content.icon->src_rect, engine_screen.surface, field->frect);
    break;
  case 1: /* Content is a text */
    s = TTF_RenderUTF8_Solid(theme->font, field->content.text, &(theme->text_color));
    SDL_BlitSurface(s, NULL, engine_screen.surface, field->frect);
    SDL_FreeSurface(s);
    break;
  }
}
