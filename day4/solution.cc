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
#include <sstream>

namespace aoc2021::day4 {

static constexpr size_t kBoardSize{5U};

class BingoBoard {

public:
    BingoBoard() {
        for (auto& row : board) {
            row.fill(0);
        }
        row_flags.fill(0);
        column_flags.fill(0);
    }

    void init_row(size_t row_idx, const std::array<int, kBoardSize>& row) { board[row_idx] = row; }

    void mark_number(int value) {
        for (size_t row = 0; row < kBoardSize; row++) {
            for (size_t column = 0; column < kBoardSize; column++) {
                if (board[row][column] == value) {
                    row_flags[row] |= 1 << column;
                    column_flags[column] |= 1 << row;

                    if ((row_flags[row] == kWinMask) || (column_flags[column] == kWinMask)) {
                        winning = true;
                    }
                }
            }
        }
    }

    bool is_winning() const {
        return winning;
    }

    int unmarked_sum() const {
        int sum{0};

        for (size_t row = 0; row < kBoardSize; row++) {
            for (size_t column = 0; column < kBoardSize; column++) {
                if ((row_flags[row] & (1 << column)) == 0) {
                    sum += board[row][column];
                }
            }
        }

        return sum;
    }

private:
    static constexpr int kWinMask{0b11111};

    std::array<std::array<int, kBoardSize>, kBoardSize> board;
    std::array<int, kBoardSize> row_flags;
    std::array<int, kBoardSize> column_flags;
    bool winning{false};
};

void parse_input(const std::list<std::string>& input, std::vector<BingoBoard>& boards, std::list<int>& num_list) {
    auto it = input.begin();
    const auto& num_list_raw = *it;

    std::stringstream line_stream(num_list_raw);
    std::string num_raw;
    while (std::getline(line_stream, num_raw, ',')) {
        num_list.push_back(std::stoi(num_raw));
    }

    it++;
    it++;
    BingoBoard current_board;
    size_t current_row{0};
    while (it != input.end()) {
        if (it->empty()) {
            boards.push_back(current_board);
            current_board = BingoBoard{};
            current_row = 0;
            it++;
            continue;
        }

        std::array<int, kBoardSize> row;
        row.fill(0);

        std::stringstream num_line_raw(*it);
        size_t current_column{0};
        while (std::getline(num_line_raw, num_raw, ' ') && (current_column < kBoardSize)) {
            if (num_raw.empty()) {
                continue;
            }
            row[current_column] = std::stoi(num_raw);
            current_column++;
        }
        current_board.init_row(current_row, row);

        current_row++;
        it++;
    }
}

uint32_t solution_part1(const std::list<std::string>& input) {
    std::vector<BingoBoard> boards;
    std::list<int> num_list;

    parse_input(input, boards, num_list);

    uint32_t result{0};
    for (int num : num_list) {
        for (auto& board : boards) {
            board.mark_number(num);
            if (board.is_winning()) {
                result = board.unmarked_sum() * num;
                goto end;
            }
        }
    }

end:
    return result;
}

uint32_t solution_part2(const std::list<std::string>& input) {
    std::vector<BingoBoard> boards;
    std::list<int> num_list;

    parse_input(input, boards, num_list);

    uint32_t result{0};
    size_t num_winning{0};
    size_t least_winning_idx{0};
    for (int num : num_list) {
        for (size_t i = 0; i < boards.size(); i++) {
            auto& board = boards[i];
            if (board.is_winning()) {
                continue;
            }

            board.mark_number(num);
            if (board.is_winning()) {
                num_winning++;
                if (num_winning == (boards.size() - 1)) {
                    auto pos = std::find_if(
                            boards.begin(), boards.end(), [](const BingoBoard& b) { return !b.is_winning(); });
                    least_winning_idx = std::distance(boards.begin(), pos);
                }
            }
        }

        if (num_winning == boards.size()) {
            result = boards[least_winning_idx].unmarked_sum() * num;
            break;
        }
    }

    return result;
}

} // namespace aoc2021::day1