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
#include "vectors.h"

int main() {
    // Create
    struct IntVec* vec = InitVec(VEC_INT);
    
    // Append
    AppendVec(vec, &(int){123}, VEC_INT);
    
    // Use
    printf("Value: %d\n", vec->vec[0]);  // 67
    
    // Free (2 allocations)
    FreeVec(vec, VEC_INT);
}
```
## API

| Function                                                 | Usage                                 | Description                                                     |
| -------------------------------------------------------- | ------------------------------------- | --------------------------------------------------------------- |
| InitVec(enum VecType type)                               | vec = InitVec(VEC_INT)                | Create new vector (capacity=16)                                 |
| AppendVec(void* vec, void* item, enum VecType type)      | AppendVec(vec, &value, VEC_INT)       | Add item (auto-resizes x2)                                      |
| FreeVec(void* vec, enum VecType type)                    | FreeVec(vec, VEC_INT)                 | Cleanup memory                                                  |
| GetLastVec(void* vec, enum VecType type)                 | ptr = LastVec(vec, VEC_INT)        | Get pointer to last element (NULL if empty)                        |
| GetItemFromVec(void* vec, size_t idx, enum VecType type) | ptr = GetItemFromVec(vec, 2, VEC_INT) | Get pointer to element at index (NULL if invalid)               |
| PopVec(void* vec, enum VecType type)                     | PopVec(vec, VEC_INT)                  | Remove last element                                             |
| PopAtIndex(void* vec, size_t idx, enum VecType type)     | PopAtIndex(vec, 2, VEC_INT)           | Remove element at index (shifts left)                           |

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



