#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "string_funcs.h"
#include "key_event.h"
#include "state.h"
#include "state_main_menu.h"

//class MainMenuState;

class Application {
    public:
    unsigned int height;
    unsigned int width;
    float tick_rate = 60.0;
    std::string title;
    std::ifstream config;

    ALLEGRO_DISPLAY* disp            = NULL;
    ALLEGRO_TIMER* timer             = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

    State* current_state;

    Application(const char*);
    Application(std::string);
    int start();
    void update();
    void draw();
    void loop();
    void input(KeyEvent*);
    void set_game_state(State*);

    //current state functions
    void state_init();
    void state_destroy();
    private:
    bool app_end = false;
    
    void _parse_config(std::ifstream&);
};

#endif // !APPLICATION_H
