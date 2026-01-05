#include <vectors.h>
#include <string.h>
#include <stdio.h>

bool is_even(void* item, void* ctx) {
    return (*(int*)item) % 2 == 0;
}

bool is_greater_than(void* item, void* ctx) {
    return (*(float*)item) > (*(float*)ctx);
}

bool is_vowel(void* item, void* ctx) {
    char c = *(char*)item;
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool contains_str(void* item, void* ctx) {
    return strstr(*(char**)item, (char*)ctx) != NULL;
}

int main(int argc, char **argv) {
    // Test 1: Int Vector
    Vector* vec_int = InitVec(VEC_INT, (int[]){1, 2, 3, 4, 5, 6}, &(size_t){6});
    if (!vec_int) {
        printf("Failed to init IntVec\n");
        return 1;
    }

    printf("Original Int Vector size: %td\n", GetSizeVec(vec_int));
    FilterVec(vec_int, is_even, NULL);
    printf("Filtered Int Vector size: %td (expected 3)\n", GetSizeVec(vec_int));
    
    printf("Items: ");
    for (ptrdiff_t i = 0; i < GetSizeVec(vec_int); i++) {
        printf("%d ", *(int*)GetItemFromVec(vec_int, i));
    }
    printf("(expected 2 4 6)\n\n");
    FreeVec(vec_int);

    // Test 2: Float Vector
    Vector* vec_float = InitVec(VEC_FLOAT, (float[]){1.1, 2.2, 3.3, 4.4}, &(size_t){4});
    if (!vec_float) {
        printf("Failed to init FloatVec\n");
        return 1;
    }

    float threshold = 3.0f;
    printf("Original Float Vector size: %td\n", GetSizeVec(vec_float));
    FilterVec(vec_float, is_greater_than, &threshold);
    printf("Filtered Float Vector size: %td (expected 2)\n", GetSizeVec(vec_float));

    printf("Items: ");
    for (ptrdiff_t i = 0; i < GetSizeVec(vec_float); i++) {
        printf("%.1f ", *(float*)GetItemFromVec(vec_float, i));
    }
    printf("(expected 3.3 4.4)\n\n");
    FreeVec(vec_float);

    // Test 3: Char Vector
    Vector* vec_char = InitVec(VEC_CHAR, "hello", &(size_t){5});
    if (!vec_char) {
        printf("Failed to init CharVec\n");
        return 1;
    }

    printf("Original Char Vector size: %td\n", GetSizeVec(vec_char));
    FilterVec(vec_char, is_vowel, NULL);
    printf("Filtered Char Vector size: %td (expected 2)\n", GetSizeVec(vec_char));

    printf("Items: ");
    for (ptrdiff_t i = 0; i < GetSizeVec(vec_char); i++) {
        printf("%c", *(char*)GetItemFromVec(vec_char, i));
    }
    printf(" (expected eo)\n\n");
    FreeVec(vec_char);

    // Test 4: String Vector
    char* strs[] = {"apple", "banana", "cherry", "date"};
    Vector* vec_str = InitVec(VEC_STRING, strs, &(size_t){4});
    if (!vec_str) {
        printf("Failed to init StrVec\n");
        return 1;
    }

    char* sub = "a";
    printf("Original String Vector size: %td\n", GetSizeVec(vec_str));
    FilterVec(vec_str, contains_str, sub);
    printf("Filtered String Vector size: %td (expected 3)\n", GetSizeVec(vec_str));

    printf("Items: ");
    for (ptrdiff_t i = 0; i < GetSizeVec(vec_str); i++) {
        printf("\"%s\" ", *(char**)GetItemFromVec(vec_str, i));
    }
    printf("(expected \"apple\" \"banana\" \"date\")\n");
    FreeVec(vec_str);

    return 0;
}
