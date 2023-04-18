#ifndef DISTRIBUTED_USER_DATA_H
#define DISTRIBUTED_USER_DATA_H

typedef enum EHashes {
  Node = 0,
} EHashes;

typedef struct UnitEntity {
} UnitEntity;

typedef struct Username {
  const char *username[sizeof(char *)];
} Username;

typedef struct Vector2Position {
  int x;
  int y;
} Vector2Position;

typedef struct DistyData {
  char *source;
  char *destination;
  char *data_size;
  char *user_data;
} DistyData;

typedef struct TrackingTable {
  EHashes e_hash;
  UnitEntity entity;
  Username name;
  Vector2Position vector2_position;
  DistyData disty_data;
} TrackingTable;

#endif // DISTRIBUTED_USER_DATA_H