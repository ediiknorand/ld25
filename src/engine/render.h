#ifndef H_ENGINE_RENDER_H
#define H_ENGINE_RENDER_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/* Init render */
void engine_init_render(int flags);
/* Quit render */
void engine_quit_render();
/* Load image */
SDL_Surface *engine_load_image(char *filename);
/* Unload image */
void engine_unload_image(SDL_Surface *image);
/* Render image */
void engine_render_surface(SDL_Surface *src_surface, SDL_Rect *src_rect, SDL_Rect *dest_rect);

#endif
