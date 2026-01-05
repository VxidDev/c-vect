#include "../include/vectors.h"

Vector* FilterVec(Vector* vec , bool (*func)(void* , void*) , void* ctx) {
    if (!vec) return NULL;
    if (GetSizeVec(vec) == 0) return vec;

    for (ptrdiff_t i = 0; i < GetSizeVec(vec); i++) {
        if (!func(GetItemFromVec(vec , i) , ctx)) {
            RemoveFromVec(vec , i);
            i--;
        }
    }

    return vec;
}