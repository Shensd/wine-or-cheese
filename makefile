all:
	g++ main.cpp application.cpp string_funcs.cpp example_state.cpp state_main_menu.cpp resource_manager.cpp -o program.out -std=c++11 `pkg-config --cflags --libs allegro-5 allegro_primitives-5 allegro_image-5`
