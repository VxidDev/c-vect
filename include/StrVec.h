#pragma once

#include <stdio.h>
#include "vectors.h"

struct StrVec {
    size_t size , capacity;
    char **vec;
};