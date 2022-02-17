# cpp_hw5

## 5_1

Note: To explicitly use C++20 features, I've specified path to compiler in CMakeLists.txt using

```set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")```

which will probably not work in your computer.

Also, I use ```-O2``` optimization flag.

| Program  | Time(ms) |
|----------|----------|
| counter1 | 57537    |
| counter2 | 8690     |
| counter3 | 7562     |

Counter1 is the slowest; counter2 and counter3 seems to be similar.

The reason for counter1's slowness is that, only using one mutex essentially makes the program serial.

Counter2 and counter3 are similarly fast, which is not the same with result showed in lecture. Perhaps this is because "
all cores use same cache lines" at my laptop.

## 5_2

Using jthread has nothing to do with speed, as it takes 59104ms to complete counting.

## 5_3

see my_stack.h and test_my_stack.cpp. Added empty() and initializer list constructor.

## 5_4 and 5_5
see 5_5.cpp. I am not sure if I get the 5.5 question correctly. Basically I put a flag in the class to tell whether the
counter working, and in constructor we can specify the flag.