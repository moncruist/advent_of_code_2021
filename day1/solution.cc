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

namespace aoc2021::day1 {

size_t solution_part1(const std::list<int>& input) {
    size_t result{0};
    if (input.empty()) {
        return result;
    }

    int prev = input.front();
    auto pos = input.begin();
    pos++;

    while (pos != input.end()) {
        int current = *pos;
        if (current > prev) {
            result++;
        }
        prev = current;
        pos++;
    }

    return result;
}

size_t solution_part2(const std::list<int>& input) {
    size_t result{0};
    if (input.empty()) {
        return result;
    }
    auto window_start = input.cbegin();
    auto window_end = input.cbegin();
    int window_sum{0};

    constexpr size_t WINDOW_SIZE{3};
    for (size_t i = 0; i < WINDOW_SIZE; i++) {
        if (window_end == input.cend()) {
            return result;
        }

        window_sum += *window_end;
        window_end++;
    }

    while (window_end != input.cend()) {
        int next_window = window_sum;
        next_window += *window_end;
        next_window -= *window_start;

        if (next_window > window_sum) {
            result++;
        }

        window_sum = next_window;
        window_start++;
        window_end++;
    }

    return result;
}

} // namespace aoc2021::day1