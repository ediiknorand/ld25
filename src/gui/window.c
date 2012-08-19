#include <SDL/SDL.h>
#include <stdlib.h>
#include <string.h>
#include "window.h"
#include "theme.h"
#include "../engine/render.h"

/* - - - - */
void guiInit()
{
  guiStack.top = NULL;
}

void guiClear()
{
  GUIWindow *w, *aux;

  w = guiStack.top;
  while(w)
  {
    free(w->field);
    aux = w->caller;
    free(w);
    w = aux;
  }
}

/* - - - - */
GUIWindow *guiSummonWindow(char *title, SDL_Rect *wrect, int n_fields, GUITheme *theme)
{
  GUIWindow *w = malloc(sizeof(GUIWindow));

  w->caller = guiStack.top;
  guiStack.top = w;

  memcpy(&(w->wrect), wrect, sizeof(SDL_Rect));
  w->title = title;
  w->field = malloc(n_fields*sizeof(GUIField));
  w->fsize = n_fields;
  w->filled = 0;

  w->theme = theme;

  return w;
}

void guiUnsummonWindow()
{
  GUIWindow *w;

  if(!guiStack.top)
    return;
  w = guiStack.top;
  free(w->field);
  guiStack.top = w->caller;
  free(w);
}

/* - - - - */
void guiAddField(GUIWindow *w, SDL_Rect *frect, SDL_Surface *surface, SDL_Rect *src_rect)
{
  if(w->filled >= w->fsize)
    return;
  if(frect)
    memcpy(&(w->field[w->filled].frect), frect, sizeof(SDL_Rect));
  if(src_rect)
    memcpy(&(w->field[w->filled].src_rect), src_rect, sizeof(SDL_Rect));
  w->field[w->filled].surface = surface;
  (w->filled)++;
}

/* - - - - */
