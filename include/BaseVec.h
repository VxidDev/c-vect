#pragma once

#include <stdio.h>
#include "vectors.h"

typedef struct {
    enum VecType type;
    void* data;
} Vector;