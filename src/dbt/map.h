#ifndef H_MAP_H
#define H_MAP_H

#include "../engine/engine.h"

#define MAP_TILE_W 32
#define MAP_TILE_H 32
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

#define map_index(x,y) (x+y*MAP_WIDTH)

typedef struct
{
  char *map;
  char *emap;
  SDL_Surface *tileset;
} Map;

Map dbt_map;

void map_load();
void map_paths();

void map_render();

#endif
