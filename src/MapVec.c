#include "../include/vectors.h"

Vector* MapVec(Vector* vec , void* (*func)(void* , void*) , void* ctx) {
    if (!vec) return NULL;
    if (GetSizeVec(vec) == 0) return vec;

    for (ptrdiff_t i = 0; i < GetSizeVec(vec); i++) {
        SetItemVec(vec , func(GetItemFromVec(vec , i) , ctx) , i);
    }

    return vec;
}