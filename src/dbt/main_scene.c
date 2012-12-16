#include "../engine/engine.h"
#include "map.h"
#include "input.h"
#include "main_scene.h"
#include "entity.h"
#include "render_entity.h"
#include "refresh_entity.h"

void *dbt_load(void *scene)
{
  map_load();
  input_load();
  entity_load();
  render_load();
  entity_stone_map();


  entity_spawn_soldier(0, MAP_HEIGHT/2);
  entity_spawn_soldier(MAP_WIDTH-1, MAP_HEIGHT/2);
  entity_spawn_archer(0, MAP_HEIGHT/2+1);
  entity_spawn_soldier(0, MAP_HEIGHT/2-1);
  entity_spawn_archer(MAP_WIDTH-1, MAP_HEIGHT/2+1);
  entity_spawn_soldier(MAP_WIDTH-1, MAP_HEIGHT/2-1);
  entity_spawn_soldier(MAP_WIDTH/3, 0);
  entity_spawn_bunny(8,5);
  entity_spawn_bunny(13,7);
  dbt_map.map[map_index(MAP_WIDTH/2-1,MAP_HEIGHT/2-1)] = 3;

  return NULL;
}

void *dbt_unload(void *scene)
{
  return NULL;
}

int dbt_refresh(void *scene, Uint8 *keyboard, double delta)
{
  int running = input_refresh(keyboard);
  refresh_entity(delta);

  return running;
}

void dbt_render(void *scene, double delta)
{
  map_render();
  render_entity();
}
