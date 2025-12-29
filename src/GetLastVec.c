#include "../include/vectors.h"

void* GetLastVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        default: return NULL;
    }
}