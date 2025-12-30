# c-vector 🧮

Zero-dependency dynamic arrays for C
int*, float*, char*, char** vectors with auto-resizing.
Features
   - ✅ 4 types: int, float, char, char** (strings)
   - ✅ Auto-grow: capacity *= 2 (starts at 16)
   - ✅ Zero-init: calloc() safety
   - ✅ Leak-proof: FreeVec() double-free protection
   - ✅ Single header: Drop-in vectors.h

## Quick Start
```C
#include <vectors.h>

int main() {
    struct IntVec* vec = InitVec(VEC_INT, NULL , NULL);
    if (!vec) return 1;
    
    // Add elements
    for (int i = 0; i < 20; i++) {
        AppendVec(vec, &(int){i}, VEC_INT);
    }
    
    printf("Size: %zu, Capacity: %zu\n", 
           vec->size, 
           vec->capacity);
    
    // Access & modify
    int* last = GetLastVec(vec, VEC_INT);
    if (last) *last = 999;
    
    // Iterate safely
    for (size_t i = 0; i < SizeVec(vec, VEC_INT); i++) {
        int* item = GetItemFromVec(vec, i, VEC_INT);
        if (item) printf("%d ", *item);
    }
    printf("\n");
    
    FreeVec(vec, VEC_INT);
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

int main() {
    void* vec = InitVec(VEC_INT);
    AppendVec(vec, &(int){42}, VEC_INT);
    FreeVec(vec, VEC_INT);
    return 0;
}
```
```bash
gcc main.c -lvectors -o app
./app
```

## API

| Function                                                   | Usage                                 | Description                                                                                                                                |
| ---------------------------------------------------------- | ------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------|
| InitVec(enum VecType type, void arr, void arrlen)**        | vec = InitVec(VEC_INT, arr, &arrlen)  | Initialize a new vector with optional source array and length. If arr and arrlen is NULL, creates an empty vector (default capacity = 16). |
| AppendVec(void vec, void item, enum VecType type)**        | AppendVec(vec, &value, VEC_INT)       | Append an element to the end of the vector. Automatically resizes (×2) as needed.                                                          |
| FreeVec(void vec, enum VecType type)*                      | FreeVec(vec, VEC_INT)                 | Free all allocated memory associated with the vector.                                                                                      |
| GetLastVec(void vec, enum VecType type)*                   | ptr = GetLastVec(vec, VEC_INT)        | Get a pointer to the last element, or NULL if the vector is empty.                                                                         |
| PopVec(void vec, enum VecType type)*                       | ptr = PopVec(vec, VEC_INT)            | Remove and return a pointer to the last element. Returns NULL if the vector is empty.                                                      |
| RemoveFromVec(void vec, size_t index, enum VecType type)*  | ok = RemoveFromVec(vec, 2, VEC_INT)   | Remove element at a given index (shifts left). Returns true if successful.                                                                 |
| GetItemFromVec(void vec, size_t index, enum VecType type)* | ptr = GetItemFromVec(vec, 2, VEC_INT) | Return a pointer to the element at index, or NULL if invalid.                                                                              |
| ClearVec(void vec, enum VecType type)*                     | ClearVec(vec, VEC_INT)                | Clear all elements but keep allocated memory (capacity unchanged, size = 0).                                                               |
| ResetVec(void vec, enum VecType type)*                     | ResetVec(vec, VEC_INT)                | Reset vector to its initial empty state (capacity reset to default, e.g., 16). Returns true if successful.                                 |
| ShrinkToFitVec(void vec, enum VecType type)*               | ShrinkToFitVec(vec, VEC_INT)          | Shrink capacity to match the current number of elements. Frees unused memory. Returns true if reallocation succeeded.                      |
| ShrinkVec(void vec, size_t size, enum VecType type)*       | ShrinkVec(vec, 8, VEC_INT)            | Reduce vector capacity to the specified new size (if smaller than current capacity). Returns true if successful.                           |
| ExtendVec(void vec, size_t size, enum VecType type)*       | ExtendVec(vec, 64, VEC_INT)           | Increase vector capacity to at least the specified size. Does not modify the element count. Returns true if successful.                    |

Types: VEC_INT, VEC_FLOAT, VEC_CHAR, VEC_STRING

## Memory Layout
```
[ struct: size/capacity ] → vec → [ data array ]
free(data) → free(struct)  ✅
```

Single header → zero deps → production ready! 🚀

## Safety Rules

  - Always check InitVec != NULL

  - Use LastVec/GetItemFromVec results IMMEDIATELY (internal pointers become invalid after AppendVec/PopVec)

  - VEC_STRING: Don't free returned pointers

  - Capacity doubles automatically on append

  - Invalid index prints error message, returns NULL



