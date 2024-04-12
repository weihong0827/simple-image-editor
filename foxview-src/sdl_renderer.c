#include "sdl_renderer.h"

SDL_Texture *image_texture;

/*editted to allow the engine to initialise and render the specific parsed PPM image*/
int initialize_renderer(CustomRenderer *renderer, PPMFile* image, char *window_title,
                        const int window_width, const int window_height,
                        Uint32 flags) {
  renderer->window_title = window_title;
  renderer->screen_width = window_width;
  renderer->screen_height = window_height;
  renderer->render_flags = flags;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    // In the case that the SDL failed to initialize ...
    printf("SDL_Init() failed: %s\n", SDL_GetError());
    return 1;
  }

  renderer->window =
      SDL_CreateWindow(renderer->window_title, renderer->screen_width,
                       renderer->screen_height, renderer->render_flags);

  if (renderer->window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  renderer->renderer =
      SDL_CreateRenderer(renderer->window, 0,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer->renderer == NULL) {
    // In the case that the renderer could not be made...
    printf("Could not create renderer: %s\n", SDL_GetError());
    return 1;
  }

  // Create an SDL surface from pixel data
  SDL_Surface *pixel_surface = SDL_CreateSurfaceFrom(
      image->Body.pixel_data, renderer->screen_width, renderer->screen_height,
      image->Header.width * sizeof(Pixel), SDL_PIXELFORMAT_RGB24);

  // Create a texture from the surface
  image_texture =
      SDL_CreateTextureFromSurface(renderer->renderer, pixel_surface);
  SDL_DestroySurface(pixel_surface);

  return 0;
}

/*created new texture from a new image and parse into existing renderer object.*/
void reinit_renderer(CustomRenderer *renderer, PPMFile* image){
  SDL_Surface *pixel_surface = SDL_CreateSurfaceFrom(
      image->Body.pixel_data, renderer->screen_width, renderer->screen_height,
      image->Header.width * sizeof(Pixel), SDL_PIXELFORMAT_RGB24);

  // Create a texture from the surface
  image_texture =
      SDL_CreateTextureFromSurface(renderer->renderer, pixel_surface);
  SDL_DestroySurface(pixel_surface);
}

void draw(CustomRenderer *renderer) {
  SDL_RenderClear(renderer->renderer);
  SDL_RenderTexture(renderer->renderer, image_texture, NULL, NULL);
  SDL_RenderPresent(renderer->renderer);
}

void terminate_renderer(CustomRenderer *renderer) {
  SDL_DestroyTexture(image_texture);
  SDL_DestroyRenderer(renderer->renderer);
  SDL_DestroyWindow(renderer->window);
}

/*created to only destroy the texture created instead of the whole renderer,
allowing preview of a new image without destroying the whole renderer object*/
void destroy_texture(){
  SDL_DestroyTexture(image_texture);
}