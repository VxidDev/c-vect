#include "../include/vectors.h"

void FreeVec(void* vec , enum VecType type) {
    switch (type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec;

            free(Vec->vec);
            free(Vec);

            break;
        }
    }
}