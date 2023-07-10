#if _WIN32 || __linux__
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#endif

#if _WIN32
#include <C:/dev/vcpkg/packages/sdl2_x86-windows/include/SDL2/SDL.h>
#endif

#if __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_video.h>
#endif

#include "../inc/coverage_testassert_module.h"
#include "../inc/current_process_modal_registry.h"

class IntermediateCommand {
public:
  void execute_intermediate_command();
};

class AttachAttackToUsage : public IntermediateCommand {
  AttachAttackToUsage *self_attachment;

public:
  AttachAttackToUsage(AttachAttackToUsage *self_attachment) {
    this->self_attachment = self_attachment;
  } // first we init
  // then we de-init
  ~AttachAttackToUsage() {
    std::free(this->self_attachment);
    this->self_attachment = std::nullptr_t();
    delete &self_attachment;
  }

  void execute_intermediate_command() {
    int x; // grasp `int x` from a Command Handle's Context
    handle_user_data(x);
  }
  void handle_user_data(int x);
};

class AttachDelayToUsage : public IntermediateCommand {
  AttachDelayToUsage *self_attachment;

public:
  AttachDelayToUsage(AttachDelayToUsage *self_attachment) {
    this->self_attachment = self_attachment;
  } // first we init
  // then we de-init
  ~AttachDelayToUsage() {
    std::free(this->self_attachment);
    this->self_attachment = std::nullptr_t();
    delete &self_attachment;
  }

  void execute_intermediate_command() {
    int x; // grasp `int x` from a Command Handle's Context
    handle_user_data(x);
  }
  void handle_user_data(int x);
};

class AttachSustainToUsage : public IntermediateCommand {
  AttachSustainToUsage *self_attachment;

public:
  AttachSustainToUsage(AttachSustainToUsage *self_attachment) {
    this->self_attachment = self_attachment;
  } // first we init
  // then we de-init
  ~AttachSustainToUsage() {
    std::free(this->self_attachment);
    this->self_attachment = std::nullptr_t();
    delete &self_attachment;
  }

  void execute_intermediate_command() {
    int x; // grasp `int x` from a Command Handle's Context
    handle_user_data(x);
  }
  void handle_user_data(int x);
};

class AttachReleaseToUsage : public IntermediateCommand {
  AttachReleaseToUsage *self_attachment;

public:
  AttachReleaseToUsage(AttachReleaseToUsage *self_attachment) {
    this->self_attachment = self_attachment;
  } // first we init
  // then we de-init
  ~AttachReleaseToUsage() {
    std::free(this->self_attachment);
    this->self_attachment = std::nullptr_t();
    delete &self_attachment;
  }

  void execute_intermediate_command() {
    int x; // grasp `int x` from a Command Handle's Context
    handle_user_data(x);
  }
  void handle_user_data(int x);
};

class AdditionHandler {
public:
  AttachAttackToUsage *attack_attachment;
  AttachDelayToUsage *delay_attachment;
  AttachSustainToUsage *sustain_attachment;
  AttachReleaseToUsage *release_attachment;

  int handle_modal_of_execution();
}; // Strategy design pattern for Prototype models

int attach_media_layer_window(SDL_Window *window, SDL_Surface *screen_surface) {
  window = std::nullptr_t();
  screen_surface = SDL_GetWindowSurface(window);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize the Window and Screen:\n\t%s",
           SDL_GetError());
  }

  SDL_FillRect(screen_surface, std::nullptr_t(),
               SDL_MapRGBA(screen_surface->format, 0x1B, 0x1B, 0x1B, 0xAA));

  SDL_UpdateWindowSurface(window);

  SDL_Event event;
  bool is_finished = false;
  while (is_finished != true) {
    if (event.type == SDL_QUIT) {
      SDL_DestroyWindow(window);
      SDL_Quit();

      screen_surface = std::nullptr_t();
      std::free(screen_surface);
      delete screen_surface;

      window = std::nullptr_t();
      std::free(window);

      return 1;
    }
  }

  return 0;
}

int deinit_media_layer_window(SDL_Window *window, SDL_Surface *screen_surface) {
  SDL_DestroyWindow(window);

  screen_surface = std::nullptr_t();
  std::free(screen_surface);
  delete screen_surface;

  window = std::nullptr_t();
  std::free(window);

  return 1;
}

class HandleMatrix {
public:
  int x, y;      // coordinates as members
  int *matrix[]; // the actual matrix member
};

class CheckRegisterHexSum {
  enum ArmRegisters arm_register;
  enum CurrentProcessorModes current_processor_mode;

  union { // field that tells us what is being used in a union
    IntermediateCommand intermediate_command; // no ptr-type, str8>stack!!
  };

public:
  int hexsum_calculable() {
    int ret_val =
        CurrentProcessorModes::USER_MODE | this->current_processor_mode;
    // XOR our member binary values
    return ret_val;
  }

  int alias_hex_sum_merge(int usage_index) { // get input from the user table
    // NOTE(Daniel): check if we are in Arm's: USER MODE
    if (this->current_processor_mode != CurrentProcessorModes::USER_MODE) {
      return 1;
    }

    HandleMatrix *matrix; // init in heap-space with anonymous indices

    for (int i = 0;; i++)
      for (int j = 0;; j++) {
        matrix->matrix[i][j] = usage_index;
      }

    std::free(matrix);
    delete matrix;

    return 0;
  }
}; // merge these two strategies with aliasing

int AdditionHandler::handle_modal_of_execution() {
  SDL_LoadBMP("../assets/sprites/Player-Sprite-Export/spritesheet.png");
  bool is_successful = true;

  if (SDL_LoadBMP("../assets/sprites/spritesheet.png") == NULL) {
    printf("Unable to load the image warranted!? %s", SDL_GetError());
    is_successful = false;

    SDL_FreeSurface(SDL_LoadBMP("../assets/sprites/spritesheet.png"));
    SDL_LoadBMP(NULL);
  }

  return is_successful;
}

class OpaqueAimAutomaty {
public:
  HandleMatrix *matrix_handle;
  AdditionHandler signal_transgression_handler;
};

int fast_inverse_square_root(int x) {
  union {
    int d;
    uint32_t i;
  } converter = {.d = x};

  converter.i = 0x5f3759df - (converter.i >> 1);
  converter.d *= 1.5f - (x * .5f * converter.d * converter.d);

  return converter.d;
} // NOTE(Daniel): O(1) Line-of-Best-Fit
  // ---
  // John Carmack’s Unusual Fast Inverse Square Root (Quake III) (no date).
  // Available at: https://stackoverflow.com/a/1349572.
  // ---
  // Understanding Quake’s Fast Inverse Square Root – BetterExplained (no date).
  // Available at:
  // https://betterexplained.com/articles/understanding-quakes-fast-inverse-square-root/.

int infer_functor_inverse_one(int x) {
  int B;
  OpaqueAimAutomaty aim_automa;

  for (auto i = 0; i < 8; i++)
    for (auto j = 0; j < 8; j++) {
      aim_automa.matrix_handle->matrix[i][j] = B;
    }

  fast_inverse_square_root(x);
  B ^= x;

  return B;
} // TODO(Daniel): create ADSR equivalents

void AttachAttackToUsage::handle_user_data(int x) {
  infer_functor_inverse_one(x);
}

void AttachDelayToUsage::handle_user_data(int x) {
  infer_functor_inverse_one(x);
}

void AttachSustainToUsage::handle_user_data(int x) {
  infer_functor_inverse_one(x);
}

void AttachReleaseToUsage::handle_user_data(int x) {
  infer_functor_inverse_one(x);
}
// TODO(Daniel): Strategy-x-Builder pattern

class AdsrUsageStrategyBuilder : AdditionHandler {
  AttachAttackToUsage attack_attachment;
  AttachDelayToUsage delay_attachment;
  AttachSustainToUsage sustain_attachment;
  AttachReleaseToUsage release_attachment;

public:
  AdsrUsageStrategyBuilder();
  ~AdsrUsageStrategyBuilder();

  AdsrUsageStrategyBuilder build_attack(AttachAttackToUsage nu_attack);
  AdsrUsageStrategyBuilder build_delay(AttachDelayToUsage nu_delay);
  AdsrUsageStrategyBuilder build_sustain(AttachSustainToUsage nu_sustain);
  AdsrUsageStrategyBuilder build_release(AttachReleaseToUsage nu_release);

  void execute_intermediate_command();
  void handle_user_data();
};

class AdsrUsageStrategy {
  AttachAttackToUsage attack_attachment;
  AttachDelayToUsage delay_attachment;
  AttachSustainToUsage sustain_attachment;
  AttachReleaseToUsage release_attachment;

public:
  int check_hexadecimal_address_destination() {
    CheckRegisterHexSum *registry_sentinel; // have this in the heap
    registry_sentinel->hexsum_calculable();
    // Initially...supposedly written as:
    // ArmRegisters arm_registry;
    // CheckRegisterHexSum registry_sentinel;
    // registry_sentinel.alias_hex_sum_merge(arm_registry);

    union {
      int a_destination;
      int b_source;
    } c = {.a_destination =
               ArmRegisters::R0}; // don't initialise and override
                                  // subobject's members all at once;
                                  // Bring the subobject's next member
                                  // override into the next method

    registry_sentinel->alias_hex_sum_merge(c.a_destination);
    return c.a_destination;
  }

  int check_hexadecimal_address_source() {
    CheckRegisterHexSum *registry_sentinel; // have this in the heap
    registry_sentinel->hexsum_calculable();
    // Initially...supposedly written as:
    // ArmRegisters arm_registry;
    // CheckRegisterHexSum registry_sentinel;
    // registry_sentinel.alias_hex_sum_merge(arm_registry);

    union {
      int a_destination;
      int b_source;
    } c = {.b_source = ArmRegisters::R0}; // don't initialise and override
                                          // subobject's members all at once;
                                          // Bring the subobject's next member
                                          // override into the next method

    registry_sentinel->alias_hex_sum_merge(c.b_source);
    return c.b_source;
  }
};

class WindowHandler {
public:
  static int get_screen_width();
  static int get_screen_height(); // methods are in static-space
};

class PlayerEntity {};

class PlayerPosition {
public:
  int x;
  int y;
};

class PlayerBundle {
public:
  PlayerEntity entity;
  PlayerPosition position;
};

PlayerEntity *designate_player_entity_scalar(PlayerEntity player_instance) {
  // TODO: move player_entity data into a new ServiceLocator function

  PlayerEntity *new_player = &player_instance;

  return new_player; // return address of stack memory associated with local
                     // variable
}

PlayerBundle *init_player_bundle_instance(PlayerBundle *bundle_instance,
                                          PlayerEntity player_instance) {
  bundle_instance->entity = *designate_player_entity_scalar(
      player_instance); // pointer-to-address because
                        // of address of stack memory
  bundle_instance->position.x = WindowHandler::get_screen_width() / 2.f;
  bundle_instance->position.y = WindowHandler::get_screen_height() / 2.f;

  std::memmove(bundle_instance, bundle_instance,
               sizeof(&bundle_instance)); // the memory in memmove can overlap,
                                          // whereeas memcpy cannot or it will
                                          // cause undefined behavior

  return bundle_instance; // may need memcpy and memmove
}

int process_world_relative_terrain() {
  enum WorldTerrains { CHECKERED_TEXTURE, STRIPED_TEXTURE };
  enum WorldTerrains terrain;

  switch (terrain) {
  case 0:
    terrain = CHECKERED_TEXTURE;
  case 1:
  default:
    terrain = STRIPED_TEXTURE;
  }

  int textures_matrices[8][8]; // match the 32-bit register

  for (int i = 0; i < WindowHandler::get_screen_width(); i++) {
    for (int j = 0; j < WindowHandler::get_screen_height(); j++) {
      textures_matrices[i][j] = STRIPED_TEXTURE; // match the 32-bit register
    }
  }

  return 0;
}

struct FrameData {
  int current_frame;
  int frame_count;
  int frame_speed;
};

int MINIMAL_TESTS_RUN = 0;
char *test_frame_data() {
  struct FrameData frame_data;
  std::string message = "error, current_frame != 0";
  char *converted_message = new char[message.length() + 1];
  // don't use std::strcpy, use std::memcpy instead.
  std::memcpy(converted_message, message.c_str(), sizeof(&converted_message));
  MINIMAL_UNIT_ASSERT(converted_message, frame_data.current_frame == 0);
  return 0;
} // std::string to char*, https://stackoverflow.com/a/7352131.

char *run_tests() {
  MINIMAL_RUN_TEST(test_frame_data);
  return 0;
}

int main() {
  int ret_val = 0;

  enum ArmRegisters arm_registry;
  AdditionHandler *input_handler;

  switch (arm_registry) {
  default:
    enum ArmRegisters arm_usage = arm_registry;
    // now withhold the LHS value of a register for an IR module pass
  }

  SDL_Window *window;
  SDL_Surface *screen_surface, *image_surface;

  struct FrameData frame_data; // have this value in the "stack-space"

  int current_frame = 0;
  int frame_count = 0;
  int frame_speed = 8;

  frame_data.current_frame = current_frame;
  frame_data.frame_count = frame_count;
  frame_data.frame_speed = frame_speed;

  const int max_frame_speed = 16;
  const int min_frame_speed = 1;

  struct PlayerEntity *player_instance;

  struct PlayerBundle player_bundle;
  struct PlayerBundle bundle_instance;

  PlayerBundle *player =
      init_player_bundle_instance(&bundle_instance, *player_instance);

  attach_media_layer_window(window, screen_surface);

  AdditionHandler *addition_handle;
  addition_handle->handle_modal_of_execution();

  SDL_BlitSurface(image_surface, NULL, screen_surface, NULL);
  // Display contents in a scrolling region

  while (!window) {
    frame_count++;
    // TODO(Daniel): change all this into a Strategy design pattern
    if (frame_count >= (60 / frame_speed)) {
      frame_count = 0;
      current_frame++;
      if (current_frame > 4)
        current_frame = 0;
    }

#ifndef LocalDirections
    // Pre-processor boolean statement for enum declaration protection
    enum LocalDirections { UP, DOWN, LEFT, RIGHT };
#endif
    enum LocalDirections directions;
    SDL_Keycode keycode;

    for (int x = 0; x < 8; x++) {
      player->position.x = x;
      for (int y = 0; y < 8; y++) {
        player->position.y = y;

        if (frame_speed > max_frame_speed)
          frame_speed = max_frame_speed;
        else if (frame_speed < min_frame_speed)
          frame_speed = min_frame_speed;
      }
    }
  }

  for (int i = 0; i < sizeof(bundle_instance); ++i) {
    free(player); // free called on unallocated object
    // free and annul all player resources
  }

  deinit_media_layer_window(window, screen_surface);
  deinit_media_layer_window(NULL, image_surface);

  addition_handle = std::nullptr_t();
  std::free(addition_handle);
  delete addition_handle;

  SDL_Quit();

  return ret_val;
}
