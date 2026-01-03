#include "../include/vectors.h"

ptrdiff_t GetSizeVec(Vector *vec) {
    switch (vec->type) {
        case VEC_INT: {
            return ((const IntVec*)vec->data)->size;
        }
        case VEC_FLOAT: {
            return ((const FloatVec*)vec->data)->size;
        }
        case VEC_STRING: {
            return ((const FloatVec*)vec->data)->size;
        }
        case VEC_CHAR: {
            return ((const FloatVec*)vec->data)->size;
        }
        default: return -1;
    }
}