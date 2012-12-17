#ifndef H_PATH_H
#define H_PATH_H

void path_follow(int idx, float x, float y, double delta);
void path_enemy(int idx);
void path_travel(int idx, double delta);
int path_detect_ally(int idx, float *x, float *y);
int path_detect_enemy(int idx, float *x, float *y);

#endif
