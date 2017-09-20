#include "application.h"

Application::Application(const char* conf) {
    Application::config.open(conf);
    
    if(config.is_open()) {
        _parse_config(config);
    } else {
        printf("Unable to open config file");
    }
}
Application::Application(std::string str) {
    Application(str.c_str());
}

void Application::_parse_config(std::ifstream& conf) {
    const std::string width = "width";
    const std::string height = "height";
    const std::string title = "title";
    
    std::vector<std::string> lines;
    std::string temp;
    unsigned int line_number = 0;
    while(getline(conf, temp)) {
        lines.push_back(temp);
        line_number++;
        
        std::vector<std::string> vals = split(temp, ' ');
        std::string name = vals.at(0);
        vals.erase(vals.begin());
        std::string value = join(vals, ' ');

        if(name == width) {
            try {
                Application::width = std::stoi(value, nullptr);
                printf("Window width set to %s", value.c_str());
            } catch(std::invalid_argument e) { 
                std::string s("Unable to parse line " + std::to_string(line_number) + ", '" + value + "' is not a number.");
                printf("%s", s.c_str());
            }
        } else if(name == height) {
            try {
                Application::height = std::stoi(value, nullptr);
                printf("Window height set to %s", value.c_str());
            } catch(std::invalid_argument e) {
                std::string s("Unable to parse line " + std::to_string(line_number) + ", '" + value + "' is not a number.");
                printf("%s", s.c_str());
            }
        } else if(name == title) {
            Application::title = value;
            printf("Window title set to %s", value.c_str());

        } else {
            std::string s("Argument '" + name + "' on line " + std::to_string(line_number) + " not found.");
            printf("%s", s.c_str());
        }
        printf("\n");
    }

    return;    
}

int Application::start() {
    al_init();

    disp = al_create_display(width, height);
    if(!disp) {
        printf("Unable to create display\n");
        return -1;
    }
    al_set_window_title(disp, title.c_str());

    event_queue = al_create_event_queue();
    if(!event_queue) {
        printf("Unable to create event_queue\n");
        return -1;
    }
    timer = al_create_timer(1 / tick_rate);
    if(!timer) {
        printf("Unable to create game timer\n");
        return -1;
    }

    if(!al_install_keyboard()) {
        printf("Unable to install keyboard\n");
        return -1;
    }
    if(!al_init_image_addon()) {
        printf("Unable to init image addon\n");
    }

    al_register_event_source(event_queue, al_get_display_event_source(disp));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    
    current_state = new MainMenuState(this);
    
    state_init();

    loop();

    return 0;
}

void Application::loop() {
    
    al_start_timer(timer);

    ALLEGRO_EVENT events;
    
    while(!app_end) {
        while(!al_is_event_queue_empty(event_queue)) {
            al_wait_for_event(event_queue, &events);
            switch(events.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    app_end = true;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    input(new KeyEvent(events.keyboard.keycode, 1));
                    break;
                case ALLEGRO_EVENT_KEY_UP:
                    input(new KeyEvent(events.keyboard.keycode, 0));
                    break;
                case ALLEGRO_EVENT_TIMER:
                    update();
                default:
                    break;
            }
        }
        draw();
    }
}

void Application::update() {
    current_state->update();
}

void Application::draw() {
    current_state->draw();
}

void Application::input(KeyEvent* ke) {
    current_state->input(ke);
}

void Application::set_game_state(State* s) {
    state_destroy();
    current_state = s;
    state_init();
}

void Application::state_init() {
    current_state->init();
}

void Application::state_destroy() {
    current_state->destroy();
}
