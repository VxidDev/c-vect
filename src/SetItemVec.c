#include "../include/vectors.h"
#include <stdint.h>
#include <string.h>

bool SetItemVec(void *vec, void *item, size_t index, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(int*)item;

            return true;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(float*)item;

            return true;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            Vec->vec[index] = *(char*)item;

            return true;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            strcpy((char*)item, Vec->vec[index]);

            return true;
        }
        default: return false;
    }
}