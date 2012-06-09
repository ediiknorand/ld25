#ifndef H_ENGINE_RENDER_H
#define H_ENGINE_RENDER_H

/* Init render */
void engine_render_init(int flags);
/* Quit render */
void engine_render_quit();
/* Load image */
SDL_Surface *engine_load_image(char *filename);
/* Unload image */
void engine_unload_image(SDL_Surface *image);
/* Render image */

#endif
