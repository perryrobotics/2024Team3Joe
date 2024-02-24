#include <kipr/wombat.h>
#include <Constants.h>

int analog_average(int port, int readings)
{
    int total;
    int i;
    for (i=0; i<readings;i++)
    {
        total = total+analog(port);
    }
    return total/readings;
}

void drive_to_black(float velocity, int port)
{
    while(velocity !=0)
    {
        if (create3_sensor_cliff(port) < BLACK)
        {
            printf("Seen Black\n");
            velocity= 0;
        }
        create3_velocity_set_components(velocity,0);
    }
    create3_wait();
}

void drive_to_white(float velocity, int port)
{
    while(velocity !=0)
    {
        if (create3_sensor_cliff(port) > BLACK)
        {
            printf("Seen Black\n");
            velocity = 0;
        }
        create3_velocity_set_components(velocity,0);
    }
    create3_wait();
}

void drive_to_ir(float velocity, int port, int distance)
{
    while(velocity !=0)
    {
        if (create3_sensor_ir(port) > distance)
        {
            printf("Seen wall\n");
            velocity= 0;
        }
        create3_velocity_set_components(velocity,0);
    }
    create3_wait();
}
void forward_to_bump(double velocity)
{
    while(velocity !=0)
    {
        if ((create3_sensor_bump(0) ==1 || create3_sensor_bump(1) ==1 || create3_sensor_bump(2) ==1 || create3_sensor_bump(3) ==1))
        {
            printf("Seen wall\n");
            velocity= 0;
        }
        create3_velocity_set_components(velocity,0);
    }
    create3_wait();
}
void drive_to_ir_or_bump(float velocity, int port, int distance)
{
    while(velocity !=0)
    {
        if (create3_sensor_ir(port) > distance || (create3_sensor_bump(0) ==1 || create3_sensor_bump(1) ==1 || create3_sensor_bump(2) ==1 || create3_sensor_bump(3) ==1))
        {
            printf("Seen wall\n");
            velocity= 0;
        }
        create3_velocity_set_components(velocity,0);
    }
    create3_wait();
}