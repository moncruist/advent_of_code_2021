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
#include <array>
#include <vector>

namespace aoc2021::day3 {

uint32_t solution_part1(const std::list<std::string>& input) {
    std::array<uint32_t, 12> bit_counts;
    bit_counts.fill(0);

    size_t size{0U};
    for (const auto& line : input) {
        uint16_t value = std::stoul(line, nullptr, 2);
        for (uint16_t i = 0; i < 12; i++) {
            uint16_t mask = 1 << i;
            if ((value & mask) != 0) {
                bit_counts[i]++;
            }
        }

        size++;
    }

    uint32_t epsilon{0U};
    uint32_t gamma{0U};
    for (uint16_t i = 0; i < 12; i++) {
        if (bit_counts[i] > (size/2)) {
            gamma |= 1 << i;
        } else {
            epsilon |= 1 << i;
        }
    }

    return epsilon * gamma;
}

void filter_list(std::list<uint16_t>& list, uint16_t pos, bool should_set)
{
    if (list.size() <= 1) {
        return;
    }

    auto it = list.begin();
    while (it != list.end()) {
        uint16_t mask = 1U << pos;
        uint16_t value = *it;
        bool is_set = (value & mask) != 0;

        auto prev = it++;
        if (is_set != should_set) {
            list.erase(prev);
        }

        if (list.size() <= 1) {
            break;
        }
    }
}

size_t bit_count(const std::list<uint16_t>& list, uint16_t pos) {
    size_t count{0};
    uint16_t mask = 1 << pos;
    for (const auto value : list) {
        if ((value & mask) != 0) {
            count++;
        }
    }
    return count;
}

uint32_t solution_part2(const std::list<std::string>& input, uint16_t bit_length) {
    std::vector<uint32_t> bit_counts;
    bit_counts.resize(bit_length);

    size_t size{input.size()};
    std::list<uint16_t> oxygen_gen_candidates;
    std::list<uint16_t> co2_scrubber_candidates;
    for (const auto& line : input) {
        uint16_t value = std::stoul(line, nullptr, 2);

        oxygen_gen_candidates.push_back(value);
        co2_scrubber_candidates.push_back(value);
    }

    for (uint16_t i = bit_length; i > 0; i--) {
        size_t idx = i - 1;
        size_t oxygen_bit_count = bit_count(oxygen_gen_candidates, idx);
        size_t co2_scrubber_bit_count = bit_count(co2_scrubber_candidates, idx);


        if ((oxygen_bit_count > (oxygen_gen_candidates.size() / 2)) ||
            (((oxygen_gen_candidates.size() % 2) == 0) && (oxygen_bit_count == oxygen_gen_candidates.size() / 2))) {
            filter_list(oxygen_gen_candidates, idx, true);
        } else {
            filter_list(oxygen_gen_candidates, idx, false);
        }

        if ((co2_scrubber_bit_count > (co2_scrubber_candidates.size() / 2)) ||
            (((co2_scrubber_candidates.size() % 2) == 0) &&
             (co2_scrubber_bit_count == co2_scrubber_candidates.size() / 2))) {
            filter_list(co2_scrubber_candidates, idx, false);
        } else {
            filter_list(co2_scrubber_candidates, idx, true);
        }
    }

    uint32_t result = oxygen_gen_candidates.front() * co2_scrubber_candidates.front();
    return result;
}

} // namespace aoc2021::day1