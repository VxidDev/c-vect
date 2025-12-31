#include "../include/vectors.h"
#include <string.h>

void AppendVec(void* vec , void* item , enum VecType type) {
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

            strcpy((char*)item, Vec->vec[Vec->size]);
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