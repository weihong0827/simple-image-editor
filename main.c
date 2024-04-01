#include "main.h"
#include "image.h"

int main(int argc, char *argv[])
{
  char command[100];
  Image *currentImage = NULL;
  ProgramState currentState = INITIAL;

  currentState = WAITING_FOR_FILE;
  printf("Enter PPM file name to load: ");
  scanf("%s", command);

  currentImage = load_ppm(command);
  if (currentImage == NULL)
  {
    printf("Failed to load image.\n");
    return 1;
  }

  currentState = EDITING;
  printf("Enter edit command (e.g., 'brightness +10'): ");
  scanf("%s", command);

  if (strncmp(command, "brightness", 10) == 0)
  {
    int brightness;
    scanf("%d", &brightness);
    adjust_brightness(currentImage, brightness);
  }

  if (strncmp(command, "temperature", 11) == 0)
  {
    int temperature;
    scanf("%d", &temperature);
    adjust_temperature(currentImage, temperature);
  }

  if (strncmp(command, "tint", 4) == 0)
  {
    int tint;
    scanf("%d", &tint);
    adjust_tint(currentImage, tint);
  }

  currentState = EXPORTING;
  printf("Enter output file name: ");
  scanf("%s", command);
  printf("Current state: %d\n", currentState);
  save_ppm(command, currentImage);

  free_image(currentImage);
  return 0;

  return EXIT_SUCCESS;
}
