#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include <stdio.h>

class ResourceManager {
    public:
        const char* default_file = "error.bmp";

        ResourceManager();
        ResourceManager(const char*);
        ResourceManager(std::string);

        void open(const char*);
        ALLEGRO_BITMAP* get_res() { return res; }

        ~ResourceManager();
    private:
        ALLEGRO_BITMAP* res;
};

#endif // !RESOURCE_MANAGER_H
