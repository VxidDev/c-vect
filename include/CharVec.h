#pragma once

#include <stdio.h>
#include "vectors.h"

struct CharVec {
    size_t size , capacity;
    char *vec;
};