#include "../include/vectors.h"

void FreeVec(Vector* Vec) {
    if (!Vec) return;
    
    enum VecType type = Vec->type;

    switch (type) {
        case VEC_INT: {
            IntVec* Array = (IntVec*)Vec->data;
            free(Array->vec);

            break;
        }
        case VEC_FLOAT: {
            FloatVec* Array = (FloatVec*)Vec->data;
            free(Array->vec);

            break;
        }
        case VEC_CHAR: {
            CharVec* Array = (CharVec*)Vec->data;
            free(Array->vec);

            break;
        }
        case VEC_STRING: {
            StrVec* Array = (StrVec*)Vec->data;
            free(Array->vec);

            break;
        }
    }

    free(Vec->data);
    free(Vec);
}