#include "../include/vectors.h"
#include <stddef.h>

void* BackVec(Vector* vec) {
    ptrdiff_t sz = GetSizeVec(vec);
    if (sz == 0 || sz == -1) return NULL;

    size_t elemSize;

    switch (vec->type) {
        case VEC_INT: elemSize = sizeof(int); break;
        case VEC_FLOAT: elemSize = sizeof(float); break;
        case VEC_CHAR: elemSize = sizeof(char); break;
        case VEC_STRING: elemSize = sizeof(char*); break;
        default: return 0;
    }

    return (char*)vec->data + (sz - 1) * elemSize;
}