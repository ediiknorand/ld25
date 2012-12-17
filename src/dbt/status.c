#include "status.h"
#include "entity.h"


void status_set(int idx)
{
  dbt_entity[idx].atk = status_atk(dbt_entity[idx].type);
  dbt_entity[idx].maxhp = status_hp(dbt_entity[idx].type);
  dbt_entity[idx].hp = dbt_entity[idx].maxhp;
}

int status_atk(int type)
{
  switch(type)
  {
  case ENTITY_DTREE: return 100;
  case ENTITY_BUNNY: return 20;
  case ENTITY_SOLDIER: return 20;
  case ENTITY_ARCHER: return 5;
  case ENTITY_STONE: return 8000;
  }
  return 0;
}

int status_hp(int type)
{
  switch(type)
  {
  case ENTITY_DTREE: return 500;
  case ENTITY_BUNNY: return 200;
  case ENTITY_SOLDIER: return 100;
  case ENTITY_ARCHER: return 90;
  case ENTITY_STONE: return 8000;
  }
  return 0;
}

float status_speed(int type)
{
  switch(type)
  {
  case ENTITY_DTREE: return 0.0f;
  case ENTITY_BUNNY: return 0.6f;
  case ENTITY_SOLDIER: return 0.8f;
  case ENTITY_ARCHER: return 0.6f;
  case ENTITY_STONE: return 0.0f;
  }
  return 0.0f;
}
