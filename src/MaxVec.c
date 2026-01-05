#include "../include/vectors.h"

void* MaxVec(Vector* vec) {
    if (vec == NULL) return NULL;

    ptrdiff_t size = GetSizeVec(vec);
    if (size == 0 || size == -1) return NULL;
    
    switch (vec->type) {
        case VEC_INT: {
            int* highest = calloc(1 , sizeof(int));

            for (ptrdiff_t i = 0; i < size; i++) {
                int item = *(int*)GetItemFromVec(vec, i);
                if (*highest < item) *highest = item;
            }

            return highest;
        }
        case VEC_FLOAT: {
            float* highest = calloc(1 , sizeof(float));

            for (ptrdiff_t i = 0; i < size; i++) {
                float item = *(float*)GetItemFromVec(vec, i);
                if (*highest < item) *highest = item;
            }

            return highest;
        }
        default: return NULL;
    }
}