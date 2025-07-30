# Gather source files
file(GLOB PLAYER_SRC
    "*.cpp"
)

# Add library
add_library(playerLib ${PLAYER_SRC})

# Include directories
target_include_directories(playerLib PUBLIC ${PROJECT_SOURCE_DIR}/include)