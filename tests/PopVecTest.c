#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT, (int[]){1 , 2 , 3}, &(size_t){3});

    if (!IntVec) {
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    printf("Last Item Pre-Pop: %i\n" , *(int*)GetLastVec(IntVec));
    PopVec(IntVec);
    printf("Last Item After-Pop: %i\n\n" , *(int*)GetLastVec(IntVec));
    
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT, (float[]){1.1 , 2.2 , 3.3}, &(size_t){3});

    if (!FloatVec) {
        printf("Failed to initialize FloatVec.\n");
        return 1;
    }

    printf("Last Item Pre-Pop: %f\n" , *(float*)GetLastVec(FloatVec));
    PopVec(FloatVec);
    printf("Last Item After-Pop: %f\n\n" , *(float*)GetLastVec(FloatVec));
    
    FreeVec(FloatVec);

    Vector* CharVec = InitVec(VEC_CHAR, "abc", &(size_t){3});

    if (!CharVec) {
        printf("Failed to initialize CharVec.\n");
        return 1;
    }

    printf("Last Item Pre-Pop: %c\n" , *(char*)GetLastVec(CharVec));
    PopVec(CharVec);
    printf("Last Item After-Pop: %c\n\n" , *(char*)GetLastVec(CharVec));
    
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING, (char*[]){"abc" , "def" , "ghk"}, &(size_t){3});

    if (!StrVec) {
        printf("Failed to initialize StrVec.\n");
        return 1;
    }

    printf("Last Item Pre-Pop: %s\n" , *(char**)GetLastVec(StrVec));
    PopVec(StrVec);
    printf("Last Item After-Pop: %s\n" , *(char**)GetLastVec(StrVec));
    
    FreeVec(StrVec);

    return 0;
}