#include "../include/vectors.h"
#include <string.h>

void AppendVec(Vector* vec , void* item) {
    
    switch (type) {
        case (VEC_CHAR): {
            CharVec* Vec = (CharVec*)vec;

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
            IntVec* Vec = (IntVec*)vec;

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
            StrVec* Vec = (StrVec*)vec;

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
            FloatVec* Vec = (FloatVec*)vec;

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