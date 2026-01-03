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

    const IntVec* Data = (const IntVec*)IntVector->data; // Extract Data from vector (functions to access vector's data are still not refactored);
    for (size_t i = 0; i < Data->size; i++) { // Print vector's data
         printf("Item @ %zu -> %i\n" , i , Data->vec[i]);
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
| * AppendVec(void vec, void item, enum VecType type)**      | AppendVec(vec, &value, VEC_INT)       | Append an element to the end of the vector. Automatically resizes (×2) as needed.                                                          |
| * FreeVec(void vec, enum VecType type)*                    | FreeVec(vec, VEC_INT)                 | Free all allocated memory associated with the vector.                                                                                      |
| * GetLastVec(void vec, enum VecType type)*                 | ptr = GetLastVec(vec, VEC_INT)        | Get a pointer to the last element, or NULL if the vector is empty.                                                                         |
| PopVec(void vec, enum VecType type)*                       | ptr = PopVec(vec, VEC_INT)            | Remove and return a pointer to the last element. Returns NULL if the vector is empty.                                                      |
| RemoveFromVec(void vec, size_t index, enum VecType type)*  | ok = RemoveFromVec(vec, 2, VEC_INT)   | Remove element at a given index (shifts left). Returns true if successful.                                                                 |
| GetItemFromVec(void vec, size_t index, enum VecType type)* | ptr = GetItemFromVec(vec, 2, VEC_INT) | Return a pointer to the element at index, or NULL if invalid.                                                                              |
| ClearVec(void vec, enum VecType type)*                     | ClearVec(vec, VEC_INT)                | Clear all elements but keep allocated memory (capacity unchanged, size = 0).                                                               |
| ResetVec(void vec, enum VecType type)*                     | ResetVec(vec, VEC_INT)                | Reset vector to its initial empty state (capacity reset to default, e.g., 16). Returns true if successful.                                 |
| ShrinkToFitVec(void vec, enum VecType type)*               | ShrinkToFitVec(vec, VEC_INT)          | Shrink capacity to match the current number of elements. Frees unused memory. Returns true if reallocation succeeded.                      |
| ShrinkVec(void vec, size_t size, enum VecType type)*       | ShrinkVec(vec, 8, VEC_INT)            | Reduce vector capacity to the specified new size (if smaller than current capacity). Returns true if successful.                           |
| ExtendVec(void vec, size_t size, enum VecType type)*       | ExtendVec(vec, 64, VEC_INT)           | Increase vector capacity to at least the specified size. Does not modify the element count. Returns true if successful.                    |
| GetSizeVec(void* vec, enum VecType type)                   | size = GetSizeVec(vec, VEC_INT)       | Return size (ptrdiff_t): ≥0=valid,   -1=ERROR   (NULL/corrupted vec).                                                                      |
| GetCapacityVec(void* vec, enum VecType type)               | cap = GetCapacityVec(vec, VEC_INT)    | Return capacity (ptrdiff_t): ≥0=valid, -1=ERROR.                                                                                           |
| InsertVec(void* vec, void* item, size_t index, enum VecType type)| rslt = InsertVec(Vector , &(int){1} , 3 , VEC_INT);| Insert specified item at selected index. Returns ```true``` if success, otherwise returns ```false```.                  |
| SetItemVec(void* vec, void* item, size_t index, enum VecType type)| rslt = SetItemVec(Vector, &(int){7}, 7, VEC_INT); | Change replace value of specified index with given item. Returns ```true``` if success, otherwise returns ```false```.  |
| `SortVec(void* vec, int(*compare)(const void* , const void*) , enum VecType type)`| rslt = SortVec(Vector , NULL , VEC_INT);| Sort vector via quick sort with pre-made or your own criteria. Returns ```true``` if success, otherwise returns ```false```. |

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



