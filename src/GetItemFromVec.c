#include "../include/vectors.h"

void* GetItemFromVec(Vector* vec , size_t index) {
    switch (vec->type) {
        case VEC_INT: {
            const IntVec* Vec = (const IntVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        case VEC_FLOAT: {
            const FloatVec* Vec = (const FloatVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        case VEC_CHAR: {
            const CharVec* Vec = (const CharVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        case VEC_STRING: {
            const StrVec* Vec = (const StrVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        default: return NULL;
    }
}