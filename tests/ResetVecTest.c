#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to init IntVec.\n");
        return 1;
    }

    printf("Size: %td (expected 3) Capacity: %td (expected 16)\n" , GetSizeVec(IntVec) , GetCapacityVec(IntVec));
    ResetVec(IntVec);
    printf("Size: %td (expected 0) Capacity: %td (expected 1)\n" , GetSizeVec(IntVec) , GetCapacityVec(IntVec));
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to init FloatVec.\n");
        return 1;
    }

    printf("Size: %td (expected 3) Capacity: %td (expected 16)\n" , GetSizeVec(FloatVec) , GetCapacityVec(FloatVec));
    ResetVec(FloatVec);
    printf("Size: %td (expected 0) Capacity: %td (expected 1)\n" , GetSizeVec(FloatVec) , GetCapacityVec(FloatVec));
    FreeVec(FloatVec);
    
    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to init CharVec.\n");
        return 1;
    }

    printf("Size: %td (expected 3) Capacity: %td (expected 16)\n" , GetSizeVec(CharVec) , GetCapacityVec(CharVec));
    ResetVec(CharVec);
    printf("Size: %td (expected 0) Capacity: %td (expected 1)\n" , GetSizeVec(CharVec) , GetCapacityVec(CharVec));
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to init StrVec.\n");
        return 1;
    }

    printf("Size: %td (expected 3) Capacity: %td (expected 16)\n" , GetSizeVec(StrVec) , GetCapacityVec(StrVec));
    ResetVec(StrVec);
    printf("Size: %td (expected 0) Capacity: %td (expected 1)\n" , GetSizeVec(StrVec) , GetCapacityVec(StrVec));
    FreeVec(StrVec);

    return 0;
}