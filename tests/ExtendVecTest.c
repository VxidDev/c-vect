#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to init IntVec.\n");
        return 1;
    }

    printf("Capacity: %td (expected 16)\n" , GetCapacityVec(IntVec));
    ExtendVec(IntVec, 32);
    printf("Capacity: %td (expected 32)\n" , GetCapacityVec(IntVec));
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to init FloatVec.\n");
        return 1;
    }

    printf("\nCapacity: %td (expected 16)\n" , GetCapacityVec(FloatVec));
    ExtendVec(FloatVec, 32);
    printf("Capacity: %td (expected 32)\n" , GetCapacityVec(FloatVec));
    FreeVec(FloatVec);
    
    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to init CharVec.\n");
        return 1;
    }

    printf("\nCapacity: %td (expected 16)\n" , GetCapacityVec(CharVec));
    ExtendVec(CharVec, 32);
    printf("Capacity: %td (expected 32)\n" , GetCapacityVec(CharVec));
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to init StrVec.\n");
        return 1;
    }

    printf("\nCapacity: %td (expected 16)\n" , GetCapacityVec(StrVec));
    ExtendVec(StrVec, 32);
    printf("Capacity: %td (expected 32)\n" , GetCapacityVec(StrVec));
    FreeVec(StrVec);

    return 0;
}