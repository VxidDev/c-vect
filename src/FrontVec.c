#include "../include/vectors.h"
#include <stddef.h>

void* FrontVec(Vector* vec) {
    ptrdiff_t size = GetSizeVec(vec);
    return size == 0 ? NULL : GetItemFromVec(vec , 0);
}