#include "../include/vectors.h"

void FreeVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            struct IntVec* Vec = (struct IntVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
        case VEC_FLOAT: {
            struct FloatVec* Vec = (struct FloatVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
        case VEC_CHAR: {
            struct CharVec* Vec = (struct CharVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
        case VEC_STRING: {
            struct StrVec* Vec = (struct StrVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
    }
}