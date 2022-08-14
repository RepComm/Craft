/**
  * An accurate simulation of the elytra item as of Minecraft 15w41b
  * Adapted from https://gist.github.com/samsartor/a7ec457aca23a7f3f120
  */

#ifndef ELYTRA_H
#define ELYTRA_H

#include "stdbool.h"
#include "math.h"

typedef struct elytra {
	int glideTime;
	int damageTaken;
	
    float posX;
	float posY;
	float posZ;

	float velX;
	float velY;
	float velZ;

    bool isCreative;
    bool isOnGround;
    float fallDistance;

    float pitch;
    float yaw;
};
#define elytra_p struct elytra *

#define PI 3.141592653589793

/**
* Simulates a Minecraft tick (20 per second).
* The pitch and yaw are the look direction of the player.
*/
void elytra_tick (elytra_p e);
/** 
* Checks if the player is currently in a gliding state.
* As you can see, if the player is in creative, they will remain gliding even if on the ground. They will stop gliding once they move (but that functionality is not shown here).
*/
bool elytra_isGliding(elytra_p e);

#endif
