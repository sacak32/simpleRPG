# Gather src files
file(GLOB ATTACK_STRATEGY_SRC
    "*.cpp"
)

# Add library
add_library(attackStrategyLib ${ATTACK_STRATEGY_SRC})

# Include directories
target_include_directories(attackStrategyLib PUBLIC ${PROJECT_SOURCE_DIR}/include)