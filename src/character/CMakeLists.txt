# Add subdirectories
add_subdirectory(player)

# Gather src files
file(GLOB CHARACTER_SRC
    "*.cpp"
)

# Add library
add_library(characterLib ${CHARACTER_SRC})

# Include directories
target_include_directories(characterLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link libraries
target_link_libraries(characterLib PUBLIC playerLib attackStrategyLib observerLib)
