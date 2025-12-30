#include "../include/vectors.h"

ptrdiff_t GetSizeVec(void *vec, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            return ((const struct IntVec*)vec)->size;
        }
        case VEC_FLOAT: {
            return ((const struct FloatVec*)vec)->size;
        }
        case VEC_STRING: {
            return ((const struct FloatVec*)vec)->size;
        }
        case VEC_CHAR: {
            return ((const struct FloatVec*)vec)->size;
        }
        default: return -1;
    }
}