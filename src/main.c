#include "main.h"
#include "image.h"
#include "preset.h"
#include "sdl_engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
SDLEngine engine;

Image **access_files(char *dir_path, int * all)
{
  Image** images = (Image**)malloc(sizeof(Image*));
  DIR *directory = opendir(dir_path);
  Image* image;
  struct dirent *f;
  int count = 0;
  char pathname[100];

  if (directory)
  {
    printf("Directory opened. Would you like to apply the same edits to all ppms in this folder? Yes(1) No(0) \n");
    scanf("%d", all);
    while ((f = readdir(directory)))
    {
      if (!strcmp(f->d_name, ".") || !strcmp(f->d_name, ".."))
      {
        continue;
      }
      snprintf(pathname, strlen(dir_path) + 2 + strlen(f->d_name), "%s/%s", dir_path, f->d_name);
      image = load_ppm(pathname);
      if (!image)
      {
        printf("Error loading image.\n");
        continue;
      }
      count++;
      images = (Image**) realloc(images, sizeof(Image*) * (count+1));
      images[count - 1] = (Image *)malloc(sizeof(Image));
      images[count-1] = image;
    }
    images[count] = NULL;
    closedir(directory);
  }
  else
  {
    image = load_ppm(dir_path);
    *all = 0;
    if (!image)
    {
      printf("Error loading image.\n");
      return NULL;
    }
    printf("Loading single file.\n");
    images = (Image**) realloc(images, sizeof(Image*) *2);
    images[0] = (Image *)malloc(sizeof(Image));
    images[0] = image;
    images[1] = NULL;
  }
  return images;
}

int apply_edits(Image *image, Preset **presets)
{
  int i = 0;
  int init_succeeded;
  printf("apply edits function %s\n", image->filename);
  PPMFile* ppm_data = (PPMFile*) malloc(sizeof(PPMFile));
  ppm_data->Body.pixel_data = (Pixel*) malloc(sizeof(Pixel) * image->width * image->height);
  to_sdl_image(image, ppm_data);
  printf("apply edits function");
  init_succeeded = initialize_engine(&engine, image->filename, ppm_data);
  if (init_succeeded) {
    run(&engine);
  }
  while (presets[i])
  {
    destroy_texture();
    commands[presets[i]->cmd_index].func(image, presets[i]->value);
    (&engine)->is_running = 1;
    to_sdl_image(image, ppm_data);
    reinit_renderer(&(&engine)->renderer, ppm_data);
    i++;
    run(&engine);
  }
  terminate_engine(&engine);
  free_sdl(ppm_data);
  return i;
}

int check_export(void){
  int export;
  printf("Would you like to export the image? Yes(1) No(0)\n");
  scanf("%d", &export);
  return export;

}

int main(int argc, char *argv[])
{
  Image *currentImage = NULL;
  ProgramState currentState = LOAD_IMAGES;
  int n = 0;
  Image** images;
  Preset **presets;
  int * all; 
  int i;
  int p;
  char input[200];

  while(currentState!=EXIT){
    if (currentState == LOAD_IMAGES)
    {
      all= (int *)malloc(sizeof(int));
      printf("Welcome to the image editor.\n");
      while(1){
        printf("Please provide file/folder path\n");
        scanf("%s", input);
        if (!strcmp(input, "exit")) {
          currentState = EXIT;
          break;
        }
        images = access_files(input, all);
        if(!images)
        {
          printf("Error accessing images.\n");
          continue;
        }
        printf("Images loaded.\n");
        n=0;
        while(images[n])
        {
          printf("%s, ", images[n]->filename);
          n++;
        }
        printf("\n");
        currentState = EDITING;
        break;
      }
    }
    else if(currentState == EDITING){
      if (*all)
      {
        printf("Applying to all.\n");
        presets = enter_edits();
        n=0;
        while (images[n])
        {
          currentImage = images[n];
          printf("Editing %s\n", images[n]->filename);
          p = apply_edits(currentImage, presets);
          printf("Edits to %s complete.\n", images[n]->filename);
          if(check_export())
          {
            currentState = EXPORTING;
            save_ppm(images[n]->filename, currentImage);
          }
          n++;
        }
        export_preset(presets);
        delete_preset(presets, p);
      }
      else
      {
        n = 0;
        while (images[n])
        {
          printf("Editting %s: \n", images[n]->filename);
          presets = enter_edits();
          currentImage = images[n];
          currentState = EDITING;
          p = apply_edits(currentImage, presets);
          printf("Edits to %s complete.\n", images[n]->filename);
          if(check_export())
          {
            currentState = EXPORTING;
            save_ppm(images[n]->filename, currentImage);
          }
          export_preset(presets);
          delete_preset(presets, p);
          n++;
        }
      }
      currentState = LOAD_IMAGES;
      free(all);
      for (i = 0; i < n; i++)
        {
          free_image(images[i]);
        }
      free(images);
    }
  }


  return EXIT_SUCCESS;

}