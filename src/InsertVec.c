#include "../include/vectors.h"
#include <stdint.h>
#include <string.h>

bool InsertVec(void *vec, void *item, size_t index, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(Vec , Vec->capacity * 2, VEC_INT)) {
                printf("Failed to insert element to vector.\n");
                return false;
            }

            for (size_t i = index; i < Vec->size; i++) {
                Vec->vec[i] = Vec->vec[i - 1];
            }

            Vec->vec[index] = *(int*)item;

            Vec->size++;

            return true;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(Vec , Vec->capacity * 2, VEC_FLOAT)) {
                printf("Failed to insert element to vector.\n");
                return false;
            }

            for (size_t i = index; i < Vec->size; i++) {
                Vec->vec[i] = Vec->vec[i - 1];
            }

            Vec->vec[index] = *(float*)item;

            Vec->size++;

            return true;
        } 
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(Vec , Vec->capacity * 2, VEC_CHAR)) {
                printf("Failed to insert element to vector.\n");
                return false;
            }

            for (size_t i = index; i < Vec->size; i++) {
                Vec->vec[i] = Vec->vec[i - 1];
            }

            Vec->vec[index] = *(char*)item;

            Vec->size++;

            return true;
        } 
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(Vec , Vec->capacity * 2, VEC_STRING)) {
                printf("Failed to insert element to vector.\n");
                return false;
            }

            for (size_t i = index; i < Vec->size; i++) {
                Vec->vec[i] = Vec->vec[i - 1];
            }

            strcpy((char*)item, Vec->vec[index]);

            Vec->size++;

            return true;
        }  
        default: return false;
    }
}