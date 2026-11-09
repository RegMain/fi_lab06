#pragma once
#include <stdint.h>
#include "client.h"
#include "vec_cl.h"

typedef struct {
  client *l;
  client *r;
} cl_bs_res;

client *get_by_id(vec_cl *clients, uint32_t id);

int cmp(client *x, client *y);
 
void sort_clients(vec_cl *clients, int (*cmp)(client *x, client *y));

int bs_cmp(client *x, int32_t val);

cl_bs_res *cl_binary_search(vec_cl *clients, int32_t l, int32_t r, int32_t val, int (*bs_cmp)(client *x, int32_t val));
