#include "../include/vectors.h"

bool AppendVec(Vector* vec , void* item) {
    if (!vec) return false;

    enum VecType type = vec->type;

    switch (type) {
        case VEC_CHAR: {
            CharVec* Vec = (CharVec*)vec->data;

            if (Vec->size == Vec->capacity) {
                Vec->capacity = Vec->capacity ? Vec->capacity * 2 : 16;

                char* temp = realloc(Vec->vec, Vec->capacity * sizeof(char));
                
                if (!temp) return false;

                Vec->vec = temp;
            }

            Vec->vec[Vec->size++] = *(char*)item;
            return true;  
        }
        case VEC_INT: {
            IntVec* Vec = (IntVec*)vec->data;

            if (Vec->size == Vec->capacity) {
                Vec->capacity = Vec->capacity ? Vec->capacity * 2 : 16;

                int* temp = realloc(Vec->vec, Vec->capacity * sizeof(int));
                
                if (!temp) return false;

                Vec->vec = temp;
            }

            Vec->vec[Vec->size++] = *(int*)item;  
            return true;
        }
        case VEC_STRING: {
            StrVec* Vec = (StrVec*)vec->data;

            if (Vec->size == Vec->capacity) {
                Vec->capacity = Vec->capacity ? Vec->capacity * 2 : 16;

                char** temp = realloc(Vec->vec, Vec->capacity * sizeof(char*));
                
                if (!temp) return false;

                Vec->vec = temp;
            }
  
            Vec->vec[Vec->size] = (char*)item;
            Vec->size++;

            return true;   
        }
        case VEC_FLOAT: {
            FloatVec* Vec = (FloatVec*)vec->data;

            if (Vec->size == Vec->capacity) {
                Vec->capacity = Vec->capacity ? Vec->capacity * 2 : 16;

                float* temp = realloc(Vec->vec, Vec->capacity * sizeof(float));
                
                if (!temp) return false;

                Vec->vec = temp;
            }

            Vec->vec[Vec->size++] = *(float*)item;  
            return true;   
        }
        default: return false;
    }
}