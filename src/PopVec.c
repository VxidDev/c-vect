#include "../include/vectors.h"

void* PopVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        default: return NULL;
    }
}