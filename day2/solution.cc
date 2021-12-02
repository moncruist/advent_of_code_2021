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

#include <charconv>

namespace aoc2021::day2 {

int solution_part1(const std::list<std::string>& input) {
    int position{0};
    int depth{0};
    for (const auto& line : input) {
        auto pos = line.find(' ');
        const std::string_view direction{line.c_str(), pos};
        const std::string_view value_str{line.c_str() + pos + 1};

        int value{0};
        std::from_chars(value_str.data(), value_str.data() + value_str.size(), value);
        if (direction == "forward") {
            position += value;
        } else if (direction == "down") {
            depth += value;
        } else if (direction == "up") {
            depth -= value;
        }
    }

    return position * depth;
}

int solution_part2(const std::list<std::string>& input) {
    int position{0};
    int depth{0};
    int aim{0};

    for (const auto& line : input) {
        auto pos = line.find(' ');
        const std::string_view direction{line.c_str(), pos};
        const std::string_view value_str{line.c_str() + pos + 1};

        int value{0};
        std::from_chars(value_str.data(), value_str.data() + value_str.size(), value);
        if (direction == "forward") {
            position += value;
            depth += aim * value;
        } else if (direction == "down") {
            aim += value;
        } else if (direction == "up") {
            aim -= value;
        }
    }

    return position * depth;
}

} // namespace aoc2021::day1