#include "main.h"
#include "image.h"

Command commands[] = {
    {"brightness", adjust_brightness},
    {"shadow", adjust_shadow},
    {"high_contrast", high_contrast},
    {"noise", add_noise},
    {"flatten", flatten},
    {"negate", adjust_negate},
    {"temperature", adjust_temperature},
    {"tint", adjust_tint},

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
  cmd_index = find_command("noise");
  if (cmd_index >= 0) {
    // scanf("%f", &value);
    // printf("%f,%d\n", value, cmd_index);
    commands[cmd_index].func(currentImage, 2);
  } else {
    printf("Unknown command.\n");
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
