#include "entity.h"
#include "path.h"
#include "map.h"
#include "attack.h"
#include "refresh_entity.h"
#include <math.h>

int markable_type(int idx)
{
  switch(dbt_entity[idx].type)
  {
  case ENTITY_STONE:
  case ENTITY_BUNNY:
  case ENTITY_SOLDIER:
  case ENTITY_ARCHER:
  case ENTITY_DTREE:
    if((dbt_entity[idx].x >= 0) && (dbt_entity[idx].x < MAP_WIDTH) && (dbt_entity[idx].y >= 0) && (dbt_entity[idx].y < MAP_HEIGHT))
      return 1;
  }
  return 0;
}

void refresh_entity(double delta)
{
  int i,j;
  for(i = 0; i < MAP_WIDTH; i++)
    for(j = 0; j < MAP_HEIGHT; j++)
      dbt_map.emap[map_index(i,j)] = -1;

  for(i = 0; i < ENTITY_MAX; i++)
    if(dbt_entity[i].use && markable_type(i))
      dbt_map.emap[map_index((int)roundf(dbt_entity[i].x), (int)roundf(dbt_entity[i].y))] = dbt_entity[i].type;



  for(i = 0; i < ENTITY_MAX; i++)
    if(dbt_entity[i].use)
      switch(dbt_entity[i].type)
      {
      case ENTITY_BUNNY:
      case ENTITY_SOLDIER:
      case ENTITY_ARCHER:
        path_travel(i, delta);
	attack_unit(i, delta);
        break;
      }
}
