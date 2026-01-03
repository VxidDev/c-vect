#include <vectors.h>
#include <string.h>

void TestVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* Data = (IntVec*)vec->data;

            printf("Size: %zu , Capacity: %zu\n" , Data->size , Data->capacity);
            for (int i = 0; i < 1000000; i++) {
                if (!AppendVec(vec , &(int){i})) {
                    printf("Failed to append at %i iteration.\n" , i);
                    break;
                }
            } 
            printf("Size: %zu , Capacity: %zu\n\n" , Data->size , Data->capacity);

            return;
        }
        case VEC_FLOAT: {
            FloatVec* Data = (FloatVec*)vec->data;

            printf("Size: %zu , Capacity: %zu\n" , Data->size , Data->capacity);
            for (int i = 0; i < 1000000; i++) {
                if (!AppendVec(vec , &(float){i + (0.1 * i)})) {
                    printf("Failed to append at %i iteration.\n" , i);
                    break;
                }
            } 
            printf("Size: %zu , Capacity: %zu\n\n" , Data->size , Data->capacity);

            return;
        }
        case VEC_CHAR: {
            CharVec* Data = (CharVec*)vec->data;

            printf("Size: %zu , Capacity: %zu\n" , Data->size , Data->capacity);
            for (int i = 0; i < 256; i++) { 
                if (!AppendVec(vec , &(char){i})) {
                    printf("Failed to append at %i iteration.\n" , i);
                }
            }
            printf("Size: %zu , Capacity: %zu\n\n" , Data->size , Data->capacity);

            return;
        }
        case VEC_STRING: {
            StrVec* Data = (StrVec*)vec->data;

            printf("Size: %zu , Capacity: %zu\n" , Data->size , Data->capacity);

            for (int i = 0; i < 100; i++) {
                char buf[32];
                snprintf(buf, sizeof(buf), "num_%d", i);
                char* copy = strdup(buf);
                
                if (!AppendVec(vec, &copy)) {
                    printf("Failed to append at %i iteration.\n" , i);
                    free(copy); 
                    break;
                }
            }

            printf("Size: %zu , Capacity: %zu\n\n" , Data->size , Data->capacity);

            return;
        }
        default: return;
    }
}

int main(int argc , char **argv) {
    Vector* IntVector = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVector) {
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    TestVec(IntVector);
    FreeVec(IntVector);

    Vector* FloatVector = InitVec(VEC_FLOAT, (float[]){1.1 , 2.2 , 3.3}, &(size_t){3});

    if (!FloatVector) {
        printf("Failed to initialize FloatVec.\n");
        return 1;
    }

    TestVec(FloatVector);
    FreeVec(FloatVector);

    Vector* CharVector = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVector) {
        printf("Failed to initialize CharVec.\n");
        return 1;
    }

    TestVec(CharVector);
    FreeVec(CharVector);

    Vector* StrVector = InitVec(VEC_STRING, (char*[]){"abc" , "def" ,"ghk"}, &(size_t){3});

    if (!StrVector) {
        printf("Failed to initialize StrVec.\n");
        return 1;
    }

    TestVec(StrVector);
    FreeVec(StrVector);

    return 0;
}