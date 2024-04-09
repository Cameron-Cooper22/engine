all:
	gcc -o fc-engine engine.c $(shell pkg-config --cflags --libs sdl2)
