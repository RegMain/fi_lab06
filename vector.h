#pragma once
#include <stdint.h>
#include "service.h"

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

typedef struct {
  int32_t capacity;
  int32_t size;
  client *ptr;
} vec_cl;

vec_cl *vec_cl_init(int32_t size);

int vec_cl_destroy(vec_cl *vec);

int vec_cl_set_size(vec_cl *vec, int32_t size);

int32_t *vec_cl_get_size(vec_cl *vec);

int vec_cl_set(vec_cl *vec, int32_t index, client value);

client *vec_cl_get(vec_cl *vec, int32_t index);

int vec_cl_push(vec_cl *vec, client value);
