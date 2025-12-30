#include "../include/vectors.h"

bool ExtendVec(void *vec, size_t size, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (Vec->size >= size || Vec->capacity >= size) {
                printf("Can't extend to lower size. Use ShrinkVec() instead.\n");
                return false;
            }

            void* ptr = realloc(Vec->vec , size * sizeof(int));

            if (ptr != NULL) {
                Vec->vec = (int*)ptr;
                Vec->capacity = size;

                return true;
            }

            return false;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->size >= size || Vec->capacity >= size) {
                printf("Can't extend to lower size. Use ShrinkVec() instead.\n");
                return false;
            }

            void* ptr = realloc(Vec->vec , size * sizeof(float));

            if (ptr != NULL) {
                Vec->vec = (float*)ptr;
                Vec->capacity = size;

                return true;
            }

            return false;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->size >= size || Vec->capacity >= size) {
                printf("Can't extend to lower size. Use ShrinkVec() instead.\n");
                return false;
            }

            void* ptr = realloc(Vec->vec , size * sizeof(char));

            if (ptr != NULL) {
                Vec->vec = (char*)ptr;
                Vec->capacity = size;

                return true;
            }

            return false;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->size >= size || Vec->capacity >= size) {
                printf("Can't extend to lower size. Use ShrinkVec() instead.\n");
                return false;
            }

            void* ptr = realloc(Vec->vec , size * sizeof(char*));

            if (ptr != NULL) {
                Vec->vec = (char**)ptr;
                Vec->capacity = size;

                return true;
            }

            return false;
        }
        default: return false;
    }
}