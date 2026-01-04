#include <stdio.h>
#include <vectors.h>

void PrintInt(void* item, size_t idx) {
    printf("Item@Idx.%zu -> %i\n" , idx , *(int*)item);
}

void PrintFloat(void* item, size_t idx) {
    printf("Item@Idx.%zu -> %.1f\n" , idx , *(float*)item);
}

void PrintChar(void* item, size_t idx) {
    printf("Item@Idx.%zu -> %c\n" , idx , *(char*)item);
}

void PrintStr(void* item, size_t idx) {
    printf("Item@Idx.%zu -> %s\n" , idx , *(char**)item);
}

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    ForEachVec(IntVec, PrintInt);
    FreeVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to initialize FloatVec.\n");
        return 1;
    }

    ForEachVec(FloatVec, PrintFloat);
    FreeVec(FloatVec);

    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to initialize CharVec.\n");
        return 1;
    }

    ForEachVec(CharVec, PrintChar);
    FreeVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to initialize StrVec.\n");
        return 1;
    }

    ForEachVec(StrVec, PrintStr);
    FreeVec(StrVec);

    return 0;   
}