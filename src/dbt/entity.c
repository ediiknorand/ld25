#include "entity.h"
#include "map.h"
#include "status.h"
#include <stdlib.h>
#include <time.h>

void entity_load()
{
  int i;
  for(i = 1; i < ENTITY_MAX; i++)
    dbt_entity[i].use = 0;
  /* Spawn Tree - the player*/
  entity_spawn(ENTITY_DTREE, 9.0f,7.0f);
}
/* Spawn stones */

void entity_stone_map()
{
  entity_spawn(ENTITY_STONE, 4,3);
  entity_spawn(ENTITY_STONE, MAP_WIDTH-5,3);
  entity_spawn(ENTITY_STONE, 4,MAP_HEIGHT-4);
  entity_spawn(ENTITY_STONE, MAP_WIDTH-5,MAP_HEIGHT-4);
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

void entity_spawn(int type, float x, float y)
{
  int idx;
  if(type == ENTITY_DTREE)
    idx = 0;
  else
    idx = entity_first_index();
  if(idx < 0)
    return;
  dbt_entity[idx].use = 1;
  dbt_entity[idx].x = x;
  dbt_entity[idx].y = y;
  dbt_entity[idx].type = type;

  dbt_entity[idx].sx = status_speed(type);
  dbt_entity[idx].sy = status_speed(type);
  dbt_entity[idx].atk = status_atk(type);
  dbt_entity[idx].maxhp = status_hp(type);
  dbt_entity[idx].hp = dbt_entity[idx].maxhp;
}
