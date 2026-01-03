#include "../include/vectors.h"

void* GetLastVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            if (Vec->size == 0) {
                return NULL;
            }

            return (void*)&Vec->vec[Vec->size - 1];
        }
        default: return NULL;
    }
}