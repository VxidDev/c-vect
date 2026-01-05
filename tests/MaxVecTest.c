#include <vectors.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Test 1: Integer Vector Max
    printf("--- Test 1: VEC_INT ---\n");
    int int_data[] = {10, 20, 5, 40, 15};
    size_t int_len = 5;
    Vector* vec_int = InitVec(VEC_INT, int_data, &int_len);
    
    if (vec_int) {
        int* result = (int*)MaxVec(vec_int);
        if (result) {
            printf("Max: %d (Expected: 40)\n", *result);
        } else {
            printf("MaxVec returned NULL for VEC_INT.\n");
        }
        FreeVec(vec_int);
    } else {
        printf("Failed to initialize VEC_INT.\n");
    }

    // Test 2: Float Vector Max
    printf("\n--- Test 2: VEC_FLOAT ---\n");
    float float_data[] = {1.5f, 2.5f, 0.8f, 3.5f, 2.1f};
    size_t float_len = 5;
    Vector* vec_float = InitVec(VEC_FLOAT, float_data, &float_len);

    if (vec_float) {
        float* result = (float*)MaxVec(vec_float);
        if (result) {
            printf("Max: %.2f (Expected: 3.50)\n", *result);
        } else {
            printf("MaxVec returned NULL for VEC_FLOAT.\n");
        }
        FreeVec(vec_float);
    } else {
        printf("Failed to initialize VEC_FLOAT.\n");
    }

    // Test 3: Empty Vector
    printf("\n--- Test 3: Empty VEC_INT ---\n");
    Vector* vec_empty = InitVec(VEC_INT, NULL, NULL);
    if (vec_empty) {
        int* result = (int*)MaxVec(vec_empty);
        if (result) {
            printf("Max: %d (Unexpected)\n", *result);
        } else {
            printf("MaxVec returned NULL for empty vector (Expected).\n");
        }
        FreeVec(vec_empty);
    }

    // Test 4: Unsupported Type (VEC_STRING)
    printf("\n--- Test 4: VEC_STRING (Unsupported) ---\n");
    char* str_data[] = {"a", "b"};
    size_t str_len = 2;
    Vector* vec_str = InitVec(VEC_STRING, str_data, &str_len);
    if (vec_str) {
        void* result = MaxVec(vec_str);
        if (result == NULL) {
            printf("MaxVec correctly returned NULL for VEC_STRING.\n");
        } else {
            printf("MaxVec returned non-NULL for VEC_STRING.\n");
            free(result);
        }
        FreeVec(vec_str);
    }

    return 0;
}