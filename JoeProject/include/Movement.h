void CW(float angle,float speed)
{
    create3_rotate_degrees(-angle,speed);
    create3_wait();
}

void CCW(float angle,float speed)
{
    create3_rotate_degrees(angle,speed);
    create3_wait();
}
void move_servo_slowly(int port, int end_pos, int delay)
{
    int current_pos;

    current_pos = get_servo_position(port);

    if (current_pos < end_pos)
    {
        while (current_pos < end_pos)
        {
            current_pos += 7;
            set_servo_position(port, current_pos);
            msleep(delay);
        }
    }
    else
    {
        while (current_pos > end_pos)
        {
            current_pos -= 7;
            set_servo_position(port, current_pos);
            msleep(delay);
        }

    }
    set_servo_position(port, end_pos);
}
void forward(double distance, double velocity)
{
    create3_drive_straight(distance, velocity);
    create3_wait();
}
void backwards(double distance, double velocity)
{
    create3_drive_straight(-distance, velocity);
    create3_wait();
}
void stop()
{
    create3_velocity_set_components(0,0);
    create3_wait();
}