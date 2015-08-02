#include <math.h>

#ifndef M_E
#define M_E 2.7182818284590452354
#endif

#ifdef __cplusplus
extern "C" {
#endif

float adsr_envelope(int A_LENGTH, int D_LENGTH, int S_LENGTH, int R_LENGTH, float S_LEVEL, int sample_number)
{
  if (S_LEVEL < 0.0) S_LEVEL = 0.0;
  if (S_LEVEL > 1.0) S_LEVEL = 1.0;
  
  if (sample_number > A_LENGTH + D_LENGTH + S_LENGTH + R_LENGTH) {
    /* SILENCE */
    return 0.0;  
  } else if (sample_number > A_LENGTH + D_LENGTH + S_LENGTH) {
    /* RELEASE */
    return S_LEVEL * (1.0 - (log(1 + (((float) (sample_number - A_LENGTH - D_LENGTH - S_LENGTH) / R_LENGTH) * (M_E - 1)))));
  } else if (sample_number > A_LENGTH + D_LENGTH) {
    /* SUSTAIN */
    return S_LEVEL;
  } else if (sample_number > A_LENGTH) {
    /* DECAY */
    return S_LEVEL - (S_LEVEL - 1.0 - ((S_LEVEL - 1.0) * log(1.0 + (((float) (sample_number - A_LENGTH) / D_LENGTH) * (M_E - 1)))));
  } else {
    /* ATTACK */
    return log(1.0 + ((float) sample_number / A_LENGTH * (M_E - 1))); 
  }
}

#ifdef __cplusplus
}
#endif
