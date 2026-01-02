#include "../include/vectors.h"

bool RemoveFromVec(void* vec , size_t index , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

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
            CharVec* Vec = (CharVec*)vec;

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
            FloatVec* Vec = (FloatVec*)vec;

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
            StrVec* Vec = (StrVec*)vec;

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