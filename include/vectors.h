#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum VecType { VEC_CHAR , VEC_STRING , VEC_INT , VEC_FLOAT };

#include "FloatVec.h"
#include "CharVec.h"
#include "IntVec.h"
#include "StrVec.h"
#include "BaseVec.h"

Vector* InitVec(enum VecType type, void* arr , void* arrlen);

bool AppendVec(Vector* Vec , void* item);
bool RemoveFromVec(Vector* vec , size_t index);
bool InsertVec(Vector* vec, void* item, size_t index);
bool ExtendVec(Vector* vec , size_t size);

void* GetLastVec(Vector* vec);
void* PopVec(Vector* vec);
void* GetItemFromVec(Vector* vec , size_t index);

ptrdiff_t GetSizeVec(Vector* vec);
ptrdiff_t GetCapacityVec(Vector* vec);

void ClearVec(Vector* vec);
void FreeVec(Vector* vec);

bool ResetVec(void* vec , enum VecType type);
bool ShrinkToFitVec(void* vec , enum VecType type);
bool ShrinkVec(void* vec , size_t size , enum VecType type);
bool SetItemVec(void* vec, void* item, size_t index, enum VecType type);
bool ContainsVec(void* vec, void* item, enum VecType type);
bool SortVec(void* vec, int(*compare)(const void* , const void*) , enum VecType type);
int SortVec__CompInt(const void* a , const void* b);
int SortVec__CompFloat(const void* a, const void* b);
int SortVec__CompChar(const void* a, const void* b);
int SortVec__CompStr(const void* a, const void* b);