#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include "vec_cl.h"
#include "vec_tr.h"
#include "client.h"
#include "models.h"
#include "service.h"

int main(void) {
  FILE *file;
  uint32_t amount;
  vec_cl *clients;
  file = fopen("test.txt", "r");
  fscanf(file, "%d", &amount);
  clients = vec_cl_init(amount);
  int32_t average = 0;
  for (int32_t i = 0; i < amount; ++i) {
    client client_i;
    int32_t tr_amount;
    fscanf(file, "%d", &client_i.id);
    fscanf(file, "%63s\t%63s\t%63s", client_i.surname, client_i.name, client_i.patronym);
    fscanf(file, "%d", &tr_amount);
    client_i.transactions = vec_tr_init(tr_amount);
    for(int32_t j = 0; j < tr_amount; ++j) {
      transaction tr_i;
      char buff[20];
      fscanf(file, "%d.%d.%d", &tr_i.dt.day, &tr_i.dt.month, &tr_i.dt.year);
      fscanf(file, "%d:%d:%d", &tr_i.t.hour, &tr_i.t.minute, &tr_i.t.second);
      fscanf(file, "%19s\t", buff);
      if (strcmp(buff, "Income") == 0) {
        tr_i.type = 1;
      } else {
        tr_i.type = 0;
      }
      fscanf(file, "%lf", &tr_i.rub);
      vec_tr_set(client_i.transactions, j, tr_i);
    }
    vec_cl_set(clients, i, client_i);
    average += tr_amount;
  }
  average = round(average * 1.0 / (amount * 1.0));
  printf("Average amount of transactions: %d\n", average);
  sort_clients(clients, cmp);
  client *lower;
  client *higher;
  lower = cl_binary_search(clients, 0, amount, average - 1, bs_cmp);
  higher = cl_binary_search(clients, 0, amount, average + 1, bs_cmp);
  printf("Lower: %s %s %s ID %d (%d)\n", lower->surname, lower->name, lower->patronym, lower->id, lower->transactions->size);
  printf("Higher: %s %s %s ID %d (%d)\n", higher->surname, higher->name, higher->patronym, higher->id, higher->transactions->size);
  vec_cl_destroy(clients);
  fclose(file);
  return 0;
}
