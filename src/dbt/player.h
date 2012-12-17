#ifndef H_PLAYER_H
#define H_PLAYER_H

#define PLAYER_SKILL0 0
#define PLAYER_SKILL1 1
#define PLAYER_SKILL2 2
#define PLAYER_SKILL3 3
#define PLAYER_SKILL4 4

#include "../engine/engine.h"

int player_skill;
double player_cooldown;
SDL_Surface *player_hud_skill;

void player_load();
void player_input();
void player_refresh(double delta);
void player_render();
void player_render_square();

#endif
