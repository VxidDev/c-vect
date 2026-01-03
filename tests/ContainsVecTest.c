#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to init IntVec.\n");
        return 1;
    }

    printf("Contains Item %i: %s (expected 'true')\n" , 3 , ContainsVec(IntVec, &(int){3}) ? "true" : "false");
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to init FloatVec.\n");
        return 1;
    }

    printf("\nContains Item %.1f: %s (expected 'false')\n" , 3.1 , ContainsVec(FloatVec, &(float){3.1}) ? "true" : "false");
    FreeVec(FloatVec);
    
    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to init CharVec.\n");
        return 1;
    }

    printf("\nContains Item '%c': %s (expected 'false')\n" , 'f' , ContainsVec(CharVec, "f") ? "true" : "false");
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to init StrVec.\n");
        return 1;
    }

    printf("\nContains Item '%s': %s (expected 'true')\n" , "abc" , ContainsVec(IntVec, "abc") ? "true" : "false");
    FreeVec(StrVec);

    return 0;
}