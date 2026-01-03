#include "../include/vectors.h"
#include <stdint.h>
#include <string.h>

bool InsertVec(Vector* vec, void *item, size_t index) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(vec , Vec->capacity * 2)) {
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
            FloatVec* Vec = (FloatVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(vec , Vec->capacity * 2)) {
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
            CharVec* Vec = (CharVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(vec , Vec->capacity * 2)) {
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
            StrVec* Vec = (StrVec*)vec->data;

            if (!Vec || index > Vec->size || index == SIZE_MAX) return false;

            if (Vec->size + 1 > Vec->capacity && !ExtendVec(vec , Vec->capacity * 2)) {
                return false;
            }

            for (size_t i = index; i < Vec->size; i++) {
                Vec->vec[i] = Vec->vec[i - 1];
            }

            Vec->vec[index] = (char*)item;

            Vec->size++;

            return true;
        }  
        default: return false;
    }
}