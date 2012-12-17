#ifndef H_ENTITY_H
#define H_ENTITY_H

#define ENTITY_MAX 256

#define ENTITY_DTREE 0
#define ENTITY_STONE 3
#define ENTITY_BUNNY 10
#define ENTITY_SOLDIER 20
#define ENTITY_ARCHER 21
#define ENTITY_FRUIT 40
#define ENTITY_ARROW 41

typedef struct
{
  char use;
  float x,y;
  float sx, sy;
  int hp, maxhp;
  int atk;
  int type;
} Entity;

Entity dbt_entity[ENTITY_MAX];

void entity_load();

void entity_stone_map();

int entity_first_index();

void entity_spawn(int type, float x, float y);
void entity_spawn_stone(float x, float y);
void entity_spawn_bunny(float x, float y);
void entity_spawn_soldier(float x, float y);
void entity_spawn_archer(float x, float y);
void entity_spawn_fruit(float x, float y);
void entity_spawn_arrow(float x, float y);

#endif
