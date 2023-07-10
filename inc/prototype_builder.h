#include "game_actor_entity.h"

typedef struct EntityPrototype {
  PlayerBundle *player; // the bundle struct is a flyweight, not an object
} EntityPrototype;

EntityPrototype init_prototype_via_execution(EntityPrototype prototype,
                                             InputCommand command);

EntityPrototype *clone_prototype_on_build();

typedef struct PrototypeBuilder {
} PrototypeBuilder;

typedef struct PrototypeBuilderVirtualTable {
  PrototypeBuilder (*create_builder)(PrototypeBuilder *builder);
  PrototypeBuilder (*build_hook_strategy)(PrototypeBuilder *builder,
                                          EntityPrototype *prototype);
  void (*copy_ref_cell)(PrototypeBuilder *builder);
  void (*clone_ref_cell)(PrototypeBuilder *builder, EntityPrototype *prototype);
  void (*drop_ref_cell)(PrototypeBuilder *builder, EntityPrototype *prototype);
  void (*destroy_hooked_strategy)(PrototypeBuilder *builder,
                                  EntityPrototype *prototype);
} PrototypeBuilderVirtualTable; // contains function pointers

PrototypeBuilder create_handler_for_prototype(PrototypeBuilder builder,
                                              InputHandler handler);

void execute_actor_prototype(InputCommand *command, PlayerEntity *player);

typedef union BuiltPrototypeComparator {
  EntityPrototype prototype;
  PrototypeBuilder builder;
} BuiltPrototypeComparator;

// TODO(Daniel):
// Since the PlayerBundle is a Flyweight pattern,
// We can just instantiate the extrinsic details of the object model.
// This way we can have members of flyweight model which are context-free,
// be cullable through an Observer pattern.
// The Observer pattern will need to have the states of the 32-bit IR of the ARM
// architecture though.
// Although referencing the bundled object model by pointer implies an indirect
// lookup. Albeit, generally Flyweight's optimization is close to little-to-no
// cost over an 'enum'. So a Flyweight is a good alternative over an 'enum' -
// depending on whether your other components are good enough with and for it.
// We can still use 'enum' especially with the Instruction Register and IR, but-
// -we'll need to create a Bridge which utilises the comparator abilities of a
// 'union' type.
