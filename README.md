# c-vector 🧮

Zero-dependency dynamic arrays for C
int*, float*, char*, char** vectors with auto-resizing.
Features
   - ✅ 4 types: int, float, char, char** (strings)
   - ✅ Auto-grow: capacity *= 2 (starts at 16)
   - ✅ Zero-init: calloc() safety
   - ✅ Leak-proof: FreeVec() double-free protection

## Quick Start
```C
#include <vectors.h>

int main() {
    Vector* IntVector = InitVec(VEC_INT , (int[]){1 , 2 , 3} , &(size_t){3}); // Initialize Vector

    if (!IntVector) {  // Check if successfully created vector
        printf("Failed to initialize IntVec.\n");
        return 1;
    }

    for (size_t i = 0; i < Data->size; i++) { // Print vector's data
         printf("Item @ %zu -> %i\n" , i , GetItemFromVec(IntVector , i));
    }
    
    FreeVec(IntVector); // Free Vector.
    return 0;
}
```
## Build

```bash
git clone https://github.com/VxidDev/c-vect.git
cd c-vect
make          # Build libvectors.a
make install  # Install system-wide
```

### Build Targets
| Command      | Does                       |
| ------------ | -------------------------- |
| make         | Build libvectors.a         |
| make clean   | Delete build files         |
| make install | Install to /usr/local/     |
| make format  | Format code (clang-format) |
| make check   | Static analysis (cppcheck) |

Using the Library
1. System-wide (after make install)
```C
#include <vectors.h>  // Standard include!
```
```bash
gcc main.c -lvectors -o app
./app
```

## API
'*' before a function name means function is re-factored and now usable.

| Function                                                   | Usage                                 | Description                                                                                                                                |
| ---------------------------------------------------------- | ------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------|
| * InitVec(enum VecType type, void arr, void arrlen)**      | vec = InitVec(VEC_INT, arr, &arrlen)  | Initialize a new vector with optional source array and length. If arr and arrlen is NULL, creates an empty Vector* (default capacity = 16).|
| * AppendVec(Vector* vec, void item)**                      | AppendVec(vec, &value)                | Append an element to the end of the vector. Automatically resizes (×2) as needed.                                                          |
| * FreeVec(Vector* vec)*                                    | FreeVec(vec)                          | Free all allocated memory associated with the vector.                                                                                      |
| * GetLastVec(Vector* vec)*                                 | ptr = GetLastVec(vec)                 | Get a pointer to the last element, or NULL if the vector is empty.                                                                         |
| * PopVec(Vector* vec)*                                     | ptr = PopVec(vec)                     | Remove and return a pointer to the last element. Returns NULL if the vector is empty.                                                      |
| * RemoveFromVec(Vector* vec, size_t index)*                | ok = RemoveFromVec(vec, 2)            | Remove element at a given index (shifts left). Returns true if successful.                                                                 |
| * GetItemFromVec(Vector* vec, size_t index)*               | ptr = GetItemFromVec(vec, 2)          | Return a pointer to the element at index, or NULL if invalid.                                                                              |
| * ClearVec(Vector* vec)*                                   | ClearVec(vec)                         | Clear all elements but keep allocated memory (capacity unchanged, size = 0).                                                               |
| * ResetVec(Vector* vec)*                                   | ResetVec(vec)                         | Reset vector to its initial empty state (capacity reset to default, e.g., 16). Returns true if successful.                                 |
| * ShrinkToFitVec(Vector* vec)*                             | ShrinkToFitVec(vec)                   | Shrink capacity to match the current number of elements. Returns true if reallocation succeeded.                                           |
| * ShrinkVec(Vector* vec, size_t size)*                     | ShrinkVec(vec, 8)                     | Reduce vector capacity to the specified new size (if smaller than current capacity). Returns true if successful.                           |
| * ExtendVec(Vector* vec, size_t size)*                     | ExtendVec(vec, 64)                    | Increase vector capacity to at least the specified size. Does not modify the element count. Returns true if successful.                    |
| * GetSizeVec(Vector* vec)                                  | size = GetSizeVec(vec)                | Return size (ptrdiff_t): ≥0=valid,   -1=ERROR   (NULL/corrupted vec).                                                                      |
| * GetCapacityVec(Vector* vec)                              | cap = GetCapacityVec(vec)             | Return capacity (ptrdiff_t): ≥0=valid, -1=ERROR.                                                                                           |
| * InsertVec(Vector* vec, void* item, size_t index)         | ok = InsertVec(Vector , &(int){1} , 3)| Insert specified item at selected index. Returns ```true``` if success, otherwise returns ```false```.                                     |
| * SetItemVec(Vector* vec, void* item, size_t index)        | ok = SetItemVec(Vector, &(int){7}, 7) | Change replace value of specified index with given item. Returns ```true``` if success, otherwise returns ```false```.                     |
| * SortVec(Vector* vec, int(* compare)(const void* , const void*))| ok = SortVec(Vector , NULL)     | Sort vector via quick sort with pre-made or your own criteria. Returns ```true``` if success, otherwise returns ```false```.               |
| * ContainsVec(Vector* vec , void* item)                    | ok = ContainsVec(Vector , &(int){3}   | Check if vector contains given item. Return ```true``` if does, otherwise returns ```false```. Algorithm complexity O(n).                  |
| * ForEachVec(Vector* vec , void (* func)(void* item , size_t idx)) | ForEachVec(Vector , PrintItem) | Repeat given instruction for each item in the vector. |

Types: VEC_INT, VEC_FLOAT, VEC_CHAR, VEC_STRING

## Memory Layout
```
[ struct: size/capacity ] → vec → [ data array ]
free(data) → free(struct)  ✅
```

## Safety Rules

  - Always check InitVec != NULL

  - Use LastVec/GetItemFromVec results IMMEDIATELY (internal pointers become invalid after AppendVec/PopVec)

  - VEC_STRING: Don't free returned pointers

  - Capacity doubles automatically on append

  - Invalid index prints error message, returns NULL



