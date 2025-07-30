file(GLOB TEST_SRC "*.cpp")

add_executable(tests ${TEST_SRC})

target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(tests PRIVATE
    playerLib
    characterLib
    attackStrategyLib
    observerLib
    GTest::GTest
    GTest::Main
    pthread
)

include(GoogleTest)
gtest_discover_tests(tests)