#include <vectors.h>

int main(int argc, char **argv) {
    printf("*-*-*-* Vectors Test *-*-*-*\n");
    struct IntVec *Vector = (struct IntVec*)InitVec(VEC_INT , (int[]){1 , 2 , 3 , 4 , 5} , &(int){5});

    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    if (Vector == NULL) {
        printf("Failed to initialize vector.\n");
        return 1;
    }

    printf("*-*-*-* InitVec Test Passed *-*-*-*\n");

    for (int i = 0; i < 30; i++) {
        AppendVec(Vector, &(int){i}, VEC_INT);
    }

    printf("*-*-*-* AppendVec Test Passed *-*-*-*\n");

    for (int i = 0; i < 30; i++) {
        printf("Index: %d , Value: %d\n" , i , *(int*)GetItemFromVec(Vector, i, VEC_INT));
    }

    printf("*-*-*-* GetItemFromVec Test Passed *-*-*-*\n\n");

    RemoveFromVec(Vector, 2, VEC_INT);
    
    printf("*-*-*-* RemoveFromVec Test Passed *-*-*-*\n");

    for (int i = 0; i < 4; i++) {
        printf("Index: %d , Value: %d\n" , i , *(int*)GetItemFromVec(Vector, i, VEC_INT));
    }

    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));
    ClearVec(Vector, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    printf("*-*-*-* ClearVec Test Passed *-*-*-*\n");

    ResetVec(Vector, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    for (int i = 0; i < 5; i++) {
        AppendVec(Vector, &(int){i}, VEC_INT);
    }

    for (int i = 0; i < 5; i++) {
        printf("Index: %d , Value: %d\n" , i , *(int*)GetItemFromVec(Vector, i, VEC_INT));
    }

    printf("*-*-*-* ResetVec Test Passed *-*-*-*\n");

    ShrinkToFitVec(Vector, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    printf("*-*-*-* ShrinkToFitVec Test Passed *-*-*-*\n");

    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    for (int i = 0; i < 3; i++) {
        AppendVec(Vector, &(int){i}, VEC_INT);
    }

    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    ShrinkVec(Vector, 1, VEC_INT);
    ShrinkVec(Vector, 15, VEC_INT);
    ShrinkVec(Vector, 9, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));
    ShrinkVec(Vector, 8, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    printf("*-*-*-* ShrinkVec Test Passed *-*-*-*\n");

    ExtendVec(Vector, 5, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));
    ExtendVec(Vector, 8, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));
    ExtendVec(Vector, 20, VEC_INT);
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    printf("*-*-*-* ExtendVec Test Passed *-*-*-*\n");

    InsertVec(Vector , &(int){1} , 3 , VEC_INT);
    printf("Index: %i , Item: %i\n" , 3 , *(int*)GetItemFromVec(Vector, 3, VEC_INT));
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));
    if (InsertVec(Vector , &(int){1} , 7 , VEC_INT)) printf("Index: %i , Item: %i\n" , 7 , *(int*)GetItemFromVec(Vector, 7, VEC_INT));;
    printf("\nSize: %zu , Capacity: %zu\n" , GetSizeVec(Vector, VEC_INT) , GetCapacityVec(Vector, VEC_INT));

    printf("*-*-*-* InsertVec Test Passed *-*-*-*\n");

    SetItemVec(Vector, &(int){7}, 7, VEC_INT);
    printf("Index: 7 , Value: %i\n" , *(int*)GetItemFromVec(Vector, 7, VEC_INT));

    printf("*-*-*-* SetItemVec Test Passed *-*-*-*\n");

    FreeVec(Vector, VEC_INT);

    printf("*-*-*-* SUCCESS *-*-*-*\n");

    return 0;
}