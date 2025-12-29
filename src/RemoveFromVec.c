#include "../include/vectors.h"

bool RemoveFromVec(void* vec , size_t index , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return false;
            }

            for (size_t i = index; i < Vec->size - 1; i++) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return false;
            }

            for (size_t i = index; i < Vec->size - 1; i++) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return false;
            }

            for (size_t i = index; i < Vec->size - 1; i++) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return false;
            }

            for (size_t i = index; i < Vec->size - 1; i++) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        default: return false;
    }
}