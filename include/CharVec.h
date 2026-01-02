#pragma once

#include <stdio.h>
#include "vectors.h"

typedef struct {
    size_t size , capacity;
    char *vec;
} CharVec;