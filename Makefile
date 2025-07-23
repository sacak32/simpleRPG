CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR = src
PLAYER_SRC_DIR = $(SRC_DIR)/player
ATTACK_STRATEGY_SRC_DIR = $(SRC_DIR)/attackStrategy
OBSERVER_SRC_DIR = $(SRC_DIR)/observer

OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/simpleRPG

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(PLAYER_SRC_DIR)/*.cpp) $(wildcard $(ATTACK_STRATEGY_SRC_DIR)/*.cpp) \
	   $(wildcard $(OBSERVER_SRC_DIR)/*.cpp) \

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

# Compile src/attackStrategy/*.cpp files
$(OBJ_DIR)/attackStrategy/%.o: $(ATTACK_STRATEGY_SRC_DIR)/%.cpp | $(OBJ_DIR)/attackStrategy
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile src/observer/*.cpp files
$(OBJ_DIR)/observer/%.o: $(OBSERVER_SRC_DIR)/%.cpp | $(OBJ_DIR)/observer
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary folders
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/player:
	mkdir -p $(OBJ_DIR)/player

$(OBJ_DIR)/attackStrategy:
	mkdir -p $(OBJ_DIR)/attackStrategy

$(OBJ_DIR)/observer:
	mkdir -p $(OBJ_DIR)/observer

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Debug helper to print sources
print-sources:
	@echo $(SRCS)

.PHONY: all clean print-sources