static NPY_INLINE uint32_t next_uint32(bitgen_t *bitgen_state);
static NPY_INLINE uint64_t next_uint64(bitgen_t *bitgen_state);
static NPY_INLINE float next_float(bitgen_t *bitgen_state);

//Random generators for external use

float random_standard_uniform_f(bitgen_t *bitgen_state);
double random_standard_uniform(bitgen_t *bitgen_state);
void random_standard_uniform_fill(bitgen_t *bitgen_state, npy_intp cnt, double *out);
