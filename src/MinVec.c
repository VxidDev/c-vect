#include "../include/vectors.h"

void* MinVec(Vector* vec) {
    if (vec == NULL) return NULL;

    ptrdiff_t size = GetSizeVec(vec);
    if (size == 0 || size == -1) return NULL;
    
    switch (vec->type) {
        case VEC_INT: {
            int* lowest = (int*)GetItemFromVec(vec, 0);

            for (ptrdiff_t i = 1; i < size; i++) {
                int item = *(int*)GetItemFromVec(vec, i);
                if (*lowest > item) *lowest = item;
            }

            return lowest;
        }
        case VEC_FLOAT: {
            float* lowest = (float*)GetItemFromVec(vec, 0);

            for (ptrdiff_t i = 1; i < size; i++) {
                float item = *(float*)GetItemFromVec(vec, i);
                if (*lowest > item) *lowest = item;
            }

            return lowest;
        }
        default: return NULL;
    }
}