add_library(aoc2021_day4_solution STATIC
    solution.h
    solution.cc)

add_executable(aoc2021_day4
    main.cc)

target_link_libraries(aoc2021_day4 aoc2021_day4_solution utils)

add_executable(aoc2021_day4_test test_solution.cc)
target_link_libraries(aoc2021_day4_test aoc2021_day4_solution GTest::gtest GTest::gtest_main)

add_test(NAME aoc2021_day4_test COMMAND aoc2021_day4_test)