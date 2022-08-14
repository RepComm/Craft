
#ifndef PLAYER_H
#define PLAYER_H

//for GLuint
#include <GL/glew.h>
#include <memory.h>

#include "./util.h"
#include "./matrix.h"
#include "./general.h"

#include "./cube.h"

#define MAX_NAME_LENGTH 32

typedef struct {
    float x;
    float y;
    float z;
    float rx;
    float ry;
    float t;
} State;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    State state;
    State state1;
    State state2;
    GLuint buffer;
} Player;

void make_player(
    float *data,
    float x, float y, float z, float rx, float ry);

GLuint gen_player_buffer(float x, float y, float z, float rx, float ry);

void update_player(Player *player,
    float x, float y, float z, float rx, float ry, int interpolate);

void interpolate_player(Player *player);


float player_player_distance(Player *p1, Player *p2);

float player_crosshair_distance(Player *p1, Player *p2);

#endif
