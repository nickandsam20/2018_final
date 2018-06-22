#include "ball.h"
#include "global.h"
ball::ball(float x,float y,float r,float s_x=0,float s_y=0,int power=0,float a_x=0,float a_y=0){
    c=new Circle(x,y,r);
    speed_x=s_x;
    speed_y=s_y;
    attack_power=power;
    accel_x=a_x;
    accel_y=a_y;

}
ball::ball(float x,float y,float r,float s_x=0,float s_y=0,int power=0){
    c=new Circle(x,y,r);
    speed_x=s_x;
    speed_y=s_y;
    attack_power=power;
    accel_x=0;
    accel_y=0;

}

bool ball::valid(){
    //if(loc_x-radius<=0 || loc_x+radius>=window_width) return false;
    //if(loc_y-radius<=0 || loc_y+radius>=window_height) return false;
    if(c->x-c->r<=0 || c->x+c->r>=window_width) return false;
    if(c->y-c->r<=0 || c->y+c->r>=window_height) return false;
    return true;
}

void ball::update(){
    c->x+=speed_x;
    c->y+=speed_y;
    speed_x+=accel_x;
    speed_y+=accel_y;
}
