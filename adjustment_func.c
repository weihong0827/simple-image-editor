#include "adjustment_func.h"
#include <stdio.h>
#include <stdlib.h>

AdjustmentParms *initParam(enum AdjustmentType type, float adjustment_value,
                           int min_brightness, int max_brightness) {

  AdjustmentParms *params = (AdjustmentParms *)malloc(sizeof(AdjustmentParms));
  params->type = type;
  params->adjustment_value = adjustment_value;
  params->min_brightness = min_brightness;
  params->max_brightness = max_brightness;
  return params;
}

int shadow_func(AdjustmentParms *params) {
  int result;
  if (params->type != SHADOW) {
    printf("Error: shadow function called with wrong parameters\n");
    return -1;
  }
  if (params->adjustment_value > 1) {

    result = params->pixel_value +
             (params->adjustment_value - 1) * (255 - params->pixel_value);
    printf("Shadow: %d\n", result);

  } else {
    result = params->pixel_value * params->adjustment_value;
  }
  return result;
}

int brightness_func(AdjustmentParms *params) {
  int result;
  if (params->type != BRIGHTNESS) {
    printf("Error: brightness function called with wrong parameters\n");
    return -1;
  }
  result = params->pixel_value + params->adjustment_value;

  return result;
}
