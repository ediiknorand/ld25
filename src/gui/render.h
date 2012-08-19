#ifndef H_GUI_RENDER_H
#define H_GUI_RENDER_H

#include <SDL/SDL.h>
#include "window.h"

void guiRenderWinRect(GUIWindow *w);
void guiRenderWindow(GUIWindow *w);

void guiRenderField(GUIField *field);

#endif
