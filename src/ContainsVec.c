#include "../include/vectors.h"
#include <string.h>

bool ContainsVec(void *vec, void *item, enum VecType type) {
    switch (type) {
        case VEC_INT: {
            const struct IntVec* Vec = (const struct IntVec*)vec;
            const int Item = *(const int*)item;

            for (size_t i = 0; i < Vec->size; i++) {
                if (Vec->vec[i] == Item) return true;
            }

            return false;
        }
        case VEC_FLOAT: {
            const struct FloatVec* Vec = (const struct FloatVec*)vec;
            const float Item = *(const float*)item;

            for (size_t i = 0; i < Vec->size; i++) {
                if (Vec->vec[i] == Item) return true;
            }

            return false;
        }
        case VEC_CHAR: {
            const struct CharVec* Vec = (const struct CharVec*)vec;
            const char Item = *(const char*)item;

            for (size_t i = 0; i < Vec->size; i++) {
                if (Vec->vec[i] == Item) return true;
            }

            return false;
        }
        case VEC_STRING: {
            const struct StrVec* Vec = (const struct StrVec*)vec;
            const char* Item = (const char*)item;

            for (size_t i = 0; i < Vec->size; i++) {
                if (strcmp(Item, Vec->vec[i]) == 0) return true;
            }

            return false;
        }
        default: return false;
    }
}