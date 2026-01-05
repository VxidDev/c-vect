#include <vectors.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* sum_int(void* accumulator, void* item, void* ctx) {
    *(int*)accumulator += *(int*)item;
    return accumulator;
}

void* sum_float(void* accumulator, void* item, void* ctx) {
    *(float*)accumulator += *(float*)item;
    return accumulator;
}

void* concat_char(void* accumulator, void* item, void* ctx) {
    char* str_acc = (char*)accumulator;
    char c = *(char*)item;
    size_t len = strlen(str_acc);
    str_acc[len] = c;
    str_acc[len + 1] = '\0';
    return (void*)str_acc;
}

void* concat_str(void* accumulator, void* item, void* ctx) {
    char** str_acc_ptr = (char**)accumulator;
    char* current_str = *str_acc_ptr;
    char* item_str = *(char**)item;

    size_t current_len = (current_str ? strlen(current_str) : 0);
    size_t item_len = strlen(item_str);
    size_t new_len = current_len + item_len + 1;

    char* new_str = realloc(current_str, new_len);
    if (!new_str) {
        return accumulator;
    }
    
    if (current_len == 0) {
        new_str[0] = '\0';
    }
    
    strcat(new_str, item_str);
    *str_acc_ptr = new_str;
    return accumulator;
}

int main(int argc, char **argv) {
    // Test 1: Int Vector
    Vector* vec_int = InitVec(VEC_INT, (int[]){1, 2, 3, 4, 5}, &(size_t){5});
    if (!vec_int) {
        printf("Failed to init IntVec\n");
        return 1;
    }

    int initial_int = 0;
    ReduceVec(vec_int, sum_int, NULL, &initial_int);
    printf("Int Sum: %d (expected 15)\n", initial_int);
    FreeVec(vec_int);

    // Test 2: Float Vector
    Vector* vec_float = InitVec(VEC_FLOAT, (float[]){1.1, 2.2, 3.3}, &(size_t){3});
    if (!vec_float) {
        printf("Failed to init FloatVec\n");
        return 1;
    }

    float initial_float = 0.0f;
    ReduceVec(vec_float, sum_float, NULL, &initial_float);
    printf("Float Sum: %.1f (expected 6.6)\n", initial_float);
    FreeVec(vec_float);

    // Test 3: Char Vector
    Vector* vec_char = InitVec(VEC_CHAR, "abc", &(size_t){3});
    if (!vec_char) {
        printf("Failed to init CharVec\n");
        return 1;
    }

    char char_buf[16] = "";
    ReduceVec(vec_char, concat_char, NULL, char_buf);
    printf("Char Concat: %s (expected abc)\n", char_buf);
    FreeVec(vec_char);

    // Test 4: String Vector
    char* strs[] = {"Hello", " ", "World"};
    Vector* vec_str = InitVec(VEC_STRING, strs, &(size_t){3});
    if (!vec_str) {
        printf("Failed to init StrVec\n");
        return 1;
    }

    char* str_acc = NULL;
    ReduceVec(vec_str, concat_str, NULL, &str_acc);
    printf("String Concat: %s (expected Hello World)\n", str_acc ? str_acc : "NULL");
    
    if (str_acc) free(str_acc);
    FreeVec(vec_str);

    return 0;
}
