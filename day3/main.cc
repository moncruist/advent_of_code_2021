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
#include "solution.h"

#include <iostream>

#include "utils/args_parser.h"
#include "utils/input_parser.h"

using aoc2021::utils::ArgsParser;
using aoc2021::utils::SolutionPart;

int main(int argc, const char* argv[]) {
    ArgsParser parser;

    if (!parser.parse(argc, argv)) {
        return 1;
    }

    const auto input = aoc2021::utils::parse_file(parser.get_input_filename());

    uint32_t result{0U};
    switch (parser.get_part()) {
        case SolutionPart::PART_1:
            result = aoc2021::day3::solution_part1(input);
            break;

        case SolutionPart::PART_2:
            result = aoc2021::day3::solution_part2(input, 12);
            break;

        default:
            return 1;
    }

    std::cout << "result: " << result << std::endl;
}