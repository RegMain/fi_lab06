#include <stdio.h>
#include <math.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include "vec_cl.h"
#include "vec_tr.h"
#include "client.h"
#include "models.h"
#include "service.h"

int main(void) {
  FILE *file;
  vec_cl *clients;
  file = fopen("test.txt", "r");
  if (!file) {
    return 1;
  }
  clients = vec_cl_init(0);
  client client_i;
  int32_t average = 0;
  while (fscanf(file, "%d", &client_i.id) == 1) {
    int32_t tr_amount;
    fscanf(file, "%63s\t%63s\t%63s", client_i.surname, client_i.name, client_i.patronym);
    fscanf(file, "%d", &tr_amount);
    client_i.transactions = vec_tr_init(tr_amount);
    for(int32_t j = 0; j < tr_amount; ++j) {
      transaction tr_j;
      char buff[20];
      fscanf(file, "%d.%d.%d", &tr_j.dt.day, &tr_j.dt.month, &tr_j.dt.year);
      fscanf(file, "%d:%d:%d", &tr_j.t.hour, &tr_j.t.minute, &tr_j.t.second);
      fscanf(file, "%19s\t", buff);
      if (strcmp(buff, "Income") == 0) {
        tr_j.type = 1;
      } else {
        tr_j.type = 0;
      }
      fscanf(file, "%lf", &tr_j.rub);
      vec_tr_set(client_i.transactions, j, tr_j);
    }
    vec_cl_push(clients, client_i);
    average += tr_amount;
  }
  average = round(average * 1.0 / (*vec_cl_get_size(clients) * 1.0));
  printf("Average amount of transactions: %d\n", average);
  sort_clients(clients, cmp);
  client *lower = cl_binary_search(clients, 0, *vec_cl_get_size(clients), average, bs_cmp)->l;
  client *higher = cl_binary_search(clients, 0, *vec_cl_get_size(clients), average + 1, bs_cmp)->r;
  printf("Lower: %s %s %s ID %d (%d)\n", lower->surname, lower->name, lower->patronym, lower->id, lower->transactions->size);
  printf("Higher: %s %s %s ID %d (%d)\n", higher->surname, higher->name, higher->patronym, higher->id, higher->transactions->size);
  vec_cl_destroy(clients);
  fclose(file);
  return 0;
}
