#include "../include/vectors.h"

ptrdiff_t GetCapacityVec(void *vec, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            return ((const IntVec*)vec)->capacity;
        }
        case VEC_FLOAT: {
            return ((const FloatVec*)vec)->capacity;
        }
        case VEC_STRING: {
            return ((const FloatVec*)vec)->capacity;
        }
        case VEC_CHAR: {
            return ((const FloatVec*)vec)->capacity;
        }
        default: return -1;
    }
}