include_directories(${PROJECT_SOURCE_DIR}/src)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(
        insertTest.bin
        insertTest.cc
)

target_link_libraries(
        insertTest.bin
        heapfile
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(insertTest.bin)