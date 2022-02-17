cmake_minimum_required(VERSION 3.16)
project(cpp_hw5)


set(CMAKE_CXX_FLAGS "-O2")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")
include_directories(.)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


add_executable(DistributedCounter1
        DistributedCounter1.h
        DistributedCounterTest1.cpp
        )

add_executable(DistributedCounter2
        DistributedCounter2.h
        DistributedCounterTest2.cpp
        )
add_executable(DistributedCounter3
        DistributedCounter3.h
        DistributedCounterTest3.cpp
        )


add_executable(test_my_stack
        my_stack.h
        test_my_stack.cpp
        )

add_executable(5_5
        5_5.cpp
        )
target_link_libraries(DistributedCounter1 PRIVATE Threads::Threads)
target_link_libraries(DistributedCounter2 PRIVATE Threads::Threads)
target_link_libraries(DistributedCounter3 PRIVATE Threads::Threads)
target_link_libraries(test_my_stack PRIVATE Threads::Threads)
