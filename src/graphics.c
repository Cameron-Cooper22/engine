#ifndef ENGINE_GRAPHICS
#define ENGINE_GRAPHICS

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "errhandling.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

// Starts SDL and creates the window
bool init();

// Loads media
bool loadMedia();

// Frees memory and shuts down SDL
void close();


bool init() {
  bool success = true;

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    assert()
    success = false;
  } else {
    
    gWindow = SDL_CreateWindow( "Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL) {
      printf( "\t[-] Window could not be created. SDL_Error: %s\n", SDL_GetError() );
      success = false;
    } else {
      // Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }

  return success;
}

bool loadMedia() {
  bool success = true;

  // Load splash image
  gHelloWorld = SDL_LoadBMP( "/home/kinveth/Downloads/02_getting_an_image_on_the_screen/hello_world.bmp" );
  if( gHelloWorld == NULL ) {
    printf( "\t[-] Unable to loads image. SDL_Error: %s\n", SDL_GetError() );
    success = false;
  }
  return success;
}

void close() {

  // Deallocate surface
  SDL_FreeSurface( gHelloWorld );
  gHelloWorld = NULL;

  // Destroy the current window
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;

  // Quit the SDL subsystems
  SDL_Quit();
}

int main() {
  if (!init())
    exit(EXIT_FAILURE);
  if (!loadMedia())
    exit(EXIT_FAILURE);
  else {
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );
    
    SDL_Event e; bool quit = false;
    while( quit == false ) {
      while( SDL_PollEvent( &e ) ){
	if( e.type == SDL_QUIT )
	  quit = true;
      }
    }
  }

  close();
  return 0;
}


#endif
