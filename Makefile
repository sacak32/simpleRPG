CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR = src
PLAYER_SRC_DIR = $(SRC_DIR)/player
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/simpleRPG

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(PLAYER_SRC_DIR)/*.cpp)

# Map sources to objects (flatten folder structure into obj/player or obj)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.cpp,$(SRCS))) \
       $(patsubst $(PLAYER_SRC_DIR)/%.cpp,$(OBJ_DIR)/player/%.o,$(filter $(PLAYER_SRC_DIR)/%.cpp,$(SRCS)))

all: $(TARGET)

# Link executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile src/*.cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile src/player/*.cpp files
$(OBJ_DIR)/player/%.o: $(PLAYER_SRC_DIR)/%.cpp | $(OBJ_DIR)/player
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary folders
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/player:
	mkdir -p $(OBJ_DIR)/player

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Debug helper to print sources
print-sources:
	@echo $(SRCS)

.PHONY: all clean print-sources