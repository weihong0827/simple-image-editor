#include "preset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Preset * init_preset(float value,  int cmd_index){
  Preset * preset = (Preset *) malloc(sizeof(Preset));
  preset->value = value;
  preset->cmd_index = cmd_index;
  return preset;
}

void delete_preset(Preset** preset, int f){
  int i;

  for (i =0; i < f; i++){
    free(preset[i]);
  }
  
  free(preset);
}

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

Preset** enter_edits() {
  char command[100];
  float value;
  int count = 0;
  Preset** presets = (Preset **) malloc(sizeof(Preset*));
  int cmd_index;

  while (1) {
    printf("Enter edit command (e.g., 'brightness') or 'exit' to end edit: ");
    scanf("%s", command);
    if (strcmp(command, "exit") == 0) {
      presets[count] = NULL;
      return presets;
    }
    printf("%s\n", command);
    cmd_index = find_command(command);
    if (cmd_index >= 0) {
      count++;
      printf("Enter value (e.g., +10): ");
      scanf("%f", &value);
      presets = (Preset **) realloc(presets, sizeof(Preset*) * (count + 1));
      presets[count - 1] = init_preset(value, cmd_index);
    }else{
      printf("Unknown command.\n");
      continue;
    }
  }
}
