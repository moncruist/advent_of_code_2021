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

namespace aoc2021::day5 {

struct Line {
    int x1;
    int y1;
    int x2;
    int y2;

    bool is_straight() const { return (x1 == x2) || (y1 == y2); }
};

class Lanternfish {
public:
    Lanternfish(size_t width, size_t height) : width_(width), height_(height) {
        matrix_.resize(width * height);
        std::fill(matrix_.begin(), matrix_.end(), 0);
    }

    void draw_line(const Line& line) {
        int delta_x = line.x2 - line.x1;
        int delta_y = line.y2 - line.y1;

        if (line.is_straight()) {
            if (delta_x != 0) {
                size_t start = std::min(line.x1, line.x2);
                size_t end = std::max(line.x1, line.x2);
                for (size_t x = start; x <= end; x++) {
                    matrix_[get_idx(x, line.y1)]++;
                }
            } else {
                size_t start = std::min(line.y1, line.y2);
                size_t end = std::max(line.y1, line.y2);
                for (size_t y = start; y <= end; y++) {
                    matrix_[get_idx(line.x1, y)]++;
                }
            }
        } else {
            size_t x = line.x1;
            size_t y = line.y1;

            while ((x != line.x2) && (y != line.y2)) {
                matrix_[get_idx(x, y)]++;
                x = delta_x > 0 ? x + 1 : x - 1;
                y = delta_y > 0 ? y + 1 : y - 1;
            }
            matrix_[get_idx(line.x2, line.y2)]++;
        }
    }

    size_t count_ge(int value) {
        return std::count_if(matrix_.begin(), matrix_.end(), [value](int v) { return v >= value; });
    }

private:
    size_t get_idx(size_t x, size_t y) { return (y * width_) + x; }

    size_t width_;
    size_t height_;
    std::vector<int> matrix_;
};

std::tuple<int, int> parse_coords(const std::string& raw) {
    std::stringstream coords_stream(raw);

    std::string temp;
    std::getline(coords_stream, temp, ',');
    int head = std::stoi(temp);
    std::getline(coords_stream, temp, ',');
    int tail = std::stoi(temp);

    return {head, tail};
}

void parse_input(const std::list<std::string>& input, std::list<Line>& lines) {
    for (const auto& line_raw : input) {
        auto delim = line_raw.find(" -> ");
        auto head = line_raw.substr(0, delim);
        auto tail = line_raw.substr(delim + 4);

        auto [x1, y1] = parse_coords(head);
        auto [x2, y2] = parse_coords(tail);
        lines.push_back({x1, y1, x2, y2});
    }
}

uint32_t solution_part1(const std::list<std::string>& input) {
    std::list<Line> lines;
    parse_input(input, lines);

    auto filtered = lines | std::ranges::views::filter([](const Line& line) { return line.is_straight(); });
    size_t width = std::max(std::ranges::max(filtered, {}, &Line::x1).x1, std::ranges::max(filtered, {}, &Line::x2).x2);
    size_t height = std::max(std::ranges::max(filtered, {}, &Line::y1).y1, std::ranges::max(filtered, {}, &Line::y2).y2);

    Lanternfish ctx(width+1, height+1);

    for (const auto& line : filtered) {
        ctx.draw_line(line);
    }

    return ctx.count_ge(2);
}

uint32_t solution_part2(const std::list<std::string>& input) {
    std::list<Line> lines;
    parse_input(input, lines);

    size_t width = std::max(std::ranges::max(lines, {}, &Line::x1).x1, std::ranges::max(lines, {}, &Line::x2).x2);
    size_t height = std::max(std::ranges::max(lines, {}, &Line::y1).y1, std::ranges::max(lines, {}, &Line::y2).y2);

    Lanternfish ctx(width+1, height+1);

    for (const auto& line : lines) {
        ctx.draw_line(line);
    }

    return ctx.count_ge(2);
}

} // namespace aoc2021::day5