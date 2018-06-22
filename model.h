//#ifndef MODEL_H_INCLUDED
//#define MODEL_H_INCLUDED
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
#include "ball.h"

class model{
    protected:
        float loc_x;
        float loc_y;
        float r;
        float ball_r;
    public:
        model(float x,float y):loc_x(x),loc_y(y){}


};

class model_1:public model{ //¶ê§Îµo´²
    public:
        model_1(float x,float y,float v):model(x,y),speed(v){ ball_r=1;}
        std::vector<ball*>shot();
    protected:
        float speed;


};
//#endif
