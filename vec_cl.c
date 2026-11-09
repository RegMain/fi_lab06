#include "vec_cl.h"
#include "vec_tr.h"
#include <stdint.h>
#include <stdlib.h>

vec_cl *vec_cl_init(int32_t size) {
  vec_cl *vec = (vec_cl *)malloc(sizeof(vec_cl));
  if (!vec) {
    return NULL;
  }
  vec->size = size;
  if (size == 0) {
    vec->capacity = 4;
  } else {
    vec->capacity = size;
  }
  vec->ptr = (client *)malloc(sizeof(client) * vec->capacity);
  if (!vec->ptr) {
    free(vec);
    return NULL; 
  }
  return vec;
}

int vec_cl_destroy(vec_cl *vec) {
  if (!vec) {
    return -1;
  }
  for (int32_t i = 0; i < vec->size; ++i) {
    if (vec->ptr[i].transactions) {
      vec_tr_destroy(vec->ptr[i].transactions);
    }
  }
  if (!vec->ptr) {
    free(vec);
    return 0;
  }
  free(vec->ptr);
  free(vec);
  return 0;
}

int vec_cl_set_size(vec_cl *vec, int32_t size) {
  if (!vec || size < 0) {
    return -1;
  }
  if (size < vec->capacity) {
    vec->size = size;
    return 0;
  }
  client *tmp = (client *)realloc(vec->ptr, sizeof(client) * size * 2);
  if (!tmp) {
    return -1;
  }
  vec->ptr = tmp;
  vec->size = size;
  vec->capacity = 2 * size;
  return 0;
}

int32_t *vec_cl_get_size(vec_cl *vec) {
  if (!vec) {
    return NULL;
  }
  return &vec->size;
}

int vec_cl_set(vec_cl *vec, int32_t index, client value) {
  if (!vec || !vec->ptr || index < 0 || index >= *vec_cl_get_size(vec)) {
    return -1;
  }
  vec->ptr[index] = value;
  return 0;
}

client *vec_cl_get(vec_cl *vec, int32_t index) {
  if (!vec || !vec->ptr || index < 0 || index >= *vec_cl_get_size(vec)) {
    return NULL;
  }
  return &vec->ptr[index];
}

int vec_cl_push(vec_cl *vec, client value) {
  if (!vec || !vec->ptr) {
    return -1;
  }
  if (vec_cl_set_size(vec, vec->size + 1) || vec_cl_set(vec, vec->size - 1, value)) {
    return -1;
  }
  return 0;
}
