#include "../include/vectors.h"

void* PopVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec, VEC_INT);
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec, VEC_FLOAT);
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec, VEC_CHAR);
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec , VEC_STRING);
        }
        default: return NULL;
    }
}