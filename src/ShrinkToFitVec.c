#include "../include/vectors.h"

bool ShrinkToFitVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(int));

            if (ptr != NULL) {
                Vec->vec = (int*)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            return false;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(float));

            if (ptr != NULL) {
                Vec->vec = (float*)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            return false;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(char));

            if (ptr != NULL) {
                Vec->vec = (char*)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            return false;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            if (Vec->size == Vec->capacity) return true;

            void* ptr = realloc(Vec->vec , Vec->size * sizeof(char*));

            if (ptr != NULL) {
                Vec->vec = (char**)ptr;
                Vec->capacity = Vec->size;

                return true;
            }

            return false;
        }
        default: return false;
    }
}