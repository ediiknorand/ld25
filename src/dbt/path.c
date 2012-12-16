#include "path.h"
#include "map.h"
#include "entity.h"
#include <math.h>

void path_enemy(int idx)
{
  if((int)dbt_entity[idx].x < (int)dbt_entity[0].x)
    dbt_entity[idx].sx = 0.6f;
  else 
  {
    if((int)dbt_entity[idx].x > (int)dbt_entity[0].x)
      dbt_entity[idx].sx = - 0.6f;
    else
      dbt_entity[idx].sx = 0;
  }

  if((int)dbt_entity[idx].y < (int)dbt_entity[0].y)
    dbt_entity[idx].sy = 0.6f;
  else 
  {
    if((int)dbt_entity[idx].y > (int)dbt_entity[0].y)
      dbt_entity[idx].sy = - 0.6f;
    else
      dbt_entity[idx].sy = 0;
  }
}

int walkable_tile_x(int idx,double delta)
{
  int dx = floorf(dbt_entity[idx].x+dbt_entity[idx].sx*delta);
  int dy = floorf(dbt_entity[idx].y);

  if(dx < 0 || dx >= MAP_WIDTH)
    return 0;

  if(dx == (int)dbt_entity[idx].x)
    return 1;

  if(dbt_map.emap[map_index(dx,dy)] != -1)
    return 0;
  return 1;
}

int walkable_tile_y(int idx,double delta)
{
  int dx = floorf(dbt_entity[idx].x);
  int dy = floorf(dbt_entity[idx].y+dbt_entity[idx].sy*delta);

  if(dy < 0 || dy >= MAP_HEIGHT)
    return 0;

  if(dy == (int)dbt_entity[idx].y)
    return 1;

  if(dbt_map.emap[map_index(dx,dy)] != -1)
    return 0;
  return 1;
}

void path_travel(int idx, double delta)
{
  switch(dbt_entity[idx].type)
  {
  case ENTITY_SOLDIER:
  case ENTITY_ARCHER:
    if(dbt_entity[idx].walking)
    {
      if(path_detect_ally(idx))
        dbt_entity[idx].walking = 0;
      else
      {
        path_enemy(idx);
	if(walkable_tile_x(idx, delta))
	  dbt_entity[idx].x += dbt_entity[idx].sx*delta;
	if(walkable_tile_y(idx, delta))
	  dbt_entity[idx].y += dbt_entity[idx].sy*delta;
      }
    } else if(!path_detect_ally(idx))
    {
      dbt_entity[idx].walking = 1;
    }
    break;
  case ENTITY_BUNNY:
    if(!dbt_entity[idx].walking)
    {
      if(path_detect_enemy(idx))
      {
        dbt_entity[idx].walking = 1;
	dbt_entity[idx].x += dbt_entity[idx].sx*delta;
	dbt_entity[idx].y += dbt_entity[idx].sy*delta;
      }
    }
    else
    {
      if(!path_detect_enemy(idx))
        dbt_entity[idx].walking = 0;
      else
	dbt_entity[idx].x += dbt_entity[idx].sx*delta;
	dbt_entity[idx].y += dbt_entity[idx].sy*delta;
    }
  }
}

int path_detect_ally(int idx)
{
  int i,j,k;
  int dx = (int)ceilf(dbt_entity[idx].x);
  int dy = (int)ceilf(dbt_entity[idx].y);

  k = 2;

  for(i = (dx-k<0?0:dx-k); i < (dx+k>=MAP_WIDTH?MAP_WIDTH-1:dx+k); i++)
    for(j = (dy-k<0?0:dy-k); j < (dy+k>=MAP_HEIGHT?MAP_HEIGHT-1:dy+k); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_BUNNY)
        return 1;
  k = 1;
  for(i = (dx-k<0?0:dx-k); i < (dx+k>=MAP_WIDTH?MAP_WIDTH-1:dx+k); i++)
    for(j = (dy-k<0?0:dy-k); j < (dy+k>=MAP_HEIGHT?MAP_HEIGHT-1:dy+k); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_DTREE)
        return 1;
  return 0;
}

int path_detect_enemy(int idx)
{
  int i,j,k;
  int dx = (int)floorf(dbt_entity[idx].x);
  int dy = (int)floorf(dbt_entity[idx].y);

  k = 2;

  for(i = (dx-k<0?0:dx-k); i < (dx+k>=MAP_WIDTH?MAP_WIDTH-1:dx+k); i++)
    for(j = (dy-k<0?0:dy-k); j < (dy+k>=MAP_HEIGHT?MAP_HEIGHT-1:dy+k); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_SOLDIER || dbt_map.emap[map_index(i,j)] == ENTITY_ARCHER)
      {
        dbt_entity[idx].sx = (i - dbt_entity[idx].x)/1.0f;
        dbt_entity[idx].sy = (j - dbt_entity[idx].y)/1.0f;
        return 1;
      }
  return 0;
}
