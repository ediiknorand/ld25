#include "path.h"
#include "map.h"
#include "entity.h"
#include <math.h>

void path_refresh(int idx, int cx, int cy, double delta)
{
  int tx,ty;

  dbt_entity[idx].x += dbt_entity[idx].sx*delta*cx;
  dbt_entity[idx].y += dbt_entity[idx].sy*delta*cy;
  tx = (int)roundf(dbt_entity[idx].x);
  ty = (int)roundf(dbt_entity[idx].y);
  dbt_map.emap[map_index(tx,ty)] = dbt_entity[idx].type;
}

void path_follow(int idx, float x, float y, double delta)
{
  int dx = (int)roundf(dbt_entity[idx].x);
  int dy = (int)roundf(dbt_entity[idx].y);
  int cx = 0;
  int cy = 0;

  if(dx < x) cx = 1;
  if(dx > x) cx = -1;
  if(dy < y) cy = 1;
  if(dy > y) cy = -1;

  if(dbt_map.emap[map_index(dx+cx,dy+cy)] >= 0 && (cx && cy))
  {
    if(dbt_map.emap[map_index(dx,dy+cy)] < 0)
      cx = 0;
    else if(dbt_map.emap[map_index(dx+cx,dy)] < 0)
      cy = 0;
    else
    {
      cx = 0; cy = 0;
    }
  }
  if(dbt_map.emap[map_index(dx+cx,dy+cy)] >= 0 && ((cx&&!cy) || (cy&&!cx)))
  {
    cx = 0; cy = 0;
  }
  path_refresh(idx, cx,cy, delta);
}

/* = = = = = = = = = = = = = = = = */
void path_travel_enemy(int idx, double delta)
{
  float x,y;
  if(path_detect_ally(idx,&x,&y))
    path_follow(idx, x,y, delta);
  else
    path_follow(idx, floorf(dbt_entity[0].x), floorf(dbt_entity[0].y), delta);
}

void path_travel_ally(int idx, double delta)
{
  float x,y;
  if(path_detect_enemy(idx,&x,&y))
    path_follow(idx, x,y, delta);
}

void path_travel(int idx, double delta)
{
  switch(dbt_entity[idx].type)
  {
    case ENTITY_SOLDIER:
    case ENTITY_ARCHER:
      path_travel_enemy(idx, delta);
      break;
    case ENTITY_BUNNY:
      path_travel_ally(idx, delta);
      break;
  }
}

/* = = = =  ==  = = = = = = = = = = =  */
int path_detect_ally(int idx, float *x, float *y)
{
  int i,j;
  int dx = (int)roundf(dbt_entity[idx].x);
  int dy = (int)roundf(dbt_entity[idx].y);

  for(i = (dx-2<0?0:dx-2); i <= (dx+2>=MAP_WIDTH?MAP_WIDTH-1:dx+2); i++)
    for(j = (dy-2<0?0:dy-2); j <= (dy+2>=MAP_HEIGHT?MAP_HEIGHT-1:dy+2); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_BUNNY)
      {
        *x = i; *y = j;
	return 1;
      }
   return 0;
}

int path_detect_enemy(int idx, float *x, float *y)
{
  int i,j;
  int dx = (int)roundf(dbt_entity[idx].x);
  int dy = (int)roundf(dbt_entity[idx].y);

  for(i = (dx-2<0?0:dx-2); i <= (dx+2>=MAP_WIDTH?MAP_WIDTH-1:dx+2); i++)
    for(j = (dy-2<0?0:dy-2); j <= (dy+2>=MAP_HEIGHT?MAP_HEIGHT-1:dy+2); j++)
      if(dbt_map.emap[map_index(i,j)] == ENTITY_SOLDIER || dbt_map.emap[map_index(i,j)] == ENTITY_ARCHER)
      {
        *x = i; *y = j;
	return 1;
      }
   return 0;
}
