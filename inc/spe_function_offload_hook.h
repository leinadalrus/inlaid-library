#ifndef SPE_FUNCTION_OFFLOAD_HOOK_H
#define SPE_FUNCTION_OFFLOAD_HOOK_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Amd64Entry {};

typedef struct Thread {
} Thread;

Thread *create_thread(Thread *anyopaque);
void free_thread(Thread *thread);
void block_thread(Thread *thread);

typedef struct Mutex {
} Mutex;

Mutex *create_mutex();
void free_mutex(Mutex *mutex);
void lock_mutex(Mutex *mutex);
void unlock_mutex(Mutex *mutex);
int try_lock_mutex(Mutex *mutex);

void sleep_linting(uint64_t seconds);

typedef struct MicroProgramCounter {
} MicroProgramCounter;

int initialize_microprogram_counter();
void deinitialize_microprogram_counter();
void begin_microprogram_counter();
void end_microprogram_counter();

int send_microprogram_counters_packet(uint8_t data, int length,
                                      uint8_t timestamp);
int receive_microprogram_counters_packet(uint8_t data, int length,
                                         uint8_t timestamp);
int send_microprogram_counters_command(uint8_t data, int length,
                                       uint8_t timestamp);
int send_microprogram_counters_reply(uint8_t data, uint8_t timestamp,
                                     uint16_t bitmask);
int send_microprogram_counters_acknowledgement(uint8_t data, int length,
                                               uint8_t timestamp);
int send_microprogram_counters_host_packet(uint8_t data, int length,
                                           uint8_t timestamp);
int receive_microprogram_counters_replies(uint8_t data, uint8_t timestamp,
                                          uint16_t bitmask);

typedef struct ArenaData {
  void *destination, *source, *table_data;
  uint16_t data_size;
} ArenaData;

typedef struct ArenaState {
  ArenaData state;
} ArenaState;

typedef struct LintArenaBundle {
  Thread thread;
  Mutex mutex;
  MicroProgramCounter microprogram_counter;
} LintArenaBundle;

// TODO Singleton-Strategy Pattern for Contextual-Root-Objects'(s data)
typedef struct SingletonStrategy {
  // NOTE members not given a "private:" label before a typedef struct body
  // init'd is already privated immutable
  ArenaState _private_arena_state;

  ArenaState __protected_arena_state__ =
      this->_private_arena_state; // "protected" also means shared between
                                  // inherited typedef structes
} SingletonStrategy;

#endif // SPE_FUNCTION_OFFLOAD_HOOK_H
