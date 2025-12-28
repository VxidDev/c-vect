#pragma once
#include <stdlib.h>
#include <stdio.h>

enum VecType { VEC_CHAR , VEC_STRING , VEC_INT , VEC_FLOAT };

struct FloatVec {
    size_t size , capacity;
    float *vec;
};

struct IntVec {
    size_t size , capacity;
    int *vec;
};

struct CharVec {
    size_t size , capacity;
    char *vec;
};

struct StrVec {
    size_t size , capacity;
    char **vec;
};

static inline void* InitVec(enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* vec = (struct IntVec*)calloc(1 , sizeof(struct IntVec));

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

            return vec;
        }

        break;
        case VEC_FLOAT: {
            struct FloatVec* vec = (struct FloatVec*)calloc(1 , sizeof(struct FloatVec));

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

            return vec;
        }

        break;
        case VEC_STRING: {
            struct StrVec* vec = (struct StrVec*)calloc(1 , sizeof(struct StrVec));

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

            return vec;
        }

        break;
        case VEC_CHAR: {
            struct CharVec* vec = (struct CharVec*)calloc(1 , sizeof(struct CharVec));

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

            return vec;
        }
    }
}

static inline void AppendVec(void* vec , void* item , enum VecType type) {
    switch (type) {
        case (VEC_CHAR): {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->capacity < Vec->size + 1) {
                Vec->capacity *= 2 ?: 16;
                char *temp = (char*)realloc(Vec->vec , Vec->capacity * sizeof(char));
                
                if (temp != NULL) {
                    Vec->vec = temp;
                } else {
                    printf("Failed to allocate memory for appending.\n");
                    return;
                }
            }   

            Vec->vec[Vec->size] = *(char*)item;
            Vec->size++;
            Vec->vec[Vec->size] = '\0';

        }
            break;
        case (VEC_INT): {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (Vec->capacity < Vec->size + 1) {
                Vec->capacity *= 2 ?: 16;
                int *temp = (int*)realloc(Vec->vec , Vec->capacity * sizeof(int));
                
                if (temp != NULL) {
                    Vec->vec = temp;
                } else {
                    printf("Failed to allocate memory for appending.\n");
                    return;
                }
            }   

            Vec->vec[Vec->size] = *(int*)item;
            Vec->size++;
        }
            break;
        case (VEC_STRING): {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->capacity < Vec->size + 1) {
                Vec->capacity *= 2 ?: 16;
                char* *temp = (char**)realloc(Vec->vec , Vec->capacity * sizeof(char*));
                
                if (temp != NULL) {
                    Vec->vec = temp;
                } else {
                    printf("Failed to allocate memory for appending.\n");
                    return;
                }
            }   

            Vec->vec[Vec->size] = *(char**)item;
            Vec->size++;
        }
            break;
        case (VEC_FLOAT): {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->capacity < Vec->size + 1) {
                Vec->capacity *= 2 ?: 16;
                float *temp = (float*)realloc(Vec->vec , Vec->capacity * sizeof(float));
                
                if (temp != NULL) {
                    Vec->vec = temp;
                } else {
                    printf("Failed to allocate memory for appending.\n");
                    return;
                }
            }   

            Vec->vec[Vec->size] = *(float*)item;
            Vec->size++;
        }
            break;
    }
}

static inline void FreeVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* vec = (struct IntVec*)vec;

            free(vec->vec);
            free(vec);

            break;
        }
        case VEC_FLOAT: {
            struct FloatVec* vec = (struct FloatVec*)vec;

            free(vec->vec);
            free(vec);

            break;
        }
        case VEC_CHAR: {
            struct CharVec* vec = (struct CharVec*)vec;

            free(vec->vec);
            free(vec);

            break;
        }
        case VEC_STRING: {
            struct StrVec* vec = (struct StrVec*)vec;

            free(vec->vec);
            free(vec);

            break;
        }
    }
}
