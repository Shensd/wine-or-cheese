#include "example_state.h"

ExampleState::ExampleState() {}

ExampleState::~ExampleState() {}

void ExampleState::update() {
    x += velx;
    y += vely;
}

void ExampleState::draw() {
    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_draw_rectangle(x, y, x+w, y+w, al_map_rgb(0, 255, 0), 2.0);

    al_flip_display();
}

void ExampleState::input(KeyEvent* ke) {
    bool is_down = ke->state == ke->KEY_DOWN ? true : false;
    switch(ke->keycode) {
    case ALLEGRO_KEY_W:
        if(is_down) {
            vely = -speed;
        } else {
            if(vely == -speed) {vely = 0;}
        }
        break;
    case ALLEGRO_KEY_A:
        if(is_down) {
            velx = -speed;
        } else {
            if(velx == -speed) {velx = 0;}
        }
        break;
    case ALLEGRO_KEY_S:
        if(is_down) {
            vely = speed;
        } else {
            if(vely == speed) {vely = 0;}
        }
        break;
    case ALLEGRO_KEY_D:
        if(is_down) {
            velx = speed;
        } else {
            if(velx == speed) {velx = 0;}
        }
        break;
    }
}
