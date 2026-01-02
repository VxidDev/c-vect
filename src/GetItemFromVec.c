#include "../include/vectors.h"

void* GetItemFromVec(void* vec , size_t index , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec;

            if (Vec->size == 0 || index >= Vec->size) {
                printf("Index (%zu) out of vector's range.\n" , index);
                return NULL;
            } 

            return (void*)&Vec->vec[index];
        }
        default: return NULL;
    }
}