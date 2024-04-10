#ifndef IMAGE_H
#define IMAGE_H
#pragma once
#include "adjustment_func.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* filename;
  int width, height;
  int max_color;
  int ***pixels;
} Image;


#define MAX_MAXVAL 65536

typedef struct {
  unsigned char r;  // Red
  unsigned char g;  // Green
  unsigned char b;  // Blue
} Pixel;

typedef struct {
  struct {
    char file_type[3];    // "Magic number"
    unsigned int width;   // Image width, ASCII decimal
    unsigned int height;  // Image height, ASCII decimal
    unsigned int maxval;  // Maximum color value (Maxval), ASCII decimal
  } Header;

  struct {
    Pixel* pixel_data;  // Image pixel data
  } Body;
} PPMFile;


/* Function prototypes*/
Image *load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void adjust_brightness(Image *img, float change);
void adjust_temperature(Image *img, float change);
void adjust_tint(Image *img, float change);
void adjust_shadow(Image *img, float change);
void free_image(Image *img);
void image_apply(Image *img, int (*func)(AdjustmentParms *parms),
                 AdjustmentParms *params);

void flatten(Image *img, float change);

void adjust_greyscale(Image *img, float change);
void adjust_negate(Image *img, float change);
void high_contrast(Image *img, float change);
void add_noise(Image *img, float change);

PPMFile* to_sdl_image(Image *img, PPMFile *ppm_data);
void free_sdl(PPMFile *ppm_data);
#endif
