#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVector = InitVec(VEC_INT , (int[]){3 , 1 , 2} , &(size_t){3});

    if (!IntVector) {
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    SortVec(IntVector, NULL);
    for (size_t i = 0; i < GetSizeVec(IntVector); i++) {
        printf("Item: %i\n" , *(int*)GetItemFromVec(IntVector, i));
    }

    FreeVec(IntVector);

    printf("\n");

    Vector* FloatVector = InitVec(VEC_FLOAT , (float[]){1.7 , 2.2 , 1.3} , &(size_t){3});

    if (!FloatVector) {
        printf("Failed to initialize FloatVec.\n");
        return 1;
    }

    SortVec(FloatVector, NULL);
    for (size_t i = 0; i < GetSizeVec(FloatVector); i++) {
        printf("Item: %.1f\n" , *(float*)GetItemFromVec(FloatVector, i));
    }

    FreeVec(FloatVector);

    printf("\n");

    Vector* CharVector = InitVec(VEC_CHAR , "cba" , &(size_t){3});

    if (!CharVector) {
        printf("Failed to initialize CharVec.\n");
        return 1;
    }

    SortVec(CharVector, NULL);
    for (size_t i = 0; i < GetSizeVec(CharVector); i++) {
        printf("Item: %c\n" , *(char*)GetItemFromVec(CharVector, i));
    }

    FreeVec(CharVector);

    printf("\n");

    Vector* StrVector = InitVec(VEC_STRING , (char*[]){"ghk" , "abc" , "def"} , &(size_t){3});

    if (!StrVector) {
        printf("Failed to initialize StrVec.\n");
        return 1;
    }

    SortVec(StrVector, NULL);
    for (size_t i = 0; i < GetSizeVec(StrVector); i++) {
        printf("Item: %s\n" , *(char**)GetItemFromVec(StrVector, i));
    }

    FreeVec(StrVector);

    return 0;
}