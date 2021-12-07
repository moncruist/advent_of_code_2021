add_library(aoc2021_day6_solution STATIC
    solution.h
    solution.cc)

add_executable(aoc2021_day6
    main.cc)

target_link_libraries(aoc2021_day6 aoc2021_day6_solution utils)

add_executable(aoc2021_day6_test test_solution.cc)
target_link_libraries(aoc2021_day6_test aoc2021_day6_solution GTest::gtest GTest::gtest_main)

add_test(NAME aoc2021_day6_test COMMAND aoc2021_day6_test)