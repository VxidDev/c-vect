#include "../include/vectors.h"

void* PopVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            if (Vec->size == 0) {
                printf("Vector's size is 0.\n");
                return NULL;
            }

            Vec->size--;

            return GetLastVec(vec);
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

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