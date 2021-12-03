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

#ifndef ADVENT_OF_CODE_2021_DAY1_SOLUTION_H
#define ADVENT_OF_CODE_2021_DAY1_SOLUTION_H

#include <cstddef>
#include <list>
#include <string>

namespace aoc2021::day3 {

uint32_t solution_part1(const std::list<std::string>& input);
uint32_t solution_part2(const std::list<std::string>& input, uint16_t bit_length);

} // namespace aoc2021::day1

#endif // ADVENT_OF_CODE_2021_DAY1_SOLUTION_H
