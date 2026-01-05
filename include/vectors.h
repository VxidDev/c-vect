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
Vector* FilterVec(Vector* vec , bool (*func)(void* item , void* ctx) , void* ctx);
Vector* MapVec(Vector* vec , void* (*func)(void* item , void* ctx) , void* ctx);

bool AppendVec(Vector* Vec , void* item);
bool RemoveFromVec(Vector* vec , size_t index);
bool InsertVec(Vector* vec, void* item, size_t index);
bool ExtendVec(Vector* vec , size_t size);
bool ResetVec(Vector* vec);
bool ShrinkToFitVec(Vector* vec);
bool ShrinkVec(Vector* vec , size_t size);
bool SetItemVec(Vector* vec, void* item, size_t index);
bool SortVec(Vector* vec, int(*compare)(const void* , const void*));
bool ContainsVec(Vector* vec, void* item);

void* GetLastVec(Vector* vec);
void* PopVec(Vector* vec);
void* GetItemFromVec(Vector* vec , size_t index);
void* FrontVec(Vector* vec);
void* BackVec(Vector* vec);
void* ReduceVec(Vector* vec , void* (*reducer)(void* , void* , void*) , void* ctx , void* init);

ptrdiff_t GetSizeVec(Vector* vec);
ptrdiff_t GetCapacityVec(Vector* vec);
ptrdiff_t IndexOfVec(Vector* vec , void* item);

void ForEachVec(Vector* vec , void (*func)(void* item , size_t idx));
void ClearVec(Vector* vec);
void FreeVec(Vector* vec);

void* SumVec(Vector* vec);
void* MaxVec(Vector* vec);
void* MinVec(Vector* vec);

int SortVec__CompInt(const void* a , const void* b);
int SortVec__CompFloat(const void* a, const void* b);
int SortVec__CompChar(const void* a, const void* b);
int SortVec__CompStr(const void* a, const void* b);