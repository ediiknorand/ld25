#include "entity.h"
#include "map.h"
#include "attack.h"
#include <math.h>


void attack_refresh()
{
  int i,j;

  for(i = 0; i < MAP_WIDTH; i++)
    for(j = 0; j < MAP_HEIGHT; j++)
      dbt_map.amap[map_index(i,j)] = 0;
}

void attack_unit(int idx, double delta)
{
  attack_cooldown += delta;
  if(attack_cooldown < 1.0f)
    return;
  attack_cooldown -= 1.0f;
  switch(dbt_entity[idx].type)
  {
  case ENTITY_SOLDIER:
    attack_ally(idx,1);
    break;
  case ENTITY_ARCHER:
    attack_ally(idx,3);
    break;
  case ENTITY_BUNNY:
    attack_enemy(idx,1);
    break;
  }
}

void attack_ally(int idx, int rng)
{
  int i,j;
  int dx = (int)roundf(dbt_entity[idx].x);
  int dy = (int)roundf(dbt_entity[idx].y);

  for(i = (dx-rng<0?0:dx-rng); i <= (dx+rng>MAP_WIDTH?MAP_WIDTH-1:dx+rng); i++)
    for(j = (dy-rng<0?0:dy-rng); j <= (dy+rng>MAP_HEIGHT?MAP_HEIGHT-1:dy+rng); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_BUNNY || dbt_map.emap[map_index(i,j)] == ENTITY_DTREE)
        dbt_map.amap[map_index(i,j)] += dbt_entity[idx].atk;
}

void attack_enemy(int idx, int rng)
{
  int i,j;
  int dx = (int)roundf(dbt_entity[idx].x);
  int dy = (int)roundf(dbt_entity[idx].y);

  for(i = (dx-rng<0?0:dx-rng); i <= (dx+rng>MAP_WIDTH?MAP_WIDTH-1:dx+rng); i++)
    for(j = (dy-rng<0?0:dy-rng); j <= (dy+rng>MAP_HEIGHT?MAP_HEIGHT-1:dy+rng); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_SOLDIER || dbt_map.emap[map_index(i,j)] == ENTITY_ARCHER)
        dbt_map.amap[map_index(i,j)] += dbt_entity[idx].atk;
}

void attack_damage()
{
  int i;
  int dx,dy;
  char tile;
  for(i = 0; i < ENTITY_MAX; i++)
    if(dbt_entity[i].use)
    {
      dx = (int)roundf(dbt_entity[i].x);
      dy = (int)roundf(dbt_entity[i].y);
      if(dx >= 0 && dx < MAP_WIDTH && dy >= 0 && dy < MAP_HEIGHT)
        dbt_entity[i].hp -= dbt_map.amap[map_index(dx,dy)];
      if(dbt_entity[i].hp <= 0)
      {
        dbt_entity[i].use = 0;
	if(dbt_entity[i].type == ENTITY_SOLDIER || dbt_entity[i].type == ENTITY_ARCHER)
	{
	  tile =  dbt_map.map[map_index(dx,dy)];
	  dbt_map.map[map_index(dx,dy)] = (!(tile%2)?tile+1:tile);
	}
      }
    }
}
