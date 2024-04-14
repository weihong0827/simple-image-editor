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
    {"greyscale", adjust_greyscale},
    {"tint", adjust_tint},
};

Preset *init_preset(float value, int cmd_index, int preset_step) {
  Preset *preset = (Preset *)malloc(sizeof(Preset));
  preset->value = value;
  preset->cmd_index = cmd_index;
  preset->preset_step = preset_step;
  printf("Preset initialized.\n");
  return preset;
}

void delete_preset(Preset **preset, int f) {
  int i;

  for (i = 0; i < f; i++) {
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
void parseCSV(Preset ***presets, char *path, int *count) {
  FILE *file = fopen(path, "r");
  char line[1024];
  int cmd_index;
  float value;
  char *token;
  int preset_step = *count;
  char *command;
  int i;
  while (fgets(line, 1024, file)) {
    token = strtok(line, ",");
    if (token == NULL)
      continue;

    command = token;
    token = strtok(NULL, ",");
    if (token == NULL)
      continue;

    value = atof(token);
    cmd_index = find_command(command);

    if (cmd_index >= 0) {
      *presets = (Preset **)realloc(*presets, sizeof(Preset *) * (*count + 1));
      if (*presets == NULL) {
        fprintf(stderr, "Failed to reallocate memory\n");
        return;
      }
      (*presets)[*count] = init_preset(value, cmd_index, preset_step + 1);
      (*count)++;
    } else {
      printf("Unknown command.\n");
    }
  }
  *presets = (Preset **)realloc(*presets, sizeof(Preset *) * (*count + 1));
  for (i = 0; i < *count; i++) {
    printf("Command: %s, Value: %f\n",
           commands[(*presets)[i]->cmd_index].command, (*presets)[i]->value);
  }
  fclose(file);
}

Preset **enter_edits(void) {
  char command[100];
  float value;
  int count = 0;
  Preset **presets = (Preset **)malloc(sizeof(Preset *));
  int cmd_index;
  int i;
  int last_step = 0;
  int stored = 0;

  while (1) {
    printf("Enter edit command (e.g., 'brightness') or 'csv' to input presets or 'done' to apply edits: ");
    scanf("%s", command);
    if (strcmp(command, "done") == 0) {
      for (i = 0; i < count; i++) {
        printf("Command: %s, Value: %f, step:%d\n",
               commands[presets[i]->cmd_index].command, presets[i]->value,
               presets[i]->preset_step);
      }
      presets[count] = NULL;
      return presets;
    }
    if (strcmp(command, "undo") == 0) {
      Preset *preset = presets[count - 1];
      last_step = preset->preset_step;
      while (presets[count - 1]->preset_step == last_step && count > 1) {
        printf("Deleting %s\n",
               commands[presets[count - 1]->cmd_index].command);
        free(presets[count - 1]);
        count--;
      }
      continue;
    }
    if (strcmp(command, "csv") == 0) {
      printf("Enter path to CSV file: ");
      scanf("%s", command);
      printf("reading csv file %s\n", command);
      parseCSV(&presets, command, &count);
      continue;
    }
    printf("%s\n", command);
    cmd_index = find_command(command);
    if (cmd_index >= 0) {
      count++;
      printf("Enter value (e.g., +10): ");
      stored = scanf("%f", &value);
      while (!stored) {
        while (getchar() != '\n');
        printf("Invalid value. Please enter a number.\n");
        stored = scanf("%f", &value);
      }
      presets = (Preset **)realloc(presets, sizeof(Preset *) * (count + 1));
      presets[count - 1] = init_preset(value, cmd_index, count);
    } else {
      printf("Unknown command.\n");
      continue;
    }
  }
}

void save_csv(Preset **presets, char *path) {
  FILE *file = fopen(path, "w");
  int i = 0;
  while (presets[i]) {
    fprintf(file, "%s,%f\n", commands[presets[i]->cmd_index].command,
            presets[i]->value);
    i++;
  }
  fclose(file);
}
void export_preset(Preset **presets) {
  char path[100];
  int save;
  int stored;
  printf("Do you want to save the preset to a file? Yes(1) No(0)\n");
  stored = scanf("%d", &save);
  while (!stored) {
    while (getchar() != '\n');
    printf("Invalid value. Please enter a number.\n");
    stored = scanf("%d", &save);
  }
  
  if (!save) {
    return;
  }
  printf("Enter path to save preset: ");
  scanf("%s", path);
  save_csv(presets, path);
}
