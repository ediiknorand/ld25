#include "../engine/engine.h"
#include "map.h"
#include "input.h"
#include "main_scene.h"
#include "entity.h"
#include "render_entity.h"
#include "refresh_entity.h"
#include "player.h"
#include "wave.h"
#include "attack.h"

void *dbt_load(void *scene)
{
  map_load();
  input_load();
  entity_load();
  render_load();
  entity_stone_map();
  player_load();
  wave_load();

  dbt_map.map[map_index((int)dbt_entity[0].x,(int)dbt_entity[0].y)] = 3;

  return NULL;
}

void *dbt_unload(void *scene)
{
  return NULL;
}

int dbt_refresh(void *scene, Uint8 *keyboard, double delta)
{
  int running = input_refresh(keyboard);
  player_input();
  attack_refresh();
  player_refresh(delta);
  refresh_entity(delta);
  wave_refresh(delta);
  attack_damage();

  if(dbt_entity[0].hp <= 0)
    running = 0; //game over

  return running;
}

void dbt_render(void *scene, double delta)
{
  map_render();
  player_render_square();
  render_entity();
  player_render();
  wave_render();
}
