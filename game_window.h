//#ifndef MAINWINDOW_H_INCLUDED
//#define MAINWINDOW_H_INCLUDED

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




// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Time_Gain = 1;

class GameWindow
{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();
    int game_main_page();
    int game_run();
    int game_update();
    void game_pause1();
    void game_pause2();
    void show_err_msg(int msg);
    void game_destroy();

    // draw running game map
    void draw_running_map();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);
    // detect if a tower will be constructed on road
   // bool isOnRoad();
public:
    bool initial = true;

private:
   // ALLEGRO_BITMAP *icon;
    //ALLEGRO_BITMAP *tower[Num_TowerType];
    //ALLEGRO_BITMAP *background = NULL;
    //ALLEGRO_BITMAP *main_page2_2=NULL;
    //ALLEGRO_BITMAP* main_page2_1=NULL;
    //ALLEGRO_BITMAP *info=NULL;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;
   // ALLEGRO_TIMER *monster_pro = NULL;

    //ALLEGRO_SAMPLE *sample = NULL;
   // ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
   // ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
   // ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
   // ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;

  //  LEVEL *level = NULL;
    //Menu *menu = NULL;
    //Slider *slider1=NULL;
   // Slider *slider2=NULL;
   // std::vector<Monster*> monsterSet;
    //std::list<Tower*> towerSet;

  //  int Coin_Inc_Count = 0;
  //  int mouse_x, mouse_y;
   // int selectedTower = -1, lastClicked = -1;
 //   int slider1_click=0;
 //   int slider2_click=0;
   // float deg=1;
   // float bgm_voice=1;
    bool redraw = false;
    bool mute = false;
    int draw_info=-1;
};


//#endif // MAINWINDOW_H_INCLUDED
