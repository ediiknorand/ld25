#ifndef H_MAP_H
#define H_MAP_H

#include "../engine/engine.h"

#define MAP_TILE_W 32
#define MAP_TILE_H 32
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

typedef struct
{
  char *map;
  char *emap;
  int *amap;
  SDL_Surface *tileset;
} Map;

Map dbt_map;

void map_load();
void map_paths();

void map_render();

int map_index(int x, int y);

#endif
