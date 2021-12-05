// advent_of_code_2021
// Copyright (C) 2021 Konstantin Zhukov
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <gtest/gtest.h>

#include "solution.h"

const std::list<std::string> test_input{"0,9 -> 5,9",
                                        "8,0 -> 0,8",
                                        "9,4 -> 3,4",
                                        "2,2 -> 2,1",
                                        "7,0 -> 7,4",
                                        "6,4 -> 2,0",
                                        "0,9 -> 2,9",
                                        "3,4 -> 1,4",
                                        "0,0 -> 8,8",
                                        "5,5 -> 8,2"};

TEST(Day5, TestSolution1) {
    EXPECT_EQ(aoc2021::day5::solution_part1(test_input), 5);
}

TEST(Day5, TestSolution2) {
    EXPECT_EQ(aoc2021::day5::solution_part2(test_input), 12);
}