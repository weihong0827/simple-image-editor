enum AdjustmentType { BRIGHTNESS, SHADOW };
typedef struct {
  enum AdjustmentType type;
  float adjustment_value;
  int pixel_value;
  int min_brightness;
  int max_brightness;
} AdjustmentParms;

AdjustmentParms *initParam(enum AdjustmentType type, float adjustment_value,
                           int min_brightness, int max_brightness);
int shadow_func(AdjustmentParms *params);
int brightness_func(AdjustmentParms *params);
