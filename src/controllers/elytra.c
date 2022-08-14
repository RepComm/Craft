/**
  * An accurate simulation of the elytra item as of Minecraft 15w41b
  * Adapted from https://gist.github.com/samsartor/a7ec457aca23a7f3f120
  */

#ifndef ELYTRA_C
#define ELYTRA_C

#include "stdbool.h"
#include "math.h"

struct elytra {
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
void elytra_tick (elytra_p e) {
    if (!e->isCreative && (e->glideTime + 1) % 20 == 0) {
        e->damageTaken++;
    }
	float yaw = e->yaw;
    float pitch = e->pitch;
    float velX = e->velX;
    float velY = e->velY;
    float velZ = e->velZ;

    //simplifing of the folowing to reduce the number of negatives and trig functions
    float yawcos =   cos(-yaw - PI);
    float yawsin =   sin(-yaw - PI);
    float pitchcos = cos(pitch);
    float pitchsin = sin(pitch);
    
    float lookX = yawsin * -pitchcos;
    float lookY = -pitchsin;
    float lookZ = yawcos * -pitchcos;
    
    float hvel = sqrt(velX * velX + velZ * velZ);
    float hlook = pitchcos; //Math.sqrt(lookX * lookX + lookZ * lookZ)
    float sqrpitchcos = pitchcos * pitchcos; //In MC this is multiplied by Math.min(1.0, Math.sqrt(lookX * lookX + lookY * lookY + lookZ * lookZ) / 0.4), don't ask me why, it should always =1
    
    //From here on, the code is identical to the code found in net.minecraft.entity.EntityLivingBase.moveEntityWithHeading(float, float) or rq.g(float, float) in obfuscated 15w41b
    e->velY += -0.08 + sqrpitchcos * 0.06;
    
    if (e->velY < 0 && hlook > 0) {
        float yacc = velY * -0.1 * sqrpitchcos;
        velY += yacc;
        velX += lookX * yacc / hlook;
        velZ += lookZ * yacc / hlook;
    }
    if (pitch < 0) {
        double yacc = hvel * -pitchsin * 0.04;
        velY += yacc * 3.5;
        velX -= lookX * yacc / hlook;
        velZ -= lookZ * yacc / hlook;
    }
    if (hlook > 0) {
        velX += (lookX / hlook * hvel - velX) * 0.1;
        velZ += (lookZ / hlook * hvel - velZ) * 0.1;
    }
    
    velX *= 0.99;
    velY *= 0.98;
    velZ *= 0.99;
    
    e->posX += velX;
    e->posY += velY;
    e->posZ += velZ;
    e->velX = velX;
    e->velY = velY;
    e->velZ = velZ;

    e->glideTime++;
}

/** 
* Checks if the player is currently in a gliding state.
* As you can see, if the player is in creative, they will remain gliding even if on the ground. They will stop gliding once they move (but that functionality is not shown here).
*/
bool elytra_isGliding(elytra_p e) {
    if (e->isCreative) {	
        return e->glideTime > 0;
    } else {
        return !e->isOnGround && e->fallDistance >= 1.0f;
    }
}


#endif
