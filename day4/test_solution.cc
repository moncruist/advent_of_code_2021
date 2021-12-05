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

const std::list<std::string> test_input{"7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
                                        "",
                                        "22 13 17 11  0",
                                        "8  2 23  4 24",
                                        "21  9 14 16  7",
                                        "6 10  3 18  5",
                                        "1 12 20 15 19",
                                        "",
                                        "3 15  0  2 22",
                                        "9 18 13 17  5",
                                        "19  8  7 25 23",
                                        "20 11 10 24  4",
                                        "14 21 16 12  6",
                                        "",
                                        "14 21 17 24  4",
                                        "10 16 15  9 19",
                                        "18  8 23 26 20",
                                        "22 11 13  6  5",
                                        "2  0 12  3  7",
                                        ""};

TEST(Day4, TestSolution1) {
    EXPECT_EQ(aoc2021::day4::solution_part1(test_input), 4512);
}

TEST(Day4, TestSolution2) {
    EXPECT_EQ(aoc2021::day4::solution_part2(test_input), 1924);
}