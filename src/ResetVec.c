#include "../include/vectors.h"

bool ResetVec(void *vec, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            void* ptr = realloc(Vec->vec , 16 * sizeof(int));

            if (ptr != NULL) {
               Vec->vec = (int*)ptr;
               Vec->size = 0;
               Vec->capacity = 16;

               return true;
            }

            return false;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            void* ptr = realloc(Vec->vec , 16 * sizeof(float));

            if (ptr != NULL) {
               Vec->vec = (float*)ptr;
               Vec->size = 0;
               Vec->capacity = 16;

               return true;
            }

            return false;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec;

            void* ptr = realloc(Vec->vec , 16 * sizeof(char));

            if (ptr != NULL) {
               Vec->vec = (char*)ptr;
               Vec->size = 0;
               Vec->capacity = 16;

               return true;
            }

            return false;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec;

            void* ptr = realloc(Vec->vec , 16 * sizeof(char*));

            if (ptr != NULL) {
               Vec->vec = (char**)ptr;
               Vec->size = 0;
               Vec->capacity = 16;

               return true;
            }

            return false;
        }
        default: return false;
    }
}