#include <stdint.h>
#include <stdlib.h>
#include "vec_tr.h"

vec_tr *vec_tr_init(int32_t size) {
  vec_tr *vec = (vec_tr *)malloc(sizeof(vec_tr));
  if (!vec) {
    return NULL;
  }
  vec->size = size;
  vec->capacity = size;
  vec->ptr = (transaction *)malloc(sizeof(transaction) * vec->capacity);
  if (!vec->ptr) {
    free(vec);
    return NULL; 
  }
  return vec;
}

int vec_tr_destroy(vec_tr *vec) {
  if (!vec) {
    return -1;
  }
  free(vec);
}

int vec_tr_set_size(vec_tr *vec, int32_t size) {
  if (!vec || size < 0) {
    return -1;
  }
  if (size < vec->capacity) {
    return 0;
  }
  transaction* tmp = (transaction *)realloc(vec->ptr, sizeof(transaction) * size * 2);
  if (!tmp) {
    return -1;
  }
  vec->ptr = tmp;
  vec->size = size;
  vec->capacity = 2 * size;
  return 0;
}

int32_t *vec_tr_get_size(vec_tr *vec) {
  if (!vec) {
    return NULL;
  }
  return &vec->size;
}

int vec_tr_set(vec_tr *vec, int32_t index, transaction value) {
  if (!vec || !vec->ptr || index < 0 || index >= *vec_tr_get_size(vec)) {
    return -1;
  }
  vec->ptr[index] = value;
  return 0;
}

transaction *vec_tr_get(vec_tr *vec, int32_t index) {
  if (!vec || !vec->ptr || index < 0 || index >= *vec_tr_get_size(vec)) {
    return NULL;
  }
  return &vec->ptr[index];
}

int vec_tr_push(vec_tr *vec, transaction value) {
  if (!vec || !vec->ptr) {
    return -1;
  }
  if (vec_tr_set_size(vec, vec->size + 1) || vec_tr_set(vec, vec->size - 1, value)) {
    return -1;
  }
  return 0;
}
