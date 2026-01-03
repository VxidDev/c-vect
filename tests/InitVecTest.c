#include <vectors.h>

void PrintVecData(void* vec) {
    Vector* Vect = (Vector*)vec;

    char *SVecType = Vect->type == 0 ? "VEC_CHAR" :               // Convert VEC_TYPE [int] to string
                     Vect->type == 1 ? "VEC_STRING" :
                     Vect->type == 2 ? "VEC_INT" :
                     Vect->type == 3 ? "VEC_FLOAT" : "unknown";

    printf("Vector's Type: %s\n\n" , SVecType);

    switch (Vect->type) {
        case VEC_INT: {
            IntVec* Data = (IntVec*)Vect->data;

            for (int i = 0; i < Data->size; i++) {
                printf("Item@Idx.%i -> %i\n" , i , Data->vec[i]);
            }

            printf("\nVector's Data:\nSize -> %zu | Capacity -> %zu\n" , Data->size , Data->capacity);
            
            break;
        }
        case VEC_FLOAT: {
            FloatVec* Data = (FloatVec*)Vect->data;

            for (int i = 0; i < Data->size; i++) {
                printf("Item@Idx.%i -> %f\n" , i , Data->vec[i]);
            }

            printf("\nVector's Data:\nSize -> %zu | Capacity -> %zu\n" , Data->size , Data->capacity);
            
            break;
        }
        case VEC_CHAR: {
            CharVec* Data = (CharVec*)Vect->data;

            for (int i = 0; i < Data->size; i++) {
                printf("Item@Idx.%i -> %c\n" , i , Data->vec[i]);
            }

            printf("\nVector's Data:\nSize -> %zu | Capacity -> %zu\n" , Data->size , Data->capacity);
            
            break;
        }
        case VEC_STRING: {
            StrVec* Data = (StrVec*)Vect->data;

            for (int i = 0; i < Data->size; i++) {
                printf("Item@Idx.%i -> %s\n" , i , Data->vec[i]);
            }

            printf("\nVector's Data:\nSize -> %zu | Capacity -> %zu\n" , Data->size , Data->capacity);
            
            break;
        }
    } 
}

int main(int argc , char **argv) {
    Vector* IntVector = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVector) {
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    PrintVecData(IntVector);

    FreeVec(IntVector);

    Vector* FloatVector = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVector) {
        printf("Failed to initialize FloatVec.\n");
        return 1;
    }

    PrintVecData(FloatVector);

    FreeVec(FloatVector);

    Vector* CharVector = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVector) {
        printf("Failed to initialize CharVec.\n");
        return 1;
    }

    PrintVecData(CharVector);

    Vector* StrVector = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVector) {
        printf("Failed to initialize StrVec.\n");
        return 1;
    }

    PrintVecData(StrVector);

    FreeVec(StrVector);

    return 0;
}