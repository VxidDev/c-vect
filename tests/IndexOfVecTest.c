#include <vectors.h>

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to init IntVec.\n");
        return 1;
    }

    printf("Index of 2: %td (expected 1)\n" , IndexOfVec(IntVec , &(int){2}));
    printf("Index of 5: %td (expected -1)\n" , IndexOfVec(IntVec , &(int){5}));
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to init FloatVec.\n");
        return 1;
    }

    printf("\nIndex of 2.2: %td (expected 1)\n" , IndexOfVec(FloatVec , &(float){2.2}));
    printf("Index of 5.5: %td (expected -1)\n" , IndexOfVec(FloatVec , &(float){5.5}));
    FreeVec(FloatVec);
    
    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to init CharVec.\n");
        return 1;
    }

    printf("\nIndex of 'b': %td (expected 1)\n" , IndexOfVec(CharVec , "b"));
    printf("Index of 'z': %td (expected -1)\n" , IndexOfVec(CharVec , "z"));
    FreeVec(CharVec);

    char* s1 = "abc";
    char* s2 = "def";
    char* s3 = "ghk";
    Vector* StrVec = InitVec(VEC_STRING , (char*[]){s1 , s2 , s3} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to init StrVec.\n");
        return 1;
    }

    printf("\nIndex of \"def\": %td (expected 1)\n" , IndexOfVec(StrVec , s2));
    printf("Index of \"xyz\": %td (expected -1)\n" , IndexOfVec(StrVec , "xyz"));
    FreeVec(StrVec);

    return 0;
}