#include "../include/vectors.h"

bool ShrinkToFitVec(void *vec, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(int));

            if (ptr != NULL) {
                Vec->vec = (int*)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            printf("Failed to shrink vector.\n");

            return false;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(float));

            if (ptr != NULL) {
                Vec->vec = (float*)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            printf("Failed to shrink vector.\n");

            return false;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(char));

            if (ptr != NULL) {
                Vec->vec = (char*)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            printf("Failed to shrink vector.\n");

            return false;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(char*));

            if (ptr != NULL) {
                Vec->vec = (char**)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            printf("Failed to shrink vector.\n");

            return false;
        }
        default: return false;
    }
}