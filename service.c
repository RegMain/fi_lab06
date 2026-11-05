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
  return x->transactions->size < y->transactions->size;
}

void sort_clients(vec_cl *clients, int (*cmp)(client *x, client *y)) {
  if (!clients) {
    return;
  }
  for (int32_t i = 0; i < *vec_cl_get_size(clients); ++i) {
    for (int32_t j = i + 1; j < *vec_cl_get_size(clients); ++j) {
      client *client_i = vec_cl_get(clients, i);
      client *client_j = vec_cl_get(clients, i);
      if (cmp(client_i, client_j)) {
        client tmp = *client_i;
        *client_j = *client_i;
        *client_i = tmp;
      }
    }
  }
}
