#pragma once

#include <SDL3/SDL.h>
#include <stdio.h>

#include "image.h"

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  const char *window_title;
  int screen_width;
  int screen_height;
  Uint32 render_flags;
} CustomRenderer;

int initialize_renderer(CustomRenderer *renderer, PPMFile*image, char *window_title,
                        const int window_width, const int window_height,
                        Uint32 flags);

void draw(CustomRenderer *renderer);
void reinit_renderer(CustomRenderer *renderer, PPMFile* image);
void terminate_renderer(CustomRenderer *renderer);
void destroy_texture();