#include "../include/vectors.h"

bool ExtendVec(Vector* vec, size_t size) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (Vec->size >= size || Vec->capacity >= size) {
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
            FloatVec* Vec = (FloatVec*)vec->data;

            if (Vec->size >= size || Vec->capacity >= size) {
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
            CharVec* Vec = (CharVec*)vec->data;

            if (Vec->size >= size || Vec->capacity >= size) {
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
            StrVec* Vec = (StrVec*)vec->data;

            if (Vec->size >= size || Vec->capacity >= size) {
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