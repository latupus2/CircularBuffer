cmake_minimum_required(VERSION 3.10)
project(Task1CircularBuffer VERSION 1.0)


include_directories(${CMAKE_SOURCE_DIR}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.7/build/native/include)
link_directories(${CMAKE_SOURCE_DIR}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.7/lib/native/v140/windesktop/msvcstl/static/rt-dyn/x64/Release)

set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/Task1CircularBuffer/CircularBufferTests.cpp
    ${CMAKE_SOURCE_DIR}/Task1CircularBuffer/CircularBuffer.cpp
)
enable_testing()

# executable
add_executable(CircularBufferTest ${SOURCE_FILES})

target_link_libraries(CircularBufferTest gtest gtest_main)
add_test(NAME CircularBufferTest COMMAND CircularBufferTest)
