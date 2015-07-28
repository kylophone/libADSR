#include <math.h>

float adsr_envelope(int A_LENGTH, int D_LENGTH, int S_LENGTH, int R_LENGTH, float S_LEVEL, int sample_number)
{
  if (sample_number > A_LENGTH + D_LENGTH + S_LENGTH) {
    /* RELEASE */
    return S_LEVEL * (1.0 - (log(1 + (((float) (sample_number - A_LENGTH - D_LENGTH - S_LENGTH) / R_LENGTH) * (M_E - 1)))));
  } else if (sample_number > A_LENGTH + D_LENGTH) {
    /* SUSTAIN */
    return S_LEVEL;
    //return 1.0;
  } else if (sample_number > A_LENGTH) {
    /* DECAY */
    return S_LEVEL - (S_LEVEL - 1.0 - ((S_LEVEL - 1.0) * log(1.0 + (((float) (sample_number - A_LENGTH) / D_LENGTH) * (M_E - 1)))));
  } else {
    /* ATTACK */
    return log(1.0 + ((float) sample_number / A_LENGTH * (M_E - 1))); 
  }
}
