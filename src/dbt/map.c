#include "../engine/engine.h"
#include "map.h"

void map_load()
{
  int i,j;
  dbt_map.map = malloc(sizeof(char)*MAP_WIDTH*MAP_HEIGHT);
  dbt_map.emap = malloc(sizeof(char)*MAP_WIDTH*MAP_HEIGHT);
  dbt_map.amap = malloc(sizeof(int)*MAP_WIDTH*MAP_HEIGHT);

  for(i = 0; i < MAP_WIDTH; i++)
    for(j = 0; j < MAP_HEIGHT; j++)
      dbt_map.map[map_index(i,j)] = 0;

  for(i = 0; i < MAP_WIDTH; i++)
    for(j = 0; j < MAP_HEIGHT; j++)
      dbt_map.emap[map_index(i,j)] = -1;

  for(i = 0; i < MAP_WIDTH; i++)
    for(j = 0; j < MAP_HEIGHT; j++)
      dbt_map.amap[map_index(i,j)] = 0;

  map_paths();

  dbt_map.tileset = engine_load_image("resource/tile.png");
}

void map_paths()
{
  int i,j;
  
  for(i = 0; i < MAP_WIDTH; i++)
    dbt_map.map[map_index(i,MAP_HEIGHT/2)] = 2;
  for(j = MAP_HEIGHT/4; j <= 3*MAP_HEIGHT/4; j++)
    dbt_map.map[map_index(MAP_WIDTH/2-1,j)] = 2;
  for(i = MAP_WIDTH/3; i <= 2*MAP_WIDTH/3; i++ )
  {
    dbt_map.map[map_index(i,MAP_HEIGHT/4)] = 2;
    dbt_map.map[map_index(i,3*MAP_HEIGHT/4)] = 2;
  }
  for(j = 0; j <= MAP_HEIGHT/4; j++)
  {
    dbt_map.map[map_index(MAP_WIDTH/3,j)] = 2;
    dbt_map.map[map_index(2*MAP_WIDTH/3,j)] = 2;
  }
  for(j = 3*MAP_HEIGHT/4; j < MAP_HEIGHT; j++)
  {
    dbt_map.map[map_index(MAP_WIDTH/3,j)] = 2;
    dbt_map.map[map_index(2*MAP_WIDTH/3,j)] = 2;
  }
  dbt_map.map[map_index(MAP_WIDTH/2-1,MAP_HEIGHT/2)] = 3;
}

void map_render()
{
  int i,j;
  SDL_Rect dest, src;
  src.w = 32; src.h = 32;
  for(i = 0; i < MAP_WIDTH; i++)
    for(j = 0; j < MAP_HEIGHT; j++)
    {
      dest.x = i*MAP_TILE_W;
      dest.y = j*MAP_TILE_H;
      if(!(dbt_map.map[map_index(i,j)]&0x1))
        src.x = 0;
      else
        src.x = MAP_TILE_W;
      if(!(dbt_map.map[map_index(i,j)]&0x2))
        src.y = 0;
      else
        src.y = MAP_TILE_H;
      engine_render_surface(dbt_map.tileset, &src, &dest);
    }
}


int map_index(int x, int y)
{
  return x+y*MAP_WIDTH;
}
