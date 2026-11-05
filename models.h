#pragma once
#include <stdint.h>

typedef struct {
  int8_t day;
  int8_t month;
  int8_t year;
} date;

typedef struct {
  date dt;
  uint32_t time;
  int type;
  double rub;
} transaction;
