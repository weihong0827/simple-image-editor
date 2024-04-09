#include "main.h"
#include "image.h"
#include "preset.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** access_files(char* dir_path, int* all) {
  char** files = (char **) malloc(sizeof(char *));
  DIR* directory = opendir(dir_path);
  struct dirent *f;
  char* path;
  int count = 0;
  int l;

  if (directory){
    printf("Directory opened. Would you like to apply the same edits to all ppms in this folder? Yes(1) No(0) \n");
    scanf("%d", all);
    while ((f = readdir(directory))) {
      if (!strcmp(f->d_name,".") || !strcmp(f->d_name,"..") ){
        continue;
      }
      count++;
      files = (char **) realloc(files, sizeof(char *) * (count+1));
      // path = realpath(f->d_name, NULL);
      // printf("%s\n", path);
      l = strlen(f->d_name);
      files[count - 1] = (char *) malloc(sizeof(char) * (strlen(dir_path) + l +2));
      strcpy(files[count - 1], dir_path);
      strcat(files[count - 1], "/");
      strcat(files[count - 1], f->d_name);
    }
    files[count] = NULL;
    closedir(directory);
  }
  else {
    printf("Loading single file.\n");
    *all = 0;
    l = strlen(dir_path);
    files = (char **) realloc(files, sizeof(char *) * (2));
    files[0] = (char *) malloc(sizeof(char) * (l+1));
    files[1] = NULL;
    strcpy(files[0], dir_path);
  }
  return files;
}

int main(int argc, char *argv[]) {
  char command[100];
  Image *currentImage = NULL;
  ProgramState currentState = INITIAL;
  float value;
  int cmd_index;
  int n = 0;
  int f =0;
  char** files;
  char* save_path;
  Image* editted;
  Preset** presets;
  int* apply_to_all = (int*) malloc(sizeof(int));

  currentState = WAITING_FOR_FILE;
  files = access_files(argv[1], apply_to_all);
  printf("%d\n", *apply_to_all);

  if (*apply_to_all) {
    printf("Applying to all.\n");
    presets = enter_edits();
    currentState = EDITING;
    while (files[n]) {
      printf("Editing %s\n", files[n]);
      currentImage = load_ppm(files[n]);
      f=0;
      while (presets[f]!= NULL) {
        commands[presets[f]->cmd_index].func(currentImage, presets[f]->value);
        f++;
      }
      printf("Edits to %s complete.\n", files[n]);
      currentState = EXPORTING;
      // save_path = (char *) malloc(sizeof(char) * (strlen(files[n]) + 5));
      // strncpy(save_path, files[n], strlen(files[n])-4);
      // save_path[strlen(files[n])-4] = '\0';
      // strcat(save_path, "edit.ppm");
      save_ppm("editted.ppm", currentImage);
      // free(save_path);
      // printf("freed");
      free_image(currentImage);
      n++;
    }
    printf("%d\n", f); 
    delete_preset(presets, f);
  }else{
    n=0;
    while (files[n]) {
      printf("Editting %s: \n", files[n]);
      presets = enter_edits();
      currentImage = load_ppm(files[n]);
      currentState = EDITING;
      f=0;
      while (presets[f]) {
        commands[presets[f]->cmd_index].func(currentImage, presets[f]->value);
        f++;
      }
      printf("Edits to %s complete.\n", files[n]);
      currentState = EXPORTING;
      // save_path = (char *) malloc(sizeof(char) * (strlen(files[n]) + 5));
      // strncpy(save_path, files[n], strlen(files[n])-4);
      // save_path[strlen(files[n])-4] = '\0';
      // strcat(save_path, "edit.ppm");
      save_ppm("editted.ppm", currentImage);
      // free(save_path);
      free_image(currentImage);
      delete_preset(presets, f);
      n++;
    }
    
  }
  
  for (int i = 0; i < n; i++) {
    free(files[i]);
  }
  free(files);
  // printf("Enter PPM file name to load: ");
  // scanf("%s", command);
  //
  // currentImage = load_ppm(command);
  // currentImage = load_ppm("./images/caked.ppm");
  // if (currentImage == NULL) {
  //   printf("Failed to load image.\n");
  //   return 1;
  // }

  // currentState = EDITING;
  // printf("Enter edit command (e.g., 'brightness +10'): ");
  // scanf("%s", command);

  // cmd_index = find_command(command);
  // cmd_index = find_command("noise");
  // if (cmd_index >= 0) {
    // scanf("%f", &value);
    // printf("%f,%d\n", value, cmd_index);
  //   commands[cmd_index].func(currentImage, 2);
  // } else {
  //   printf("Unknown command.\n");
  // }

  // printf("Enter output file name: ");
  // scanf("%s", command);
  // printf("Current state: %d\n", currentState);
  // printf("%s\n", command);

  // save_ppm(command, currentImage);
  

  // free_image(currentImage);
  return 0;

  return EXIT_SUCCESS;
}
