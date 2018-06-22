//#ifndef BALL_H_INCLUDED
//#define BALL_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include <list>
#include <time.h>
#include "global.h"
#include "Circle.h"

class ball{

    protected:
        int attack_power;

        float speed_x;
        float speed_y;
        float accel_x;
        float accel_y;
        Circle *c=NULL;
    public:
        ball(float,float,float,float,float,int,float,float);
        ball(float,float,float,float,float,int);
        bool valid();
        void update();
        ~ball(){
            delete c;
        }

};


//#endif // BALL_H_INCLUDED
