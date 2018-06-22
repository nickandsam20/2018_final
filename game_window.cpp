#include "game_window.h"
#include <iostream>
#include "global.h"
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7


ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h)
{
  ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

  // 1. create a temporary bitmap of size we want
  resized_bmp = al_create_bitmap(w, h);
  if (!resized_bmp) return NULL;

  // 2. load the bitmap at the original size
  loaded_bmp = al_load_bitmap(filename);
  if (!loaded_bmp)
  {
     al_destroy_bitmap(resized_bmp);
     return NULL;
  }

  // 3. set the target bitmap to the resized bmp
  prev_target = al_get_target_bitmap();
  al_set_target_bitmap(resized_bmp);

  // 4. copy the loaded bitmap to the resized bmp
  al_draw_scaled_bitmap(loaded_bmp,
     0, 0,                                // source origin
     al_get_bitmap_width(loaded_bmp),     // source width
     al_get_bitmap_height(loaded_bmp),    // source height
     0, 0,                                // target origin
     w, h,                                // target dimensions
     0                                    // flags
  );

  // 5. restore the previous target and clean up
  al_set_target_bitmap(prev_target);
 // al_destroy_loaded_bmp(loaded_bmp);
  al_destroy_bitmap(loaded_bmp);

  return resized_bmp;
}





void
GameWindow::game_init()
{
    //char buffer[50];

    //icon = al_load_bitmap("./icon.png");
    //background = al_load_bitmap("./StartBackground.jpg");
    //background =

   // main_page2_1=load_bitmap_at_size("./pic/main_page2-1.jpg",window_width,window_height);
   // main_page2_2=load_bitmap_at_size("./pic/main_page2-2.jpg",window_width,window_height);
    //info=load_bitmap_at_size("./pic/info.png",window_width,window_height/2);
    /*
    for(int i = 0; i < Num_TowerType; i++)
    {
        sprintf(buffer, "./Tower/%s.png", TowerClass[i]);
        tower[i] = al_load_bitmap(buffer);
        printf("%s\n",buffer);
    }
    */
    //tower[5]=load_bitmap_at_size("./Tower/My.png",1,1);
    //al_set_display_icon(display, icon);
    //al_reserve_samples(3);

    //sample = al_load_sample("growl.wav");
   // startSound = al_create_sample_instance(sample);
   // al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
   // al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());

   // sample = al_load_sample("BackgroundMusic.ogg");
    //backgroundSound = al_create_sample_instance(sample);
   // al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    //al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());


    //level = new LEVEL(1);
    //menu = new Menu();
    //slider1=new Slider(630,450);
    //slider1->set_label_content("effect sound");
    //slider2=new Slider(630,530);
    //slider2->set_label_content("BGM");
}

bool
GameWindow::mouse_hover(int startx, int starty, int width, int height)
{
    /*
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
    */
}







void
GameWindow::game_play()
{
    int msg;
    int a=0;
    int lev=1;
    int flag=0;
    srand(time(NULL));
    char text1[]={"press enter to go to next stage or press any other key to leave"};
    char text2[]={"you are dead"};
    msg = -1;

    a=game_main_page();
    if(a==0) show_err_msg(1);
    game_begin();


    while(msg!=GAME_EXIT){
        msg=game_run();
    }

    /*
    while(msg != GAME_EXIT)
    {
        msg = game_run();
        if(msg==GAME_NEXT_LEVEL){
           flag=0;
           printf("%s\n",text1);
           if(lev<4){
               al_draw_text(Medium_font, al_map_rgb(0, 0, 0),window_width/2-20 , window_height/2-100, ALLEGRO_ALIGN_CENTER, text1);
               al_flip_display();
                while(1){
                    al_wait_for_event(event_queue,&event);
                    if(event.type==ALLEGRO_EVENT_KEY_DOWN){
                        switch(event.keyboard.keycode){
                        case ALLEGRO_KEY_ENTER:
                            lev++;
                            //game_begin();
                            if(lev<=4){
                                al_stop_timer(timer);
                                al_stop_timer(monster_pro);
                                level->setLevel(lev);
                                for(auto i=towerSet.begin();i!=towerSet.end();++i){
                                    delete *i;
                                }
                                towerSet.clear();
                                monsterSet.clear();
                                game_begin();
                                flag=1;
                                break;
                            }else{

                                msg=GAME_EXIT;
                                show_err_msg(msg);
                                return;
                            }

                        default :
                            msg=GAME_EXIT;
                            show_err_msg(msg);
                            return;
                        }
                    }
                    if(flag==1) break;
                }
           }else{
                al_draw_text(Medium_font, al_map_rgb(0, 0, 0),window_width/2-20 , window_height/2-100, ALLEGRO_ALIGN_CENTER, "all level clear");
                al_flip_display();
                while(1){

                    al_wait_for_event(event_queue,&event);
                    if(event.type==ALLEGRO_EVENT_KEY_DOWN)
                    {
                        msg=GAME_EXIT;
                        show_err_msg(msg);
                        return;
                    }
                }

           }
        }else if(msg==GAME_FAIL){
            al_draw_text(Medium_font, al_map_rgb(0, 0, 0),window_width/2 , window_height/2, ALLEGRO_ALIGN_CENTER, text2);
            al_flip_display();
            while(1){
                al_wait_for_event(event_queue,&event);
                if(event.type==ALLEGRO_EVENT_KEY_DOWN){
                    break;
                }
            }
            msg=GAME_EXIT;
            show_err_msg(msg);
            return;
        }
    }
    */



    show_err_msg(msg);
}

void
GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    /*
    * Create two timers to control different parts of tower game:
    *    a. timer: control the animation of each object, stopped when game doesn't run.
    *    b. monster_pro: control the production of monster, stooped when there is no need to produce monster.
    */
    timer = al_create_timer(1.0 / FPS);
    //monster_pro = al_create_timer(1.0 * 80 / FPS);

    if(timer == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    //al_register_event_source(event_queue, al_get_timer_event_source(timer));
    //al_register_event_source(event_queue, al_get_timer_event_source(monster_pro));

    // Initializing resources that tower game needs.
    game_init();
}

void
GameWindow::game_begin()
{
    //printf(">>> Start Level[%d]\n", level->getLevel());
    draw_running_map();

    //al_play_sample_instance(startSound);
    //while(al_get_sample_instance_playing(startSound));
   // al_play_sample_instance(backgroundSound);

    al_start_timer(timer);
    //al_start_timer(monster_pro);
}

int
GameWindow::game_run()
{
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {

        error = process_event();
    }
    return error;
}

int
GameWindow::game_update()
{
    return GAME_CONTINUE;
}

void
GameWindow::game_reset()
{


    mute = false;
    redraw = false;

    // stop sample instance
   // al_stop_sample_instance(backgroundSound);
   // al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(timer);
    //al_stop_timer(monster_pro);
}

void
GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);
//    al_destroy_timer(monster_pro);



//    al_destroy_bitmap(icon);
   // al_destroy_bitmap(background);
   // al_destroy_bitmap(main_page2_1);
   // al_destroy_bitmap(main_page2_2);
    //al_destroy_bitmap(info);
    //al_destroy_sample(sample);
   // al_destroy_sample_instance(startSound);
    //al_destroy_sample_instance(backgroundSound);

   // delete level;
   // delete menu;
}

int
GameWindow::process_event()
{
    int i;
    int instruction = GAME_CONTINUE;

    al_wait_for_event(event_queue, &event);
    redraw = false;

     if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }

    if(redraw) {
        // update each object in game
        instruction = game_update();

        // Re-draw map
        draw_running_map();
        redraw = false;
    }

    return instruction;
}

void
GameWindow::draw_running_map()
{
    unsigned int i, j;

    al_clear_to_color(al_map_rgb(100, 100, 100));
    //al_draw_bitmap(background, 0, 0, 0);
    /*
    for(i = 0; i < field_height/40; i++)
    {
        for(j = 0; j < field_width/40; j++)
        {
            char buffer[50];
            sprintf(buffer, "%d", i*15 + j);
            if(level->isRoad(i*15 + j)) {
                al_draw_filled_rectangle(j*40, i*40, j*40+40, i*40+40, al_map_rgb(255, 244, 173));
            }
            // For debug usage, if you want to create a new map, you may turn off this comment.
            // al_draw_text(font, al_map_rgb(0, 0, 0), j*40 + 20, i*40 + 14, ALLEGRO_ALIGN_CENTER, buffer);
        }
    }
    for(i=0; i<monsterSet.size(); i++)
    {
        monsterSet[i]->Draw();
    }



    for(std::list<Tower*>::iterator it = towerSet.begin(); it != towerSet.end(); it++)
        (*it)->Draw();

    if(selectedTower != -1)
        Tower::SelectedTower(mouse_x, mouse_y, selectedTower);
    */
    //al_draw_filled_rectangle(field_width, 0, window_width, window_height, al_map_rgb(100, 100, 100));

    //menu->Draw();
    //slider1->Draw();
    //slider2->Draw();
    //if(draw_info==1)al_draw_bitmap(info,0,0,0);
    al_flip_display();
}
int GameWindow::game_main_page(){
}
void GameWindow::game_pause1(){
    /*
    al_stop_timer(timer);
    al_stop_timer(monster_pro);


    while(1){
        al_wait_for_event(event_queue,&event);
        if(event.type==ALLEGRO_EVENT_KEY_DOWN){
               if(event.keyboard.keycode==ALLEGRO_KEY_P){
                al_resume_timer(timer);
                al_resume_timer(monster_pro);

                    return;
               }
        }
    }
    */
}
void GameWindow::game_pause2(){

    al_stop_timer(timer);
    //al_stop_timer(monster_pro);
    al_draw_text(Large_font, al_map_rgb(0, 0, 0),window_width/2-50 , window_height/2-50, ALLEGRO_ALIGN_CENTER, "pause");
    al_flip_display();

    while(1){
        al_wait_for_event(event_queue,&event);
        if(event.type==ALLEGRO_EVENT_KEY_DOWN){
               if(event.keyboard.keycode==ALLEGRO_KEY_P){
                al_start_timer(timer);
                //al_start_timer(monster_pro);

                    return;
               }
        }
    }

}


