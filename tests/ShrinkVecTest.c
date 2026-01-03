#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to init IntVec.\n");
        return 1;
    }

    printf("Capacity: %td (expected 16)\n" , GetCapacityVec(IntVec));
    ShrinkVec(IntVec , 9);
    printf("Capacity: %td (expected 9)\n" , GetCapacityVec(IntVec));
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to init FloatVec.\n");
        return 1;
    }

    printf("\nCapacity: %td (expected 16)\n" , GetCapacityVec(FloatVec));
    ShrinkVec(FloatVec , 4);
    printf("Capacity: %td (expected 4)\n" , GetCapacityVec(FloatVec));
    FreeVec(FloatVec);
    
    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to init CharVec.\n");
        return 1;
    }

    printf("\nCapacity: %td (expected 16)\n" , GetCapacityVec(CharVec));
    ShrinkVec(CharVec , 8);
    printf("Capacity: %td (expected 8)\n" , GetCapacityVec(CharVec));
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to init StrVec.\n");
        return 1;
    }

    printf("\nCapacity: %td (expected 16)\n" , GetCapacityVec(StrVec));
    ShrinkVec(StrVec , 13);
    printf("Capacity: %td (expected 13)\n" , GetCapacityVec(StrVec));
    FreeVec(StrVec);

    return 0;
}