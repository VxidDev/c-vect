#include "../include/vectors.h"

ptrdiff_t GetCapacityVec(void *vec, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            return ((const struct IntVec*)vec)->capacity;
        }
        case VEC_FLOAT: {
            return ((const struct FloatVec*)vec)->capacity;
        }
        case VEC_STRING: {
            return ((const struct FloatVec*)vec)->capacity;
        }
        case VEC_CHAR: {
            return ((const struct FloatVec*)vec)->capacity;
        }
        default: return -1;
    }
}