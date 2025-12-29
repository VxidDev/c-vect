#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum VecType { VEC_CHAR , VEC_STRING , VEC_INT , VEC_FLOAT };

#include "FloatVec.h"
#include "CharVec.h"
#include "IntVec.h"
#include "StrVec.h"

void* InitVec(enum VecType type);
void AppendVec(void* vec , void* item , enum VecType type);
void FreeVec(void* vec , enum VecType type);
void* GetLastVec(void* vec , enum VecType type);
void* PopVec(void* vec , enum VecType type);
bool RemoveFromVec(void* vec , size_t index , enum VecType type);
void* GetItemFromVec(void* vec , size_t index , enum VecType type);