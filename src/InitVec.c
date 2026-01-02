#include "../include/vectors.h"
#include <stddef.h>

void* InitVec(enum VecType type , void* arr , void* arrlen) {
    switch (type) {
        case VEC_INT: {

            IntVec* vec = (IntVec*)calloc(1 , sizeof(IntVec));

            if (!vec) {
                printf("Failed to initialize vector.\n");
                return NULL;
            }

            vec->vec = (int*)calloc(16 , sizeof(int));

            if (!vec->vec) {
                printf("Failed to allocate IntVec data\n");
                free(vec);
                return NULL;
            }

            vec->capacity = 16;

            // printf("Initialized basic vector.\n");

            if (arr != NULL && arrlen != NULL) {
                int* Array = (int*)arr;
                size_t len = *(int*)arrlen;

                // printf("Prepared void* args for work.\n");

                for (size_t i = 0; i < len; i++) {
                    AppendVec(vec, (int*)&Array[i], VEC_INT);    
                }

                if (vec->size != len) {
                    printf("Failed to initialize vector.\n");
                    return NULL;
                }
            }

            return vec;
        }

        break;
        case VEC_FLOAT: {
            FloatVec* vec = (FloatVec*)calloc(1 , sizeof(FloatVec));

            if (!vec) {
                printf("Failed to initialize vector.\n");
                return NULL;
            }

            vec->vec = (float*)calloc(16 , sizeof(float));

            if (!vec->vec) {
                printf("Failed to allocate IntVec data\n");
                free(vec);
                return NULL;
            }

            vec->capacity = 16;

            // printf("Initialized basic vector.\n");

            if (arr != NULL && arrlen != NULL) {
                float* Array = (float*)arr;
                size_t len = *(int*)arrlen;

                // printf("Prepared void* args for work.\n");

                for (size_t i = 0; i < len; i++) {
                    AppendVec(vec, (float*)&Array[i], VEC_INT);    
                }

                if (vec->size != len) {
                    printf("Failed to initialize vector.\n");
                    return NULL;
                }
            }

            return vec;
        }

        break;
        case VEC_STRING: {
            StrVec* vec = (StrVec*)calloc(1 , sizeof(StrVec));

            if (!vec) {
                printf("Failed to initialize vector.\n");
                return NULL;
            }

            vec->vec = (char**)calloc(16 , sizeof(char*));

            if (!vec->vec) {
                printf("Failed to allocate IntVec data\n");
                free(vec);
                return NULL;
            }

            vec->capacity = 16;

            // printf("Initialized basic vector.\n");

            if (arr != NULL && arrlen != NULL) {
                char** Array = (char**)arr;
                size_t len = *(int*)arrlen;

                // printf("Prepared void* args for work.\n");

                for (size_t i = 0; i < len; i++) {
                    AppendVec(vec, (char**)&Array[i], VEC_INT);    
                }

                if (vec->size != len) {
                    printf("Failed to initialize vector.\n");
                    return NULL;
                }
            }

            return vec;
        }

        break;
        case VEC_CHAR: {
            CharVec* vec = (CharVec*)calloc(1 , sizeof(CharVec));

            if (!vec) {
                printf("Failed to initialize vector.\n");
                return NULL;
            }

            vec->vec = (char*)calloc(16 , sizeof(char));

            if (!vec->vec) {
                printf("Failed to allocate IntVec data\n");
                free(vec);
                return NULL;
            }

            vec->capacity = 16;

            // printf("Initialized basic vector.\n");

            if (arr != NULL && arrlen != NULL) {
                char* Array = (char*)arr;
                size_t len = *(int*)arrlen;

                // printf("Prepared void* args for work.\n");

                for (size_t i = 0; i < len; i++) {
                    AppendVec(vec, (char*)&Array[i], VEC_INT);    
                }

                if (vec->size != len) {
                    printf("Failed to initialize vector.\n");
                    return NULL;
                }
            }

            return vec;
        }
        default: return NULL;
    }
}