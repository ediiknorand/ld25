#ifndef H_TEXT_ENGINE_H
#define H_TEXT_ENGINE_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

void engine_init_text();
void engine_quit_text();

TTF_Font *engine_load_font(char *filename, int ptsize);
void engine_unload_font(TTF_Font *font);

void engine_config_style(TTF_Font *font, int style);
SDL_Surface *engine_render_text(TTF_Font *font, char *text, SDL_Color *fg);

#endif
