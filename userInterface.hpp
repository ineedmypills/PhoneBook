//
// Created by ineedmypills on 22.05.2025.
//

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "JSONOutput.hpp"
#include "Getline.hpp"
#include <iostream>


inline void userInterface() {

    std::cout << "Сортировать .json по:\n1. Имени\n2. Фамилии\n3. Номеру\n";
    std::string sortKey;
    switch (getValidChoice()) { //Фарит, не обижайся ;P
        case 1:
            sortKey = "firstName";
            break;
        case 2:
            sortKey = "lastName";
            break;
        case 3:
            sortKey = "number";
            break;
    }

    json_output("output.json", sortKey);
};

#endif //USERINTERFACE_HPP