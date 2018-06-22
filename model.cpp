#include "model.h"
#include <math.h>
#define _USE_MATH_DEFINES
std::vector<ball*> model_1::shot(){

    float x,y,vx,vy;
    const double pi= (double)3.1415926535897932384626433832795;
    std::vector<ball*> vec;
    for(int i=0;i<12;i++){
        x=loc_x+r*cos(i*15/pi);
        y=loc_y+r*sin(i*15/pi);
        vx=speed*cos(i*15/pi);
        vy=speed*sin(i*15/pi);
        auto tmp=new ball(x,y,ball_r,vx,vy,1);
        vec.push_back(tmp);
    }
    return vec;
}
