# Add subdirectories
add_subdirectory(attackStrategy)
add_subdirectory(observer)
add_subdirectory(character)

# Add executables
add_executable(simpleRPG main.cpp GameEngine.cpp)

# Include directories
target_include_directories(simpleRPG PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link Libraries
target_link_libraries(simpleRPG PRIVATE
    playerLib
    characterLib
    attackStrategyLib
    observerLib
)