#include "player.h"
#include "input.h"
#include "entity.h"
#include "map.h"
#include "../engine/engine.h"

void player_load()
{
  player_cooldown = 10.0f;
  player_hud_skill = engine_load_image("resource/skill.png");
  player_skill = PLAYER_SKILL0;
}

void player_input()
{
  if(dbt_input.skill1)
    player_skill = PLAYER_SKILL1;
  if(dbt_input.skill2)
    player_skill = PLAYER_SKILL2;
  if(dbt_input.skill3)
    player_skill = PLAYER_SKILL3;
  if(dbt_input.skill4)
    player_skill = PLAYER_SKILL4;
}

void player_refresh(double delta)
{
  int dx = (int)(float)dbt_input.mouse_x/MAP_TILE_W;
  int dy = (int)(float)dbt_input.mouse_y/MAP_TILE_H;

  player_cooldown += delta;

  if(player_cooldown < 10.0f)
    return;
  if(player_cooldown >= 10.0f)
    player_cooldown = 10.0f;

  if(dx < 0 || dx >= MAP_WIDTH || dy < 0 || dy >= MAP_HEIGHT)
    return;

  if(dbt_input.mouse_left && player_skill)
  {
    switch(player_skill)
    {
    case PLAYER_SKILL1:
      if(dbt_map.emap[map_index(dx,dy)] < 0)
        entity_spawn(ENTITY_BUNNY, dx, dy);
      else
      {
        player_cooldown = 10.0f;
	return;
      }
      break;
    case PLAYER_SKILL2:
      if(dbt_map.emap[map_index(dx,dy)] == ENTITY_SOLDIER || dbt_map.emap[map_index(dx,dy)] == ENTITY_ARCHER)
        dbt_map.amap[map_index(dx,dy)] += 200;
      else
      {
        player_cooldown = 10.0f;
	return;
      }
    }
    player_skill = PLAYER_SKILL0;
    player_cooldown = 0.0f;
  }
}

void player_render_square()
{
  SDL_Rect dest;
  int dx = (int)(float)dbt_input.mouse_x/MAP_TILE_W;
  int dy = (int)(float)dbt_input.mouse_y/MAP_TILE_H;

  dest.x = dx*MAP_TILE_W;
  dest.y = dy*MAP_TILE_H;
  dest.w = 1;
  dest.h = MAP_TILE_H;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

  dest.x = dx*MAP_TILE_W;
  dest.y = dy*MAP_TILE_H;
  dest.w = MAP_TILE_W;
  dest.h = 1;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

  dest.x = (dx+1)*MAP_TILE_W;
  dest.y = (dy)*MAP_TILE_H;
  dest.w = 1;
  dest.h = MAP_TILE_H;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

  dest.x = dx*MAP_TILE_W;
  dest.y = (dy+1)*MAP_TILE_H;
  dest.w = MAP_TILE_W;
  dest.h = 1;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

}

void player_sel_skill(int x)
{
  SDL_Rect dest;
  int dx = x;
  int dy = 0;

  dest.x = dx*MAP_TILE_W;
  dest.y = dy*MAP_TILE_H;
  dest.w = 1;
  dest.h = MAP_TILE_H;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

  dest.x = dx*MAP_TILE_W;
  dest.y = dy*MAP_TILE_H;
  dest.w = MAP_TILE_W;
  dest.h = 1;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

  dest.x = (dx+1)*MAP_TILE_W;
  dest.y = (dy)*MAP_TILE_H;
  dest.w = 1;
  dest.h = MAP_TILE_H;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

  dest.x = dx*MAP_TILE_W;
  dest.y = (dy+1)*MAP_TILE_H;
  dest.w = MAP_TILE_W;
  dest.h = 1;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 255, 0, 0));

}

void player_render()
{
  SDL_Rect dest, src;
  dest.x = 0;
  dest.y = 0;
  src.y = 0;
  src.w = 64;
  src.h = 32;
  if(player_cooldown < 10.0f)
    src.x = 64;
  else
    src.x = 0;
  engine_render_surface(player_hud_skill, &src, &dest);

  dest.x = 64;
  dest.y = 10;
  dest.h = 6;
  dest.w = (int)(float)dbt_entity[0].hp*(640-64)/dbt_entity[0].maxhp;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 220, 0, 0));

  dest.x = 0;
  dest.y = 32;
  dest.h = 4;
  dest.w = (int)(float)player_cooldown*64/10.0f;
  SDL_FillRect(engine_screen.surface, &dest, SDL_MapRGB(engine_screen.surface->format, 0, 0, 220));

  switch(player_skill)
  {
  case PLAYER_SKILL1:
    player_sel_skill(0);
    break;
  case PLAYER_SKILL2:
    player_sel_skill(1);
    break;
  }
}
