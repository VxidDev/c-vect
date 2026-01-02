#include "../include/vectors.h"

void* GetLastVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        default: return NULL;
    }
}