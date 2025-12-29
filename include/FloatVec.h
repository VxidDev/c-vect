#pragma once

#include <stdio.h>
#include "vectors.h"

struct FloatVec {
    size_t size , capacity;
    float *vec;
};