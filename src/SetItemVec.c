#include "../include/vectors.h"
#include <stdint.h>
#include <string.h>

bool SetItemVec(Vector* vec, void *item, size_t index) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(int*)item;

            return true;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(float*)item;

            return true;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(char*)item;

            return true;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = (char*)item;

            return true;
        }
        default: return false;
    }
}