#include "entity.h"
#include "map.h"
#include <stdlib.h>
#include <time.h>

void entity_load()
{
  int i;
  for(i = 1; i < ENTITY_MAX; i++)
    dbt_entity[i].use = 0;
  /* Spawn Tree - the player*/
  dbt_entity[0].use = 1;
  dbt_entity[0].x = MAP_WIDTH/2.0f - 1;
  dbt_entity[0].y = MAP_HEIGHT/2.0f;
  dbt_entity[0].sx = 0.0f;
  dbt_entity[0].sy = 0.0f;
  dbt_entity[0].walking = 0;
  dbt_entity[0].type = ENTITY_DTREE;
}
/* Spawn stones */

void entity_stone_map()
{
  int i;

  for(i = 0; i < 4; i++)
  {
    entity_spawn_stone(i, 4);
    entity_spawn_stone(MAP_WIDTH-i-1, 4);
    entity_spawn_stone(i, MAP_HEIGHT-5);
    entity_spawn_stone(MAP_WIDTH-i-1, MAP_HEIGHT-5);

    entity_spawn_stone(3, i);
    entity_spawn_stone(MAP_WIDTH-4, i);
    entity_spawn_stone(3, MAP_HEIGHT-i-1);
    entity_spawn_stone(MAP_WIDTH-4, MAP_HEIGHT-i-1);
  }
}

/* Spawn */
int entity_first_index()
{
  int i;
  for(i = 1; i < ENTITY_MAX; i++)
    if(!(dbt_entity[i].use))
      return i;
  return -1;
}

void entity_spawn_stone(float x, float y)
{
  int idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].sx = 0.0f;
  dbt_entity[idx].sy = 0.0f;
  dbt_entity[idx].walking = 1;
  dbt_entity[idx].type = ENTITY_STONE;
}

void entity_spawn_bunny(float x, float y)
{
  int idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].sx = 0.5f;
  dbt_entity[idx].sy = 0.5f;
  dbt_entity[idx].walking = 1;
  dbt_entity[idx].type = ENTITY_BUNNY;
}

void entity_spawn_soldier(float x, float y)
{
  int idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].sx = 0.0f;
  dbt_entity[idx].sy = 0.0f;
  dbt_entity[idx].walking = 1;
  dbt_entity[idx].type = ENTITY_SOLDIER;
}

void entity_spawn_archer(float x, float y)
{
  int idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].sx = 0.2f;
  dbt_entity[idx].sy = 0.2f;
  dbt_entity[idx].walking = 1;
  dbt_entity[idx].type = ENTITY_ARCHER;
}

void entity_spawn_fruit(float x, float y)
{
  int idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].sx = 1.5f;
  dbt_entity[idx].sy = 1.5f;
  dbt_entity[idx].walking = 1;
  dbt_entity[idx].type = ENTITY_FRUIT;
}

void entity_spawn_arrow(float x, float y)
{
  int idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].sx = 2.0f;
  dbt_entity[idx].sy = 2.0f;
  dbt_entity[idx].walking = 1;
  dbt_entity[idx].type = ENTITY_ARROW;
}

