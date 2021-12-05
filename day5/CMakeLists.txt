add_library(aoc2021_day5_solution STATIC
    solution.h
    solution.cc)

add_executable(aoc2021_day5
    main.cc)

target_link_libraries(aoc2021_day5 aoc2021_day5_solution utils)

add_executable(aoc2021_day5_test test_solution.cc)
target_link_libraries(aoc2021_day5_test aoc2021_day5_solution GTest::gtest GTest::gtest_main)

add_test(NAME aoc2021_day5_test COMMAND aoc2021_day5_test)