#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>

void engine_init_sound(int flags)
{
  if((Mix_Init(flags)&flags) != flags)
  {
    fprintf(stderr, "SDL_mixer: %s\n", Mix_GetError());
    exit(1);
  }
  if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
  {
    fprintf(stderr, "SDL_mixer: %s\n", Mix_GetError());
    exit(1);
  }
}

void engine_quit_sound()
{
  Mix_CloseAudio();
  Mix_Quit();
}
