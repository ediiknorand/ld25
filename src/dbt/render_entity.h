#ifndef H_RENDER_ENTITY_H
#define H_RENDER_ENTITY_H
#include "../engine/engine.h"
#include "entity.h"

SDL_Surface *surface_tree;
SDL_Surface *surface_stone;
SDL_Surface *surface_bunny;
SDL_Surface *surface_soldier;
SDL_Surface *surface_archer;
SDL_Surface *surface_fruit;
SDL_Surface *surface_arrow;

void render_load();

void render_entity();

void render_tree();
void render_stone(int i);
void render_bunny(int i);
void render_soldier(int i);
void render_archer(int i);
void render_fruit(int i);
void render_arrow(int i);

#endif
