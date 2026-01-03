#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to init IntVec.\n");
        return 1;
    }

    printf("Item: %i (expected 2)\n" , *(int*)GetItemFromVec(IntVec , 1));
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to init FloatVec.\n");
        return 1;
    }

    printf("\nItem: %.1f (expected 2.2)\n" , *(float*)GetItemFromVec(FloatVec , 1));
    FreeVec(FloatVec);
    
    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to init CharVec.\n");
        return 1;
    }

    printf("\nItem: %c (expected 'b')\n" , *(char*)GetItemFromVec(CharVec , 1));
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to init StrVec.\n");
        return 1;
    }

    printf("\nItem: %s (expected 'def' )\n" , *(char**)GetItemFromVec(StrVec , 1));
    FreeVec(StrVec);

    return 0;
}