#pragma once
#include <stdint.h>
#include "vec_tr.h"

typedef struct {
  uint32_t id;
  char *surname;
  char *name;
  char *patronym;
  vec_tr *transactions;
} client;
