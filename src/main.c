#include "engine/engine.h"
#include "dbt/main_scene.h"

int main()
{
  engine_init_sdl();
  engine_init_screen(640, 480, 0,  SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_HWPALETTE);
  engine_set_title("Ludum Dare 25 - Death by Tree","Death by Tree");
  engine_init_render(IMG_INIT_PNG);

  engine_load_scene(dbt_load, dbt_unload, dbt_refresh, dbt_render);
  engine_main_loop();

  engine_quit_render();
  return 0;
}
