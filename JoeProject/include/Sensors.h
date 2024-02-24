#include <kipr/wombat.h>
#include <Constants.h>

int analog_average(int port, int readings); 
void drive_to_black(float velocity, int port);
void drive_to_white(float velocity, int port);
void drive_to_ir(float velocity, int port, int distance);
void forward_to_bump(double velocity);
void drive_to_ir_or_bump(float velocity, int port, int distance);