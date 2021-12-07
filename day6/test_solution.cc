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

const std::list<std::string> test_input{"3,4,3,1,2"};

TEST(Day6, TestSolution1) {
    EXPECT_EQ(aoc2021::day6::solution(test_input, 1), 5);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 2), 6);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 3), 7);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 4), 9);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 5), 10);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 6), 10);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 7), 10);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 8), 10);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 9), 11);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 10), 12);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 11), 15);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 12), 17);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 13), 19);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 14), 20);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 15), 20);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 16), 21);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 17), 22);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 18), 26);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 80), 5934);
    EXPECT_EQ(aoc2021::day6::solution(test_input, 256), 26984457539);
}