#ifndef H_ENGINE_RENDER_H
#define H_ENGINE_RENDER_H

#include <SDL/SDL.h>

/* Init render */
void engine_render_init(int flags);
/* Quit render */
void engine_render_quit();
/* Load image */
SDL_Surface *engine_load_image(char *filename);
/* Unload image */
void engine_unload_image(SDL_Surface *image);
/* Render image */
void engine_render_image(SDL_Surface *src_surface, SDL_Rect *src_rect, SDL_Rect *dest_rect);

#endif
