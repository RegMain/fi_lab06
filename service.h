#pragma once
#include <stdint.h>
#include "client.h"
#include "vec_cl.h"

client *get_by_id(vec_cl *clients, uint32_t id);

int cmp(client *x, client *y);
 
void sort_clients(vec_cl *clients, int (*cmp)(client *x, client *y));

int bs_cmp(client *x, int32_t val);

client *cl_binary_search(vec_cl *clients, int32_t l, int32_t r, int32_t val, int (*bs_cmp)(client *x, int32_t val));
