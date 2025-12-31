#include "../include/vectors.h"
#include <stdlib.h>
#include <string.h>

int SortVec__CompInt(const void* a, const void* b) {
    int va = *(int*)a;
    int vb = *(int*)b;

    return (va > vb) - (vb > va);
}

int SortVec__CompFloat(const void* a, const void* b) {
    float va = *(float*)a;
    float vb = *(float*)b;

    if (va < vb) return -1;
    else if (va > vb) return 1;
    return 0;
}

int SortVec__CompChar(const void* a, const void* b) {
    int va = *(char*)a;
    int vb = *(char*)b;

    return (va > vb) - (vb > va);
}

int SortVec__CompStr(const void* a, const void* b) {
    const char* sa = *(const char**)a;  
    const char* sb = *(const char**)b;
    return strcmp(sa, sb); 
}

bool SortVec(void *vec, int(*compare)(const void* , const void*) , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;
            
            if (Vec->size <= 1) return true;

            if (compare == NULL) compare = SortVec__CompInt;

            qsort(Vec->vec, Vec->size, sizeof(int), compare);

            return true;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            if (Vec->size <= 1) return true;

            if (compare == NULL) compare = SortVec__CompFloat;

            qsort(Vec->vec, Vec->size, sizeof(float), compare);

            return true;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            if (Vec->size <= 1) return true;

            if (compare == NULL) compare = SortVec__CompChar;

            qsort(Vec->vec, Vec->size, sizeof(char), compare);

            return true;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            if (Vec->size <= 1) return true;

            if (compare == NULL) compare = SortVec__CompStr;

            qsort(Vec->vec, Vec->size, sizeof(char*), compare);

            return true;
        }
        default: return false;
    }
}