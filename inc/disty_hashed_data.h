#ifndef DISTY_HASHED_DATA_H
#define DISTY_HASHED_DATA_H

enum EHashes
{
  Node = 0,
};

typedef struct UnitEntity
{
} UnitEntity;

typedef struct Username
{
  const char *username[sizeof(15)];
} Username;

typedef struct Vector2Position
{
  int x;
  int y;
} Vector2Position;

typedef struct DistyData
{
  char *source;
  char *destination;
  char *data_size;
  char *user_data;
} DistyData;

typedef struct TrackingTable
{
  EHashes e_hash;
  UnitEntity entity;
  Username name;
  Vector2Position vector2_position;
  DistyData disty_data;
} TrackingTable;

#endif // DISTY_HASHED_DATA_H
