#pragma once

#include <stdio.h>
#include "vectors.h"

struct IntVec {
    size_t size , capacity;
    int *vec;
};