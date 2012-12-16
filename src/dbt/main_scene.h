#ifndef H_MAIN_SCENE_H
#define H_MAIN_SCENE_H

#include "../engine/engine.h"

void *dbt_load(void *scene);
void *dbt_unload(void *scene);
int dbt_refresh(void *scene, Uint8 *keyboard, double delta);
void dbt_render(void *scene, double delta);

#endif
