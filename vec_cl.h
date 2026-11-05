#pragma once
#include <stdint.h>
#include "client.h"

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
