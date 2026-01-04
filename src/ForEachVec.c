#include "../include/vectors.h"

void ForEachVec(Vector *vec, void (*func)(void *, size_t)) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            for (size_t i = 0; i < Vec->size; i++) {
                func(GetItemFromVec(vec , i) , i);
            }

            return;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            for (size_t i = 0; i < Vec->size; i++) {
                func(GetItemFromVec(vec , i) , i);
            }

            return;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            for (size_t i = 0; i < Vec->size; i++) {
                func(GetItemFromVec(vec , i) , i);
            }

            return;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            for (size_t i = 0; i < Vec->size; i++) {
                func(GetItemFromVec(vec , i) , i);
            }

            return;
        }
    }
}