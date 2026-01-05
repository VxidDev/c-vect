#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVector = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVector) {
        printf("Failed To Initialize IntVec.\n");
        return 1;
    }

    printf("Last Item: %i\n" , *(int*)BackVec(IntVector));
    FreeVec(IntVector);

    Vector* FloatVector = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVector) {
        printf("Failed To Initialize FloatVec.\n");
        return 1;
    }

    printf("Last Item: %f\n" , *(float*)BackVec(FloatVector));
    FreeVec(FloatVector);

    Vector* CharVector = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVector) {
        printf("Failed To Initialize CharVec.\n");
        return 1;
    }

    printf("Last Item: %c\n" , *(char*)BackVec(CharVector));
    FreeVec(CharVector);

    Vector* StrVector = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVector) {
        printf("Failed To Initialize StrVec.\n");
        return 1;
    }

    printf("Last Item: %s\n" , *(char**)BackVec(StrVector));
    FreeVec(StrVector);

    Vector* EmptyIntVector = InitVec(VEC_INT, NULL, &(size_t){0});
    if (!EmptyIntVector) {
        printf("Failed to initialize EmptyIntVector.\n");
        return 1;
    }
    printf("Last Item of empty vector (expected NULL): %p\n", BackVec(EmptyIntVector));
    FreeVec(EmptyIntVector);

    return 0;
}
