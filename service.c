#include <stdlib.h>
#include <stdint.h>
#include "service.h"
#include "vec_tr.h"
#include "vec_cl.h"

client *get_by_id(vec_cl *clients, uint32_t id) {
  if (!clients) {
    return NULL;
  }
  for (uint32_t i = 0; i < *vec_cl_get_size(clients); ++i) {
    client *client_i = vec_cl_get(clients, i);
    if (client_i->id == id) {
      return client_i;
    }
  }
  return NULL;
}

int cmp(client *x, client *y) {
  if (!x || !y) {
    return -1;
  }
  return x->transactions->size > y->transactions->size;
}

void sort_clients(vec_cl *clients, int (*cmp)(client *x, client *y)) {
  if (!clients) {
    return;
  }
  for (int32_t i = 0; i < *vec_cl_get_size(clients); ++i) {
    for (int32_t j = i + 1; j < *vec_cl_get_size(clients); ++j) {
      client *client_i = vec_cl_get(clients, i);
      client *client_j = vec_cl_get(clients, j);
      if (cmp(client_i, client_j)) {
        client tmp = *client_i;
        *client_i = *client_j;
        *client_j = tmp;
      }
    }
  }
}

int bs_cmp(client *x, int32_t val) {
  if (!x) {
    return -1;
  }
  return x->transactions->size < val;
}

client *cl_binary_search(vec_cl *clients, int32_t l, int32_t r, int32_t x, int (*bs_cmp)(client *x, int32_t val)) {
  if (!clients) {
    return NULL;
  }
  int32_t m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    if (bs_cmp(vec_cl_get(clients, m), x)) {
      l = m;
    } else {
      r = m;
    }
  }
  if (r == *vec_cl_get_size(clients)) {
    return vec_cl_get(clients, l);
  }
  return vec_cl_get(clients, r);
}
