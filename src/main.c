#include "main.h"
#include "image.h"
#include "preset.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **access_files(char *dir_path, int *all)
{
  char **files = (char **)malloc(sizeof(char *));
  DIR *directory = opendir(dir_path);
  struct dirent *f;
  int count = 0;
  int l;

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
      count++;
      files = (char **)realloc(files, sizeof(char *) * (count + 1));
      /* path = realpath(f->d_name, NULL);*/
      /* printf("%s\n", path);*/
      l = strlen(f->d_name);
      files[count - 1] = (char *)malloc(sizeof(char) * (strlen(dir_path) + l + 2));
      strcpy(files[count - 1], dir_path);
      strcat(files[count - 1], "/");
      strcat(files[count - 1], f->d_name);
    }
    files[count] = NULL;
    closedir(directory);
  }
  else
  {
    printf("Loading single file.\n");
    *all = 0;
    l = strlen(dir_path);
    files = (char **)realloc(files, sizeof(char *) * (2));
    files[0] = (char *)malloc(sizeof(char) * (l + 1));
    files[1] = NULL;
    strcpy(files[0], dir_path);
  }
  return files;
}

int main(int argc, char *argv[])
{
  Image *currentImage = NULL;
  ProgramState currentState = INITIAL;
  int n = 0;
  int f = 0;
  char **files;
  Preset **presets;
  int *apply_to_all = (int *)malloc(sizeof(int));
  int i;

  if (currentState == INITIAL)
  {
    printf("Welcome to the image editor.\n");
    if (argc < 2)
    {
      printf("Error! Please provide a file or directory path.\n");
      return EXIT_FAILURE;
    }
    files = access_files(argv[1], apply_to_all);
    printf("%d\n", *apply_to_all);
    currentState = EDITING;
  }

  if (*apply_to_all)
  {
    printf("Applying to all.\n");
    presets = enter_edits();
    currentState = EDITING;
    while (files[n])
    {
      printf("Editing %s\n", files[n]);
      currentImage = load_ppm(files[n]);
      f = 0;
      while (presets[f] != NULL)
      {
        commands[presets[f]->cmd_index].func(currentImage, presets[f]->value);
        f++;
      }
      printf("Edits to %s complete.\n", files[n]);
      currentState = EXPORTING;
      save_ppm("editted.ppm", currentImage);
      free_image(currentImage);
      n++;
    }
    printf("%d\n", f);
    delete_preset(presets, f);
  }
  else
  {
    n = 0;
    while (files[n])
    {
      printf("Editting %s: \n", files[n]);
      presets = enter_edits();
      currentImage = load_ppm(files[n]);
      currentState = EDITING;
      f = 0;
      while (presets[f])
      {
        commands[presets[f]->cmd_index].func(currentImage, presets[f]->value);
        f++;
      }
      printf("Edits to %s complete.\n", files[n]);
      currentState = EXPORTING;
      save_ppm("editted.ppm", currentImage);
      free_image(currentImage);
      delete_preset(presets, f);
      n++;
    }
  }

  for (i = 0; i < n; i++)
  {
    free(files[i]);
  }
  free(files);

  return EXIT_SUCCESS;
}
