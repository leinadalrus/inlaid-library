#ifndef USER_DATA_SERVICE_H
#define USER_DATA_SERVICE_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct UserData
{
  int source;
  int destination;
  int user_data;
  size_t data_size;
} UserData;

typedef struct NullService
{
  int source{0};
  int destination{0};
  int user_data{0};
  size_t data_size{0};
} NullService;

typedef struct DataImplementation
{
  UserData data;

  int compare_scoped_lambda_data(int scoped_lambda_id, int current_data)
  {
    scoped_lambda_id = (this->data.user_data == current_data);
    return scoped_lambda_id;
  }

} DataImplementation;

#endif // USER_DATA_SERVICE_H