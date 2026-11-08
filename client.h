#pragma once
#include <stdint.h>
#include "vec_tr.h"

typedef struct {
  uint32_t id;
  char surname[64];
  char name[64];
  char patronym[64];
  vec_tr *transactions;
} client;
