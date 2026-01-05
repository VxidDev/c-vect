#include "../include/vectors.h"

ptrdiff_t GetCapacityVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            return ((const IntVec*)vec->data)->capacity;
        }
        case VEC_FLOAT: {
            return ((const FloatVec*)vec->data)->capacity;
        }
        case VEC_STRING: {
            return ((const StrVec*)vec->data)->capacity;
        }
        case VEC_CHAR: {
            return ((const CharVec*)vec->data)->capacity;
        }
        default: return -1;
    }
}