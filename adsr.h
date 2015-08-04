/*
  adsr_envelope
    Returns a float between 0.0 and 1.0 - This is your ADSR envelope.
    
    A_LENGTH        Length of attack measured in samples.
    D_LENGTH        Length of decay measured in samples.
    S_LENGTH        Length of sustain measured in samples.
    R_LENGTH        Length of release measured in samples.
    S_LEVEL         Level (linear) of sustain. This should be between 0.0 and 1.0.
    sample_number   Compute ADSR envelope value for this sample.
*/

#ifdef __cplusplus
extern "C" {
#endif

float adsr_envelope(int A_LENGTH, int D_LENGTH, int S_LENGTH, int R_LENGTH, float S_LEVEL, int sample_number);

#ifdef __cplusplus
}
#endif
