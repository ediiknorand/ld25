#ifndef H_INPUT_H
#define H_INPUT_H

#include "../engine/engine.h"

typedef struct
{
  char skill1; SDLKey key1;
  char skill2; SDLKey key2;
  char skill3; SDLKey key3;
  char skill4; SDLKey key4;
  SDLKey keyq;

  Uint8 mouse;
  int mouse_x;
  int mouse_y;
  char mouse_left;
} Keystate;

Keystate dbt_input;

void input_load();
int input_refresh(Uint8 *keyboard);

#endif
