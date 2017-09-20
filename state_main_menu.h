#ifndef STATE_MAIN_MENU_H
#define STATE_MAIN_MENU_H

#include "stdio.h"

#include "state.h"
#include "resource_manager.h"
#include "application.h"

class Application;

class MainMenuState: public State {
    public:
    MainMenuState(Application*);
    ~MainMenuState();

    Application* parent_application;

    const char* res_cheese = "res/cheese.bmp";
    const char* res_wine   = "res/wine.bmp";

    ResourceManager resource_cheese;
    ResourceManager resource_wine;

    ALLEGRO_BITMAP* cheese = NULL;
    ALLEGRO_BITMAP* wine   = NULL;

    ALLEGRO_COLOR color_bg = al_map_rgb(141, 181, 244);

    void update();
    void draw();
    void input(KeyEvent*);
    void init();
};

#endif // !STATE_MAIN_MENU_H
