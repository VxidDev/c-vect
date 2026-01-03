#include "../include/vectors.h"

bool RemoveFromVec(Vector* vec , size_t index) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return false;
            }

            for (size_t i = index; i + 1 < Vec->size; ++i) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return false;
            }

            for (size_t i = index; i + 1 < Vec->size; ++i) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return false;
            }

            for (size_t i = index; i + 1 < Vec->size; ++i) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            if (Vec->size == 0 || index >= Vec->size) {
                return false;
            }

            for (size_t i = index; i + 1 < Vec->size; ++i) {
                Vec->vec[i] = Vec->vec[i + 1];
            }

            Vec->size--;

            return true;
        }
        default: return false;
    }
}