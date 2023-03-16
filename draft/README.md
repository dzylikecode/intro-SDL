# draft

## key

```cpp
// Handle events on queue
while (SDL_PollEvent(&e) != 0) {
  if (e.type == SDL_QUIT) {
    quit = true;
  }
  // User presses a key
  else if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {
      case SDLK_UP:
        // deal with the event
        break;
    }
  }
}
```

## surface

```cpp
optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
```

将图片格式转化为 screen 一致的格式, 便于 blit

## image

```cpp
int imgFlags = IMG_INIT_PNG;
if (!(IMG_Init(imgFlags) & imgFlags)) {
  printf("SDL_image could not initialize! SDL_image Error: %s\n",
         IMG_GetError());
}

SDL_Surface* loadedSurface = IMG_Load(path.c_str());

// Quit SDL subsystems
IMG_Quit();
```

## References

[Lazy Foo' Productions - Texture Loading and Rendering](https://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php)
