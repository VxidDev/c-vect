#include "../include/vectors.h"

void ClearVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            Vec->size = 0;
            break;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            Vec->size = 0;
            break;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            Vec->size = 0;
            break;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            Vec->size = 0;
            break;
        }
    }
}