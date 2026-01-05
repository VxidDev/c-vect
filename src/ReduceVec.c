#include "../include/vectors.h"

void* ReduceVec(Vector* vec , void* (*reducer)(void* , void* , void*) , void* ctx , void* init) {
    ptrdiff_t sz = GetSizeVec(vec);
    void* acc = init;

    for (ptrdiff_t i = 0; i < sz; i++) {
        void* item = GetItemFromVec(vec, i);
        acc = reducer(acc, item, ctx);
    }

    return acc;
}