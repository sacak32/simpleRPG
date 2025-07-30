# Gather src files
file(GLOB OBSERVER_SRC
    "*.cpp"
)

# Add library
add_library(observerLib ${OBSERVER_SRC})

# Include directories
target_include_directories(observerLib PUBLIC ${PROJECT_SOURCE_DIR}/include)