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

| Function                       | Usage         |
| ------------------------------ | ------------- |
| InitVec(VEC_INT)               | Create vector |
| AppendVec(vec, &item, VEC_INT) | Add item      |
| FreeVec(vec, VEC_INT)          | Cleanup       |

Types: VEC_INT, VEC_FLOAT, VEC_CHAR, VEC_STRING

## Memory Layout
```
[ struct: size/capacity ] → vec → [ data array ]
free(data) → free(struct)  ✅
```

Single header → zero deps → production ready! 🚀



(Made in 2h T-T)


