#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

const int screenWidth = 640;
const int screenHeight = 480;

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

// The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init();  // initializes platform
bool loadRes();
void close();

int main(int argc, char* args[]) {
  if (!init()) {
    printf("Failed to initialize!\n");
    atexit(close);
    return 1;
  }
  if (!loadRes()) {
    printf("Failed to load resource!\n");
    return 1;
  }

  // assign the image to the window
  SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

  SDL_UpdateWindowSurface(gWindow);

  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    // poll all events
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) quit = true;
    }
  }

  return 0;
}

bool init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight,
                             SDL_WINDOW_SHOWN);
  if (gWindow == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  gScreenSurface = SDL_GetWindowSurface(gWindow);
  return true;
}

bool loadRes() {
  auto imagePath = "hello-world.bmp";
  gHelloWorld = SDL_LoadBMP(imagePath);
  if (gHelloWorld == NULL) {
    printf("Unable to load image %s! SDL Error: %s\n", imagePath,
           SDL_GetError());
    return false;
  }

  return true;
}

void close() {
  if (gHelloWorld) {
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
  }
  if (gWindow) {
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
  }
  SDL_Quit();
}
