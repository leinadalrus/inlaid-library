SHELL = /bin/bash

CXX_COMPILER = gcc

TARGET_EXEC := main

BUILD_DIR := ./builddir
INCLUDE_DIR := ./inc

EXT_FILES := $(shell find $(INCLUDE_DIR) -name '*.cpp' -or -name '*.c' -or  -name '*.s')

STATIC_OBJS := $(EXT_FILES:%=$(BUILD_DIR)/%.o)

PROJ_DEPS := $(STATIC_OBJS:.o=.d)

SOURCE_DIR := $(shell find $(INCLUDE_DIR) -type d)
SOURCE_FLAGS := $(addprefix -I,$(SOURCE_DIR))

CXX_FLAGS := $(SOURCE_FLAGS) -g -Wall -MMD -MP # generate makefiles with .d output

WALL_FLAGS := -g -Wall

%.o: %.c $(INCLUDE_DIR)/$(wildcard *.h)

.PRECIOUS: $(TARGET_EXEC) $(STATIC_OBJS)

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(STATIC_OBJS)
	$(CXX_COMPILER) $(STATIC_OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX_COMPILER) $(CXX_FLAGS) -c $< -o $@

# Build step for C source
$(TARGET_EXEC): $(STATIC_OBJS)
	$(CXX_COMPILER) $(WALL_FLAGS) -c $< -o $@

.PHONY: clean
	clean:
		rm -r $(BUILD_DIR)

-include $(PROJ_DEPS)

systemd_ioofd: src/main.c $(EXT_FILES)
	gcc src/main.c -o out/systemd_ioofd.o $(WALL_FLAGS)

dynamic_library: systemd_ioofd.o
	gcc systemd_ioofd.o -o systemd_ioofd

dc_toolchain_conan: 
	cd build
	cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
	cmake --build .