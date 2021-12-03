add_library(aoc2021_day3_solution STATIC
    solution.h
    solution.cc)

add_executable(aoc2021_day3
    main.cc)

target_link_libraries(aoc2021_day3 aoc2021_day3_solution utils)