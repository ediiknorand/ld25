#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "window.h"
#include "theme.h"
#include "render.h"
#include "../engine/core.h"

void guiRenderWinRect(GUIWindow *w)
{
  SDL_FillRect(engine_screen.surface, &(w->wrect), w->theme->bg_color);
}

void guiRenderWindow(GUIWindow *w)
{
  int i;
  guiRenderWinRect(w);
  for(i = 0; i < w->filled; i++)
    guiRenderField(&(w->field[i]));
}

void guiRenderField(GUIField *field)
{
  SDL_BlitSurface(field->surface, &(field->src_rect), engine_screen.surface, &(field->frect));
}
