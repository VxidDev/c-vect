#include "../include/vectors.h"

bool ResetVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            void* ptr = realloc(Vec->vec , sizeof(int));

            if (ptr != NULL) {
               Vec->vec = (int*)ptr;
               Vec->size = 0;
               Vec->capacity = 1;

               return true;
            }

            return false;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            void* ptr = realloc(Vec->vec , sizeof(float));

            if (ptr != NULL) {
               Vec->vec = (float*)ptr;
               Vec->size = 0;
               Vec->capacity = 1;

               return true;
            }

            return false;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            void* ptr = realloc(Vec->vec , sizeof(char));

            if (ptr != NULL) {
               Vec->vec = (char*)ptr;
               Vec->size = 0;
               Vec->capacity = 1;

               return true;
            }

            return false;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            void* ptr = realloc(Vec->vec , sizeof(char*));

            if (ptr != NULL) {
               Vec->vec = (char**)ptr;
               Vec->size = 0;
               Vec->capacity = 1;

               return true;
            }

            return false;
        }
        default: return false;
    }
}