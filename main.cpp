#include "list.hpp"
#include <list>
#include <iostream>
#include <memory>
#include "Colors.hpp"
#include <ctime>
#include <unistd.h>
#include <cmath>
#include <vector>
#include "vector.hpp"

void list_tester();

int main() {
    std::string input;
    std::cout << GREEN <<"Hello this is the tester for my containers on" << RED << " C++" << RESET << std::endl;
    std::cout << YELLOW << "1. " << CYAN << "list" << RESET << std::endl;
    std::cout << YELLOW << "2. " << CYAN << "vector" << RESET << std::endl;
    std::cout << YELLOW << "3. " << CYAN << "map" << RESET << std::endl;
    std::cout << YELLOW << "4. " << CYAN << "stack" << RESET << std::endl;
    std::cout << YELLOW << "5. " << CYAN << "queue" << RESET << std::endl;
    while(true) {
        srand((unsigned int)time(0));
        std::cout << BLUE "Enter container name to testing or exit: " << RESET;
        std::getline(std::cin, input);
        if (input == "list") {
            list_tester();
        }
        else if (input == "vector") {
            std::cout << GREEN <<"##############################################################" << std::endl;
            std::cout << "###                     ";
            std::cout << CYAN << "Vector tester" << GREEN"                      ###" << std::endl;
            std::cout << "##############################################################\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer vectors using " << CYAN << "default constructor" << RESET << std::endl;
            ft::vector<int> myV;
            std::vector<int> stdV;
            stdV.clear();
            std::cout << GREEN << "Standart list .size(): " << CYAN << stdV.size() << std::endl;
            std::cout << GREEN << "My list .size(): " << CYAN << myV.size() << RESET << std::endl;
            std::cout << GREEN << "Standart list .capacity(): " << CYAN << stdV.capacity() << std::endl;
            std::cout << GREEN << "My list .capacity(): " << CYAN << myV.capacity() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer vectors using " << CYAN << "filling constructor" << RESET << std::endl;
            ft::vector<int> myVe(5, 3);
            std::vector<int> stdVe(5, 3);
            std::cout << GREEN<< "Standart vector: " << CYAN;
            for (size_t i = 0; i < stdVe.size(); i++)
                std::cout << stdVe[i] << " ";
            std::cout << std::endl;
            std::cout << GREEN<< "My vector: " << CYAN;
            for (size_t i = 0; i < myVe.size(); i++)
                std::cout << myVe[i] << " ";
            std::cout << std::endl;
            std::cout << GREEN << "Standart list .size(): " << CYAN << stdVe.size() << std::endl;
            std::cout << GREEN << "My list .size(): " << CYAN << myVe.size() << RESET << std::endl;
            std::cout << GREEN << "Standart list .capacity(): " << CYAN << stdVe.capacity() << std::endl;
            std::cout << GREEN << "My list .capacity(): " << CYAN << myVe.capacity() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer vectors using " << CYAN << "range constructor" << RESET << std::endl;
            std::vector<int> ayV;
            ayV.insert(ayV.begin(),stdVe.begin(), stdVe.end());
        }
        else if (input == "exit")
            return 0;
        else
            std::cout << RED << "Unknown test" << RESET << std::endl;
    }
    return 0;
}
