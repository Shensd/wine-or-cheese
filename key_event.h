#ifndef KEY_EVENT_H
#define KEY_EVENT_H

class KeyEvent {
    public:
        const int KEY_DOWN = 1;
        const int KEY_UP = 0;
        int keycode;
        char keychar;
        int state;
        KeyEvent(int k, int s) : keycode(k), state(s) {}
};

#endif // !KEY_EVENT_H
