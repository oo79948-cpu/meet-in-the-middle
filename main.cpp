
#include <fstream>
#include <iostream>
#include <ostream>
#include "src/meet.hpp"
#include "src/meet.cpp"

int main() {
    std::cout << "Enter the path to the file (relative to the executable): ";
    std::string filepath;
    std::cin >> filepath;

    std::ifstream input;
    input.open(filepath);

    if (input.is_open()) {
        LinkedList<int> list;
        std::string item;

        while (std::getline(input, item, ',')) {
            list.add(std::stoi(item));
        }

        std::cout << "Median: " << list.getMedian() << "\n";
        std::cout << "Mean: " << list.getMean() << "\n";
    } else {
        std::cout << "Could not open file" << std::endl;
        return 1;
    }

    input.close();
}
