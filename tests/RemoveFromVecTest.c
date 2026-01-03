#include <vectors.h>

void TestVec(Vector* vec) {
    switch (vec->type) {
        case VEC_INT: {
            IntVec* data = (IntVec*)vec->data;
            
            printf("Pre-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %i\n" , data->size , data->capacity , data->vec[1]);
            RemoveFromVec(vec, 1);
            printf("After-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %i\n\n" , data->size , data->capacity , data->vec[1]);

            return;
        }
        case VEC_FLOAT: {
            FloatVec* data = (FloatVec*)vec->data;
            
            printf("Pre-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %f\n" , data->size , data->capacity , data->vec[1]);
            RemoveFromVec(vec, 1);
            printf("After-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %f\n\n" , data->size , data->capacity , data->vec[1]);

            return;
        }
        case VEC_CHAR: {
            CharVec* data = (CharVec*)vec->data;
            
            printf("Pre-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %c\n" , data->size , data->capacity , data->vec[1]);
            RemoveFromVec(vec, 1);
            printf("After-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %c\n\n" , data->size , data->capacity , data->vec[1]);

            return;
        }
        case VEC_STRING: {
            StrVec* data = (StrVec*)vec->data;
            
            printf("Pre-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %s\n" , data->size , data->capacity , data->vec[1]);
            RemoveFromVec(vec, 1);
            printf("After-Removal -> size: %zu , capacity: %zu | item@idx.1 -> %s\n\n" , data->size , data->capacity , data->vec[1]);

            return;
        }

        FreeVec(vec);
    }
}

int main(int argc , char **argv) {
    Vector* IntVec = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3});

    if (!IntVec) {
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    TestVec(IntVec);

    Vector* FloatVec = InitVec(VEC_FLOAT , (float[]){1.1 , 2.2 , 3.3} , &(size_t){3});

    if (!FloatVec) {
        printf("Failed to initialize FloatVec.\n");
        return 1;
    }

    TestVec(FloatVec);

    Vector* CharVec = InitVec(VEC_CHAR , "abc" , &(size_t){3});

    if (!CharVec) {
        printf("Failed to initialize CharVec.\n");
        return 1;
    }

    TestVec(CharVec);

    Vector* StrVec = InitVec(VEC_STRING , (char*[]){"abc" , "def" , "ghk"} , &(size_t){3});

    if (!StrVec) {
        printf("Failed to initialize StrVec.\n");
        return 1;
    }

    TestVec(StrVec);

    return 0;
}