//
// Created by ineedmypills on 21.05.2025.
//

#ifndef JSONOUTPUT_HPP
#define JSONOUTPUT_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "json.hpp"

using json = nlohmann::json;

inline void json_output(const std::string& inputJsonFile, const std::string& sortKey = "firstName")
{
    try {
        std::ifstream in(inputJsonFile);
        if (!in.is_open()) {
            std::cerr << "Ошибка: Невозможно открыть файл " << inputJsonFile << "\n";
            return;
        }

        json data;
        in >> data;
        in.close();

        if (!data.is_array()) {
            std::cerr << "Ошибка: JSON не является массивом\n";
            return;
        }

        std::sort(data.begin(), data.end(),
            [&sortKey](const json& a, const json& b) {
                if (!a.contains(sortKey) || !b.contains(sortKey)) {
                    throw std::runtime_error("Отсутствует ключ '" + sortKey + "'");
                }
                return a[sortKey].get<std::string>() <
                       b[sortKey].get<std::string>();
            });

#ifdef _WIN32
        system("color");
#endif

        std::cout << "\033[36m";
        std::cout << data.dump(4) << "\n";
        std::cout << "\033[0m";

    } catch (const std::exception& e) {
        std::cerr << "\033[31mОшибка: " << e.what() << "\033[0m\n";
    }
}

#endif //JSONOUTPUT_HPP
