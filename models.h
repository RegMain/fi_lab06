#pragma once
#include <stdint.h>
#include <sys/cdefs.h>

typedef struct {
  int8_t day;
  int8_t month;
  int16_t year;
} date;

typedef struct {
  int8_t hour;
  int8_t minute;
  int8_t second;
} time;

typedef struct {
  date dt;
  time t;
  int type;
  double rub;
} transaction;
