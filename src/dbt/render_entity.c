#include "render_entity.h"
#include "entity.h"
#include "map.h"
#include "../engine/engine.h"
#include <math.h>

void render_load()
{
  surface_tree = engine_load_image("resource/tree.png");
  surface_stone = engine_load_image("resource/stone.png");
  surface_bunny = engine_load_image("resource/bunny.png");
  surface_soldier = engine_load_image("resource/soldier.png");
  surface_archer = engine_load_image("resource/archer.png");
  //surface_fruit = engine_load_image("resource/fruit.png");
  //surface_arrow = engine_load_image("resource/arrow.png");
}

void render_entity()
{
  int i;
  for(i = 0; i < ENTITY_MAX; i++)
    if(dbt_entity[i].use)
      switch(dbt_entity[i].type)
      {
      case ENTITY_STONE: render_stone(i); break;
      case ENTITY_BUNNY: render_bunny(i); break;
      case ENTITY_SOLDIER: render_soldier(i); break;
      case ENTITY_ARCHER: render_archer(i); break;
      case ENTITY_FRUIT: render_fruit(i); break;
      case ENTITY_ARROW: render_arrow(i); break;
      }
  render_tree();
}

void render_tree()
{
  SDL_Rect dest;

  dest.x = (int)(dbt_entity[0].x*MAP_TILE_W-8);
  dest.y = (int)(dbt_entity[0].y*MAP_TILE_H-48);

  engine_render_surface(surface_tree, NULL, &dest);
}

void render_stone(int i)
{
  SDL_Rect dest;
  dest.x = (int)floorf(dbt_entity[i].x)*MAP_TILE_W;
  dest.y = (int)floorf(dbt_entity[i].y)*MAP_TILE_H;

  engine_render_surface(surface_stone, NULL, &dest);
}

void render_bunny(int i)
{
  SDL_Rect dest;
  dest.x = (int)(dbt_entity[i].x*MAP_TILE_W);
  dest.y = (int)(dbt_entity[i].y*MAP_TILE_H);
  engine_render_surface(surface_bunny, NULL, &dest);

  dest.y -= 8;
  dest.w = (int)32*((float)dbt_entity[i].hp/dbt_entity[i].maxhp);
  dest.h = 4;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));
}

void render_soldier(int i)
{
  SDL_Rect dest;
  dest.x = (int)(dbt_entity[i].x*MAP_TILE_W);
  dest.y = (int)(dbt_entity[i].y*MAP_TILE_H);

  engine_render_surface(surface_soldier, NULL, &dest);

  dest.y -= 8;
  dest.w = (int)32*((float)dbt_entity[i].hp/dbt_entity[i].maxhp);
  dest.h = 4;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 0, 0, 255));
}

void render_archer(int i)
{
  SDL_Rect dest;
  dest.x = (int)(dbt_entity[i].x*MAP_TILE_W);
  dest.y = (int)(dbt_entity[i].y*MAP_TILE_H);

  engine_render_surface(surface_archer, NULL, &dest);

  dest.y -= 8;
  dest.w = (int)32*((float)dbt_entity[i].hp/dbt_entity[i].maxhp);
  dest.h = 4;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 0, 0, 255));
}

void render_fruit(int i)
{
  SDL_Rect dest;
  dest.x = (int)floorf(dbt_entity[i].x)*MAP_TILE_W;
  dest.y = (int)floorf(dbt_entity[i].y)*MAP_TILE_H;

  engine_render_surface(surface_fruit, NULL, &dest);
}

void render_arrow(int i)
{
  SDL_Rect dest;
  dest.x = (int)floorf(dbt_entity[i].x)*MAP_TILE_W;
  dest.y = (int)floorf(dbt_entity[i].y)*MAP_TILE_H;

  engine_render_surface(surface_arrow, NULL, &dest);
}

