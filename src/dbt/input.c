#include "../engine/engine.h"
#include "input.h"

/* debug */
#include "entity.h"
#include "map.h"

void input_load()
{
  dbt_input.key1 = SDLK_a;
  dbt_input.key2 = SDLK_s;
  dbt_input.key3 = SDLK_d;
  dbt_input.key4 = SDLK_f;
  dbt_input.keyq = SDLK_q;

  dbt_input.skill1 = 0;
  dbt_input.skill2 = 0;
  dbt_input.skill3 = 0;
  dbt_input.skill4 = 0;
  dbt_input.mouse_left = 0;
}

int input_refresh(Uint8 *keyboard)
{
  /* key 1 locker */
  if(dbt_input.skill1)
    dbt_input.skill1 = 0;
  else
  {
    if(keyboard[dbt_input.key1])
      dbt_input.skill1 = 1;
  }
  /* key 2 locker */
  if(dbt_input.skill2)
    dbt_input.skill2 = 0;
  else
  {
    if(keyboard[dbt_input.key2])
      dbt_input.skill2 = 1;
  }
  /* key 3 locker */
  if(dbt_input.skill3)
    dbt_input.skill3 = 0;
  else
  {
    if(keyboard[dbt_input.key3])
      dbt_input.skill3 = 1;
  }
  /* key 4 locker */
  if(dbt_input.skill4)
    dbt_input.skill4 = 0;
  else
  {
    if(keyboard[dbt_input.key4])
      dbt_input.skill4 = 1;
  }
  /* mouse input */
  dbt_input.mouse = SDL_GetMouseState(&(dbt_input.mouse_x), &(dbt_input.mouse_y));
  if(dbt_input.mouse_left)
    dbt_input.mouse_left = 0;
  else
  {
    if(dbt_input.mouse&SDL_BUTTON(1))
      dbt_input.mouse_left = 1;
  }
  /* quit key */
  if(keyboard[dbt_input.keyq])
    return 0;
  return 1;
}
