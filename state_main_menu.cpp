#include "state_main_menu.h"

MainMenuState::MainMenuState(Application* app) : parent_application(app) {}

MainMenuState::~MainMenuState() {}

void MainMenuState::init() {
    resource_cheese.open(res_cheese);
    resource_wine.open(res_wine);


    /*
    cheese = al_load_bitmap("res/cheese.bmp");
    if(!cheese) {
        printf("Unable to load cheese bmp\n");
    }
    wine = al_load_bitmap("res/wine.bmp");
    if(!wine) {
        printf("Unable to load wine bmp\n");
    }
    */

}

void MainMenuState::update() {

}

void MainMenuState::draw() {
    al_clear_to_color(color_bg);
    
    //float y = (parent_application->height / 2) + al_get_bitmap_height(resource_cheese.get_res());
//    float y = (parent_application->height / 6);

//    printf("%i\n", y);

    //al_draw_rectangle(x, y, x+w, y+w, al_map_rgb(0, 255, 0), 2.0);
    
    al_draw_bitmap(resource_wine.get_res(), 50, 50, 0);
    //al_draw_bitmap(wine, 300, 0, 0);
    
    al_draw_bitmap(resource_cheese.get_res(), 300, 50, 0);
    //al_draw_bitmap(cheese, 0, 0, 0);

    al_flip_display();
}

void MainMenuState::input(KeyEvent* ke) {
    bool is_down = ke->state == ke->KEY_DOWN ? true : false;
    switch(ke->keycode) {
    case ALLEGRO_KEY_W:
        if(is_down) {
        
        } else {
        
        }
        break;
    case ALLEGRO_KEY_A:
        if(is_down) {
        
        } else {
        
        }
        break;
    case ALLEGRO_KEY_S:
        if(is_down) {
        
        } else {
        
        }
        break;
    case ALLEGRO_KEY_D:
        if(is_down) {
        
        } else {
        
        }
        break;
    }
}
