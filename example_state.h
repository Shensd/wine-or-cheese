#include "stdio.h"

#include "state.h"

class ExampleState: public State {
    public:
        ExampleState();
        ~ExampleState();

        void update();
        void draw();
        void input(KeyEvent*);
    private:
        float speed = 5;
        float velx = 0, vely = 0;
        float x = 10, y = 10;
        float w = 20, h = 20;
};
