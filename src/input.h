
#ifndef INPUT_H
#define INPUT_H

#include "stdbool.h"
#include "stdio.h"
#include <GLFW/glfw3.h>

struct input {
     int u;
    float activation;
};
#define input_p struct input *

#define input_store_main_max_size 256
struct input input_store_main[input_store_main_max_size];

input_p input_create( int key);
input_p input_get( int key);
input_p input_get_or_create( int key);
void input_on_key ( int key, bool isDown);
int char_to_glfw_key (char c);
bool input_is_down ( int key);
bool input_char_is_down( char c );


#endif
