#ifndef USER_DATA_SERVICE_H
#define USER_DATA_SERVICE_H

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct UserData
{
  int source;
  int destination;
  unsigned long long data_size;
  int user_data;
} UserData;

int compare_scoped_lambda_data(UserData *self, int scoped_lambda_id, int current_data)
{
  scoped_lambda_id = (self->user_data == current_data);
  return scoped_lambda_id;
}

#endif // USER_DATA_SERVICE_H