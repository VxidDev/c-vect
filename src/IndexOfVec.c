#include "../include/vectors.h"
#include <stddef.h>

ptrdiff_t IndexOfVec(Vector *vec, void *item) {
    switch (vec->type) {
        case VEC_INT: {
            const IntVec* Vec = (const IntVec*)vec->data;
            const int Item = *(const int*)item;

            for (size_t i = 0; i < Vec->size; i++) if (Vec->vec[i] == Item) return i;

            return -1;
        }
        case VEC_CHAR: {
            const CharVec* Vec = (const CharVec*)vec->data;
            const char Item = *(const char*)item;

            for (size_t i = 0; i < Vec->size; i++) if (Vec->vec[i] == Item) return i;

            return -1;
        }
        case VEC_FLOAT: {
            const FloatVec* Vec = (const FloatVec*)vec->data;
            const float Item = *(const float*)item;

            for (size_t i = 0; i < Vec->size; i++) if (Vec->vec[i] == Item) return i;

            return -1;
        }
        case VEC_STRING: {
            const StrVec* Vec = (const StrVec*)vec->data;
            const char* Item = (const char*)item;

            for (size_t i = 0; i < Vec->size; i++) if (Vec->vec[i] == Item) return i;

            return -1;
        }
        default: return -1;
    }
}