
#ifndef INPUT_C
#define INPUT_C

#include "stdbool.h"
#include "stdio.h"
#include "../../deps/glfw/include/GLFW/glfw3.h"

struct input {
     int u;
    float activation;
};
#define input_p struct input *

#define input_store_main_max_size 256
struct input input_store_main[input_store_main_max_size];
int input_store_main_end = 0;

//may be null
input_p input_create( int key) {
    
    if (input_store_main_end >= input_store_main_max_size) return 0;
    
    //this works, apparently google doens't know how to let you google this if you needed it
    input_p result = &input_store_main[input_store_main_end];
    
    result->u = key;
    result->activation = 0.0;
    
    input_store_main_end ++;
    
    // printf("input create for key '%c', new size: %i, result ptr: %i\n", key, input_store_main_end, result);
    
    return result;
}

input_p input_get( int key) {
    input_p current;

    for (int i=0; i<input_store_main_end; i++) {
        current = &input_store_main[i];

        if ( current->u == key ) {
            return current;
        }
    }
    return 0;
}

//may be null
input_p input_get_or_create( int key) {
    input_p result = input_get(key);
    
    if (result == 0) {
        result = input_create(key);
        // printf("new input adr %i\n", result);
    }

    return result;
}

void input_on_key ( int key, bool isDown) {
    input_p inp = input_get_or_create(key);
    if (inp == 0) return; //ran out of inputs
    inp->activation = isDown ? 1.0 : 0.0;
}

int char_to_glfw_key (char c) {
    if (c == ' ') { return GLFW_KEY_SPACE; 
    } else if (c == '\'') { return GLFW_KEY_APOSTROPHE; 
    } else if (c == ',') { return GLFW_KEY_COMMA; 
    } else if (c == '-') { return GLFW_KEY_MINUS; 
    } else if (c == '.') { return GLFW_KEY_PERIOD; 
    } else if (c == '/') { return GLFW_KEY_SLASH; 
    } else if (c == '0') { return GLFW_KEY_0; 
    } else if (c == '1') { return GLFW_KEY_1; 
    } else if (c == '2') { return GLFW_KEY_2; 
    } else if (c == '3') { return GLFW_KEY_3; 
    } else if (c == '4') { return GLFW_KEY_4; 
    } else if (c == '5') { return GLFW_KEY_5; 
    } else if (c == '6') { return GLFW_KEY_6; 
    } else if (c == '7') { return GLFW_KEY_7; 
    } else if (c == '8') { return GLFW_KEY_8; 
    } else if (c == '9') { return GLFW_KEY_9; 
    } else if (c == ';') { return GLFW_KEY_SEMICOLON; 
    } else if (c == '=') { return GLFW_KEY_EQUAL; 
    } else if (c == 'a') { return GLFW_KEY_A; 
    } else if (c == 'b') { return GLFW_KEY_B; 
    } else if (c == 'c') { return GLFW_KEY_C; 
    } else if (c == 'd') { return GLFW_KEY_D; 
    } else if (c == 'e') { return GLFW_KEY_E; 
    } else if (c == 'f') { return GLFW_KEY_F; 
    } else if (c == 'g') { return GLFW_KEY_G; 
    } else if (c == 'h') { return GLFW_KEY_H; 
    } else if (c == 'i') { return GLFW_KEY_I; 
    } else if (c == 'j') { return GLFW_KEY_J; 
    } else if (c == 'k') { return GLFW_KEY_K; 
    } else if (c == 'l') { return GLFW_KEY_L; 
    } else if (c == 'm') { return GLFW_KEY_M; 
    } else if (c == 'n') { return GLFW_KEY_N; 
    } else if (c == 'o') { return GLFW_KEY_O; 
    } else if (c == 'p') { return GLFW_KEY_P; 
    } else if (c == 'q') { return GLFW_KEY_Q; 
    } else if (c == 'r') { return GLFW_KEY_R; 
    } else if (c == 's') { return GLFW_KEY_S; 
    } else if (c == 't') { return GLFW_KEY_T; 
    } else if (c == 'v') { return GLFW_KEY_U; 
    } else if (c == 'v') { return GLFW_KEY_V; 
    } else if (c == 'w') { return GLFW_KEY_W; 
    } else if (c == 'x') { return GLFW_KEY_X; 
    } else if (c == 'y') { return GLFW_KEY_Y; 
    } else if (c == 'z') { return GLFW_KEY_Z; 
    } else if (c == '[') { return GLFW_KEY_LEFT_BRACKET; 
    } else if (c == '\\') { return GLFW_KEY_BACKSLASH; 
    } else if (c == ']') { return GLFW_KEY_RIGHT_BRACKET; 
    } else if (c == '`') { return GLFW_KEY_GRAVE_ACCENT; 
    // } else if (c == '') { return GLFW_KEY_WORLD_1; 
    // } else if (c == '') { return GLFW_KEY_WORLD_2; 
    } else if (c == 27) { return GLFW_KEY_ESCAPE; 
    } else if (c == '\r') { return GLFW_KEY_ENTER; 
    } else if (c == '\t') { return GLFW_KEY_TAB; 
    } else if (c == '\b') { return GLFW_KEY_BACKSPACE; 
    // } else if (c == '') { return GLFW_KEY_INSERT; 
    // } else if (c == '\d') { return GLFW_KEY_DELETE; 
    // } else if (c == '') { return GLFW_KEY_RIGHT; 
    // } else if (c == '') { return GLFW_KEY_LEFT; 
    // } else if (c == '') { return GLFW_KEY_DOWN; 
    // } else if (c == '') { return GLFW_KEY_UP; 
    // } else if (c == '') { return GLFW_KEY_PAGE_UP; 
    // } else if (c == '') { return GLFW_KEY_PAGE_DOWN; 
    // } else if (c == '') { return GLFW_KEY_HOME; 
    // } else if (c == '') { return GLFW_KEY_END; 
    // } else if (c == '') { return GLFW_KEY_CAPS_LOCK; 
    // } else if (c == '') { return GLFW_KEY_SCROLL_LOCK; 
    // } else if (c == '') { return GLFW_KEY_NUM_LOCK; 
    // } else if (c == '') { return GLFW_KEY_PRINT_SCREEN; 
    // } else if (c == '') { return GLFW_KEY_PAUSE; 
    // } else if (c == '') { return GLFW_KEY_F1; 
    // } else if (c == '') { return GLFW_KEY_F2; 
    // } else if (c == '') { return GLFW_KEY_F3; 
    // } else if (c == '') { return GLFW_KEY_F4; 
    // } else if (c == '') { return GLFW_KEY_F5; 
    // } else if (c == '') { return GLFW_KEY_F6; 
    // } else if (c == '') { return GLFW_KEY_F7; 
    // } else if (c == '') { return GLFW_KEY_F8; 
    // } else if (c == '') { return GLFW_KEY_F9; 
    // } else if (c == '') { return GLFW_KEY_F10; 
    // } else if (c == '') { return GLFW_KEY_F11; 
    // } else if (c == '') { return GLFW_KEY_F12; 
    // } else if (c == '') { return GLFW_KEY_F13; 
    // } else if (c == '') { return GLFW_KEY_F14; 
    // } else if (c == '') { return GLFW_KEY_F15; 
    // } else if (c == '') { return GLFW_KEY_F16; 
    // } else if (c == '') { return GLFW_KEY_F17; 
    // } else if (c == '') { return GLFW_KEY_F18; 
    // } else if (c == '') { return GLFW_KEY_F19; 
    // } else if (c == '') { return GLFW_KEY_F20; 
    // } else if (c == '') { return GLFW_KEY_F21; 
    // } else if (c == '') { return GLFW_KEY_F22; 
    // } else if (c == '') { return GLFW_KEY_F23; 
    // } else if (c == '') { return GLFW_KEY_F24; 
    // } else if (c == '') { return GLFW_KEY_F25; 
    // } else if (c == '') { return GLFW_KEY_KP_0; 
    // } else if (c == '') { return GLFW_KEY_KP_1; 
    // } else if (c == '') { return GLFW_KEY_KP_2; 
    // } else if (c == '') { return GLFW_KEY_KP_3; 
    // } else if (c == '') { return GLFW_KEY_KP_4; 
    // } else if (c == '') { return GLFW_KEY_KP_5; 
    // } else if (c == '') { return GLFW_KEY_KP_6; 
    // } else if (c == '') { return GLFW_KEY_KP_7; 
    // } else if (c == '') { return GLFW_KEY_KP_8; 
    // } else if (c == '') { return GLFW_KEY_KP_9; 
    // } else if (c == '') { return GLFW_KEY_KP_DECIMAL; 
    // } else if (c == '') { return GLFW_KEY_KP_DIVIDE; 
    // } else if (c == '') { return GLFW_KEY_KP_MULTIPLY; 
    // } else if (c == '') { return GLFW_KEY_KP_SUBTRACT; 
    // } else if (c == '') { return GLFW_KEY_KP_ADD; 
    // } else if (c == '') { return GLFW_KEY_KP_ENTER; 
    // } else if (c == '') { return GLFW_KEY_KP_EQUAL; 
    // } else if (c == '') { return GLFW_KEY_LEFT_SHIFT; 
    // } else if (c == '') { return GLFW_KEY_LEFT_CONTROL; 
    // } else if (c == '') { return GLFW_KEY_LEFT_ALT; 
    // } else if (c == '') { return GLFW_KEY_LEFT_SUPER; 
    // } else if (c == '') { return GLFW_KEY_RIGHT_SHIFT; 
    // } else if (c == '') { return GLFW_KEY_RIGHT_CONTROL; 
    // } else if (c == '') { return GLFW_KEY_RIGHT_ALT; 
    // } else if (c == '') { return GLFW_KEY_RIGHT_SUPER; 
    // } else if (c == '') { return GLFW_KEY_MENU; 
    // } else if (c == '') { return GLFW_KEY_LAST;
    } else {
        return GLFW_KEY_UNKNOWN; 
    }
}
bool input_is_down ( int key) {
    input_p inp = input_get(key);
    if (inp == 0) {
        // printf("no input found for '%c'\n", key);
        return false;
    }
    return (inp->activation > 0.5);
}
bool input_char_is_down( char c ) {
    return input_is_down( char_to_glfw_key(c));
}



#endif
