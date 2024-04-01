#ifndef IMAGE_H
#define IMAGE_H

typedef struct
{
    int width, height;
    int max_color;
    int ***pixels;
} Image;

/* Function prototypes*/
Image *load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void adjust_brightness(Image *img, int change);
void adjust_temperature(Image *img, int change);
void adjust_tint(Image *img, int change);
void free_image(Image *img);

#endif
