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

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <list>

namespace po = boost::program_options;


int main(int argc, char* argv[]) {
    po::options_description descs("Options");

    // clang-format off
    descs.add_options()
        ("help,h", "Help screen")
        ("part", po::value<int>()->default_value(1), "Solution part (1 or 2, default 1)")
        ("fname", po::value<std::string>(), "Input filename");
    // clang-format on

    po::positional_options_description pos_descs;
    pos_descs.add("fname", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(descs).positional(pos_descs).run(), vm);

    po::notify(vm);

    if (vm.contains("help")) {
        std::cout << descs << std::endl;
        return 1;
    }

    if (!vm.contains("fname")) {
        std::cout << "Input file name is required" << std::endl;
        return 1;
    }

    int part = vm["part"].as<int>();
    if ((part != 1) && (part != 2)) {
        std::cout << "Invalid solution part" << std::endl;
        return 1;
    }

    std::ifstream input(vm["fname"].as<std::string>());
    std::list<int> numbers;
    for (std::string line; std::getline(input, line);)
    {
        numbers.push_back(std::stoi(line));
    }

    size_t result = part == 1 ? aoc2021::day1::solution_part1(numbers) : aoc2021::day1::solution_part2(numbers);
    std::cout << "result: " << result << std::endl;
}