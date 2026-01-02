#include "../include/vectors.h"
#include <stdint.h>
#include <string.h>

bool SetItemVec(void *vec, void *item, size_t index, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(int*)item;

            return true;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(float*)item;

            return true;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(char*)item;

            return true;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            strcpy((char*)item, Vec->vec[index]);

            return true;
        }
        default: return false;
    }
}