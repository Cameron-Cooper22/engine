#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

int main() {
  /* If using multiple subsystems, OR them together in SDL_init
   * Do this by SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) and more.
   */
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    perror("Failed to initialize the SDL2 library\n");
    return -1;
  }

  SDL_Window *window = SDL_CreateWindow("4C-Engine", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, 680, 480, 0);

  if (!window) {
    perror("Failed to create window\n");
    return -1;
  }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);

  if (!window_surface) {
    perror("Failed to retrieve surface from the window");
    return -1;
  }

  SDL_UpdateWindowSurface(window);
  SDL_Delay(5000);

  return 0;
}
