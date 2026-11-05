#pragma once
#include <stdint.h>
#include "models.h"

typedef struct {
  int32_t capacity;
  int32_t size;
  transaction *ptr;
} vec_tr;

vec_tr *vec_tr_init(int32_t size);

int vec_tr_destroy(vec_tr *vec);

int vec_tr_set_size(vec_tr *vec, int32_t size);

int32_t *vec_tr_get_size(vec_tr *vec);

int vec_tr_set(vec_tr *vec, int32_t index, transaction value);

transaction *vec_tr_get(vec_tr *vec, int32_t index);

int vec_tr_push(vec_tr *vec, transaction value);
