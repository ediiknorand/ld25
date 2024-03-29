#ifndef H_GUI_CORE_H
#define H_GUI_CORE_H

#include <SDL/SDL.h>
#include "theme.h"

typedef struct
{
  SDL_Rect frect; // dest rect (screen)
  SDL_Rect src_rect; // src rect (field surface)
  SDL_Surface *surface;
} GUIField;

typedef struct _GUIWindow
{
  char *title;
  SDL_Rect wrect;

  GUIField *field;
  Uint16 fsize;
  Uint16 filled;

  struct _GUIWindow *caller;
  GUITheme *theme;
} GUIWindow;

typedef struct
{
  GUIWindow *top;
} GUIStack;

GUIStack guiStack;

/* Functions */
void guiInit();
void guiClear();

GUIWindow *guiSummonWindow(char *title, SDL_Rect *wrect, int n_fields, GUITheme *theme);
void guiUnsummonWindow();

int guiAddField(GUIWindow *win,
                 Sint16 fx, Sint16 fy,
		 SDL_Surface *surface);

int guiAddField2(GUIWindow *win,
                 Sint16 fx, Sint16 fy, 
		 SDL_Surface *surface,
		 Sint16 sx, Sint16 sy, Uint16 w, Uint16 h);

#endif
