#ifndef H_WAVE_H
#define H_WAVE_H

double wave_cooldown;
int wave_n;

void wave_load();
void wave_refresh(double delta);
void wave_render();

#endif
