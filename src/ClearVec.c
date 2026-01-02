#include "../include/vectors.h"

void ClearVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            Vec->size = 0;
            break;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            Vec->size = 0;
            break;
        }
        case VEC_STRING: {
            StrVec* Vec = ( StrVec*)vec;

            Vec->size = 0;
            break;
        }
        case VEC_CHAR: {
            CharVec* Vec = ( CharVec*)vec;

            Vec->size = 0;
            break;
        }
    }
}