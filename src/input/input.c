
#ifndef INPUT_C
#define INPUT_C

#include "stdbool.h"
#include "stdio.h"

struct input {
    unsigned int u;
    float activation;
};
#define input_p struct input *

#define input_store_main_max_size 256
struct input input_store_main[input_store_main_max_size];
int input_store_main_end = 0;

//may be null
input_p input_create(int key) {
    if (input_store_main_end >= input_store_main_max_size) return 0;
    input_p result = &input_store_main[input_store_main_end];
    result->u = key;
    input_store_main_end ++;
    
    // printf("input create for key %i, new size: %i\n", key, input_store_main_end);
    
    return result;
}

input_p input_get(int key) {
    input_p result = 0;

    for (int i=0; i<input_store_main_end; i++) {
        result = &input_store_main[i];
        if ( result->u == key ) break;
    }
    return result;
}

//may be null
input_p input_get_or_create(int key) {
    input_p result = input_get(key);

    result = input_create(key);

    return result;
}

void input_on_key (int key, bool isDown) {
    input_p inp = input_get_or_create(key);
    if (inp == 0) return; //ran out of inputs
    inp->activation = isDown ? 1.0 : 0.0;
}

bool input_is_down (int key) {
    input_p inp = input_get(key);
    return (inp != 0 && inp->activation > 0.5);
}

#endif
