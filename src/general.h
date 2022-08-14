
#ifndef MATH_GENERAL_H
#define MATH_GENERAL_H

#include "math.h"
#include "./util.h"
#include "./chunk.h"

void get_sight_vector(float rx, float ry, float *vx, float *vy, float *vz);
int chunked(float x);

int _hit_test(
    Map *map, float max_distance, int previous,
    float x, float y, float z,
    float vx, float vy, float vz,
    int *hx, int *hy, int *hz);
#endif
