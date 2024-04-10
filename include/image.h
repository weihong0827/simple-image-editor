#ifndef IMAGE_H
#define IMAGE_H
#include "adjustment_func.h"

typedef struct {
  char* filename;
  int width, height;
  int max_color;
  int ***pixels;
} Image;

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
#endif
