#include "../include/vectors.h"

void* SumVec(Vector* vec) {
    ptrdiff_t size = GetSizeVec(vec);
    if (size <= 0) return NULL;

    switch (vec->type) {
        case VEC_INT: {
            int* result = (int*)GetItemFromVec(vec, 0);
            for (ptrdiff_t i = 0; i < size; i++) {
                *result += *(int*)GetItemFromVec(vec, i);
            }

            return result;
        }
        case VEC_FLOAT: {
            float* result = (float*)GetItemFromVec(vec, 0);
            for (ptrdiff_t i = 0; i < size; i++) {
                *result += *(float*)GetItemFromVec(vec, i);
            }

            return result;
        }
        default: return NULL;
    }
}