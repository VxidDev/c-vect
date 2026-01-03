#include "../include/vectors.h"

void ClearVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: { ((IntVec*)vec->data)->size = 0; return; }
        case VEC_CHAR: { ((CharVec*)vec->data)->size = 0; return; }
        case VEC_STRING: { ((StrVec*)vec->data)->size = 0; return; }
        case VEC_FLOAT: { ((FloatVec*)vec->data)->size = 0; return; }
        default: return;
    }
}