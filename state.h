#ifndef STATE_H
#define STATE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "key_event.h"

class State {
    public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void input(KeyEvent*) = 0;
    virtual void init() {}
    virtual void destroy() {}
};

#endif // !STATE_H
