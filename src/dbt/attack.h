#ifndef H_ATTACK_H
#define H_ATTACK_H

double attack_cooldown;

void attack_refresh();
void attack_ally(int idx, int rng);
void attack_enemy(int idx, int rng);
void attack_damage();
void attack_unit(int idx, double delta);


#endif
