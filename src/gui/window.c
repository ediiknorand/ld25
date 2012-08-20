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
int guiAddField(GUIWindow *win, Sint16 fx, Sint16 fy, SDL_Surface *surface)
{
  if(!(win && surface) || (win->filled >= win->fsize))
    return -1;
  win->field[win->filled].frect.x = fx;
  win->field[win->filled].frect.y = fy;
  win->field[win->filled].src_rect.x = 0;
  win->field[win->filled].src_rect.y = 0;
  win->field[win->filled].src_rect.w = surface->w;
  win->field[win->filled].src_rect.h = surface->h;
  win->field[win->filled].surface = surface;
  (win->filled)++;
  return win->filled -1;
}


int guiAddField2(GUIWindow *win,
                  Sint16 fx, Sint16 fy, 
		  SDL_Surface *surface,
		  Sint16 sx, Sint16 sy, Uint16 w, Uint16 h)
{
  if(!(win && surface) || (win->filled >= win->fsize))
    return -1;
  win->field[win->filled].frect.x = fx;
  win->field[win->filled].frect.y = fy;
  win->field[win->filled].src_rect.x = sx;
  win->field[win->filled].src_rect.y = sy;
  win->field[win->filled].src_rect.w = w;
  win->field[win->filled].src_rect.h = h;
  win->field[win->filled].surface = surface;
  (win->filled)++;
  return win->filled -1;
}

/* - - - - */
