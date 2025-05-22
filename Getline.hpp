//
// Created by ineedmypills on 22.05.2025.
//

#ifndef GETLINE_HPP
#define GETLINE_HPP

#include <iostream>
#include <string>

inline std::string trim_input(const std::string& s) {
    const size_t first = s.find_first_not_of(" \t");
    if (std::string::npos == first) return "";
    const size_t last = s.find_last_not_of(" \t");
    return s.substr(first, (last - first + 1));
}

inline int getValidChoice() {
    std::string input;

    while (true) {
        std::cout << "Введите число (1-3): ";
        std::getline(std::cin, input);
        input = trim_input(input);

        if (input.length() != 1) {
            std::cout << "Ошибка: введите ровно одну цифру!\n";
            continue;
        }

        if (!isdigit(input[0])) {
            std::cout << "Ошибка: введен недопустимый символ!\n";
            continue;
        }

        const int choice = input[0] - '0';

        if (choice < 1 || choice > 3) {
            std::cout << "Ошибка: число должно быть от 1 до 3!\n";
            continue;
        }

        //std::cout << choice << std::endl;
        return choice;
    }
}

#endif //GETLINE_HPP
