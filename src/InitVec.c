#include "../include/vectors.h"
#include <string.h>

Vector* InitVec(enum VecType type , void* arr , void* arrlen) {
    if (!(type >= 0 && type <= 4)) {
        return NULL;    
    } 

    Vector* vec = (Vector*)calloc(1 , sizeof(Vector));

    if (!vec) {
        return NULL;
    }

    vec->type = type;
    
    switch (type) {
        case VEC_INT:
            vec->data = (IntVec*)calloc(1 , sizeof(IntVec));
            break;
        case VEC_FLOAT:
            vec->data = (FloatVec*)calloc(1 , sizeof(FloatVec));
            break;
        case VEC_CHAR:
            vec->data = (CharVec*)calloc(1 , sizeof(CharVec));
            break;
        case VEC_STRING: 
            vec->data = (StrVec*)calloc(1 , sizeof(StrVec));
            break;
    }

    if (!vec->data) {
        free(vec);
        return NULL;
    }

    void* Vector = vec->data;
    switch (type) {
        case VEC_INT: {
            IntVec* vect = (IntVec*)Vector;
            vect->vec = (int*)calloc(16 , sizeof(int));

            if (!vect->vec) {
                free(vec->data);
                free(vec);
                return NULL;
            }

            vect->size = 0;
            vect->capacity = 16;

            break;
        }
        case VEC_FLOAT: {
            FloatVec* vect = (FloatVec*)Vector;
            vect->vec = (float*)calloc(16 , sizeof(float));

            if (!vect->vec) {
                free(vec->data);
                free(vec);
                return NULL;
            }

            vect->size = 0;
            vect->capacity = 16;

            break;
        }
        case VEC_CHAR: {
            CharVec* vect = (CharVec*)Vector;
            vect->vec = (char*)calloc(16 , sizeof(char));

            if (!vect->vec) {
                free(vec->data);
                free(vec);
                return NULL;
            }

            vect->size = 0;
            vect->capacity = 16;

            break;
        }
        case VEC_STRING: {
            StrVec* vect = (StrVec*)Vector;
            vect->vec = (char**)calloc(16 , sizeof(char*));

            if (!vect->vec) {
                free(vec->data);
                free(vec);
                return NULL;
            }

            vect->size = 0;
            vect->capacity = 16;

            break;
        }
    }

    if (arr != NULL && arrlen != NULL) {
        size_t len = *(size_t*)arrlen;

        switch (type) {
            case VEC_INT: {
                IntVec* vect = (IntVec*)Vector;
                int* Array = (int*)arr;

                if (len >= vect->capacity) {
                    void* ptr = realloc(vect->vec , (len + 8) * sizeof(int));

                    if (!ptr) {
                        return vec;
                    }

                    vect->vec = (int*)ptr;
                    vect->capacity = len + 8;
                }

                memcpy(vect->vec , Array , len * sizeof(int));

                vect->size = len;

                break;
            }
            case VEC_FLOAT: {
                FloatVec* vect = (FloatVec*)Vector;
                float* Array = (float*)arr;

                if (len >= vect->capacity) {
                    void* ptr = realloc(vect->vec , (len + 8) * sizeof(float));

                    if (!ptr) {
                        return vec;
                    }

                    vect->vec = (float*)ptr;
                    vect->capacity = len + 8;
                }

                memcpy(vect->vec , Array , len * sizeof(float));

                vect->size = len;
                vect->capacity = len > 16 ? len : 16;

                break;
            }
            case VEC_CHAR: {
                CharVec* vect = (CharVec*)Vector;
                char* Array = (char*)arr;

                if (len >= vect->capacity) {
                    void* ptr = realloc(vect->vec , (len + 8) * sizeof(char));

                    if (!ptr) {
                        return vec;
                    }

                    vect->vec = (char*)ptr;
                    vect->capacity = len + 8;
                }

                memcpy(vect->vec , Array , len* sizeof(char));

                vect->vec[len] = '\0';
                vect->size = len;
                vect->capacity = len + 1 > 16 ? len + 1: 16;

                break;
            }
            case VEC_STRING: {
                StrVec* vect = (StrVec*)Vector;
                char** Array = (char**)arr;

                if (len >= vect->capacity) {
                    void* ptr = realloc(vect->vec , (len + 8) * sizeof(char*));

                    if (!ptr) {
                        return vec;
                    }

                    vect->vec = (char**)ptr;
                    vect->capacity = len + 8;
                }

                memcpy(vect->vec , Array , len * sizeof(char*));

                vect->size = len;
                vect->capacity = len > 16 ? len : 16;

                break;
            }
        }
    }

    return vec;
}