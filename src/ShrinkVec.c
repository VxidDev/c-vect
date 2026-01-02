#include "../include/vectors.h"

bool ShrinkVec(void *vec, size_t size, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            if (Vec->size > size) {
                printf("Can't resize vector, current element count exceeds target size.\n");
                return false;
            }

            if (Vec->capacity <= size) {
                printf("Can't resize vector, current capacity is smaller or the same than target size. Use ExtendVec() instead.\n");
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
            FloatVec* Vec = (FloatVec*)vec;

            if (Vec->size > size) {
                printf("Can't resize vector, current element count exceeds target size.\n");
                return false;
            }

            if (Vec->capacity <= size) {
                printf("Can't resize vector, current capacity is smaller or the same than target size. Use ExtendVec() instead.\n");
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
            CharVec* Vec = (CharVec*)vec;

            if (Vec->size > size) {
                printf("Can't resize vector, current element count exceeds target size.\n");
                return false;
            }

            if (Vec->capacity <= size) {
                printf("Can't resize vector, current capacity is smaller or the same than target size. Use ExtendVec() instead.\n");
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
            StrVec* Vec = (StrVec*)vec;

            if (Vec->size > size) {
                printf("Can't resize vector, current element count exceeds target size.\n");
                return false;
            }

            if (Vec->capacity <= size) {
                printf("Can't resize vector, current capacity is smaller or the same than target size. Use ExtendVec() instead.\n");
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