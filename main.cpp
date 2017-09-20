#include <vector>
#include <string>
#include <stdio.h>
#include <allegro5/allegro.h>

#include "application.h"

int main(int argc, char* argv[]) {
    Application app("app_conf.txt");
    app.start();    
    return 0;
}
