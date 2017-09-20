#include "resource_manager.h"

ResourceManager::ResourceManager() {}
ResourceManager::ResourceManager(std::string file) {
    ResourceManager(file.c_str());
}

ResourceManager::ResourceManager(const char* file) {
    open(file);
}

void ResourceManager::open(const char* file) {
//    ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
//    chdir(al_path_cstr(path, '/'));
//    al_destroy_path(path);
    
    res = al_load_bitmap(file);
    if(!res) {
        fprintf(stderr, "Unable to open resource file\n");
    }
//    res = al_load_bitmap(default_file);
//    if(!res) {
//        fprintf(stderr, "Unable to open default resource file. Man, you're really fucked now.\n");
//    }
}

ResourceManager::~ResourceManager() {
    al_destroy_bitmap(res);
}
