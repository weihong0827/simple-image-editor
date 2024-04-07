#include "main.h"

Command commands[] = {
    {"brightness", 10, adjust_brightness},
    {"shadow", 6, adjust_shadow},

};
int find_command(const char *name) {
  int i;
  int num_commands = sizeof(commands) / sizeof(commands[0]);
  for (i = 0; i < num_commands; i++) {
    if (strcmp(commands[i].command, name) == 0) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  char command[100];
  Image *currentImage = NULL;
  ProgramState currentState = INITIAL;
  float value;
  int cmd_index;

  currentState = WAITING_FOR_FILE;
  // printf("Enter PPM file name to load: ");
  // scanf("%s", command);
  //
  // currentImage = load_ppm(command);
  currentImage = load_ppm("cake.ppm");
  if (currentImage == NULL) {
    printf("Failed to load image.\n");
    return 1;
  }

  currentState = EDITING;
  // printf("Enter edit command (e.g., 'brightness +10'): ");
  // scanf("%s", command);

  // cmd_index = find_command(command);
  cmd_index = find_command("shadow");
  if (cmd_index >= 0) {
    // scanf("%f", &value);
    // printf("%f,%d\n", value, cmd_index);
    commands[cmd_index].func(currentImage, 0.5);
  } else {
    printf("Unknown command.\n");
  }

  if (strncmp(command, "temperature", 11) == 0) {
    int temperature;
    scanf("%d", &temperature);
    adjust_temperature(currentImage, temperature);
  }

  if (strncmp(command, "tint", 4) == 0) {
    int tint;
    scanf("%d", &tint);
    adjust_tint(currentImage, tint);
  }

  currentState = EXPORTING;

  // printf("Enter output file name: ");
  // scanf("%s", command);
  // printf("Current state: %d\n", currentState);
  // printf("%s\n", command);

  // save_ppm(command, currentImage);
  save_ppm("test.ppm", currentImage);

  free_image(currentImage);
  return 0;

  return EXIT_SUCCESS;
}
