#pragma once
#include <stdint.h>
#include "client.h"
#include "vec_cl.h"

client *get_by_id(vec_cl *clients, uint32_t id);

int cmp(client *x, client *y);
 
void sort_clients(vec_cl *clients, int (*cmp)(client *x, client *y));
