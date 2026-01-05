#include <vectors.h>
#include <stdio.h>

void* add_val(void* item, void* ctx) {
    *(int*)item += *(int*)ctx;

    return item;
}

void* mul_val(void* item, void* ctx) {
    *(float*)item *= *(float*)ctx;

    return item;
}

void* to_upper(void* item, void* ctx) {
    char* c = (char*)item;
    if (*c >= 'a' && *c <= 'z') {
        *c -= 32;
    }

    return c;
}

void* replace_str(void* item, void* ctx) {
    return ctx;
}

int main(int argc, char **argv) {
    // Test 1: Int Vector
    Vector* vec_int = InitVec(VEC_INT, (int[]){1, 2, 3}, &(size_t){3});
    if (!vec_int) {
        printf("Failed to init IntVec\n");
        return 1;
    }

    int val = 10;
    MapVec(vec_int, add_val, &val);

    printf("Int Items: ");
    for (size_t i = 0; i < GetSizeVec(vec_int); i++) {
        printf("%d ", *(int*)GetItemFromVec(vec_int, i));
    }
    printf("(expected 11 12 13)\n");
    FreeVec(vec_int);

    // Test 2: Float Vector
    Vector* vec_float = InitVec(VEC_FLOAT, (float[]){1.1, 2.2, 3.3}, &(size_t){3});
    if (!vec_float) {
        printf("Failed to init FloatVec\n");
        return 1;
    }

    float factor = 2.0f;
    MapVec(vec_float, mul_val, &factor);

    printf("Float Items: ");
    for (size_t i = 0; i < GetSizeVec(vec_float); i++) {
        printf("%.1f ", *(float*)GetItemFromVec(vec_float, i));
    }
    printf("(expected 2.2 4.4 6.6)\n");
    FreeVec(vec_float);

    // Test 3: Char Vector
    Vector* vec_char = InitVec(VEC_CHAR, "abc", &(size_t){3});
    if (!vec_char) {
        printf("Failed to init CharVec\n");
        return 1;
    }

    MapVec(vec_char, to_upper, NULL);

    printf("Char Items: ");
    for (size_t i = 0; i < GetSizeVec(vec_char); i++) {
        printf("%c", *(char*)GetItemFromVec(vec_char, i));
    }
    printf(" (expected ABC)\n");
    FreeVec(vec_char);

    // Test 4: String Vector
    char* strs[] = {"one", "two", "three"};
    Vector* vec_str = InitVec(VEC_STRING, strs, &(size_t){3});
    if (!vec_str) {
        printf("Failed to init StrVec\n");
        return 1;
    }

    char* replacement = "zero";
    MapVec(vec_str, replace_str, replacement);

    printf("String Items: ");
    for (size_t i = 0; i < GetSizeVec(vec_str); i++) {
        printf("%s ", *(char**)GetItemFromVec(vec_str, i));
    }
    printf("(expected zero zero zero)\n");
    FreeVec(vec_str);

    return 0;
}