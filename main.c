#include "vectors.h"

int main(int argc, char **argv) {
    struct IntVec *Vector = (struct IntVec*)InitVec(VEC_INT);

    if (Vector == NULL) {
        printf("Failed to initialize vector.\n");
        return 1;
    }

    for (int i = 0; i < 2147; i++) {
        AppendVec(Vector, &(int){i}, VEC_INT);
    }

    printf("Size: %zu\nCapacity: %zu\n", Vector->size, Vector->capacity);

    FreeVec(Vector, VEC_INT);

    return 0;
}