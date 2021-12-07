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

#include <algorithm>
#include <array>
#include <ranges>
#include <sstream>
#include <tuple>
#include <vector>

namespace aoc2021::day6 {

void parse_input(const std::list<std::string>& input, std::list<int>& fishes) {
    std::stringstream coords_stream(input.front());
    std::string temp;
    while (std::getline(coords_stream, temp, ',')) {
        int timer = std::stoi(temp);
        fishes.push_back(timer);
    }
}

uint64_t solution(const std::list<std::string>& input, int days) {
    static constexpr size_t kLifetimeSize{9};
    std::list<int> fishes;
    parse_input(input, fishes);

    std::array<uint64_t, kLifetimeSize> lifetimes;
    lifetimes.fill(0);
    for (auto timer : fishes) {
        lifetimes[timer]++;
    }

    for (int i = 0; i < days; i++) {
        size_t idx = i % kLifetimeSize;
        uint64_t current_fishes = lifetimes[idx];

        size_t next = (i + 7) % kLifetimeSize;
        lifetimes[next] += current_fishes;
    }

    uint64_t result = 0;

    for (const auto& fishes : lifetimes) {
        result += static_cast<size_t>(fishes);
    }

    return result;
}

} // namespace aoc2021::day5