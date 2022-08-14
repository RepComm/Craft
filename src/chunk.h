
#ifndef CHUNK_C
#define CHUNK_C

#include "./map.h"
#include "./sign.h"
#include "./util.h"

#include <GLFW/glfw3.h>

#define MAX_CHUNKS 8192

typedef struct {
    Map map;
    Map lights;
    SignList signs;
    int p;
    int q;
    int faces;
    int sign_faces;
    int dirty;
    int miny;
    int maxy;
    GLuint buffer;
    GLuint sign_buffer;
} Chunk;

int chunk_distance(Chunk *chunk, int p, int q);

#endif
