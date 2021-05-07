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

template<typename T>
void print_vector(std::vector<T> stdV, ft::vector<T> myV) {
    std::cout << GREEN<< "Standart vector: " << CYAN;
    for (size_t i = 0; i < stdV.size(); i++)
        std::cout << stdV[i] << " ";
    std::cout << std::endl;
    std::cout << GREEN<< "My vector: " << CYAN;
    for (size_t i = 0; i < myV.size(); i++)
        std::cout << myV[i] << " ";
    std::cout << std::endl;
    std::cout << GREEN << "Standart vector .size(): " << CYAN << stdV.size() << std::endl;
    std::cout << GREEN << "My vector .size(): " << CYAN << myV.size() << RESET << std::endl;
    std::cout << GREEN << "Standart vector .capacity(): " << CYAN << stdV.capacity() << std::endl;
    std::cout << GREEN << "My vector .capacity(): " << CYAN << myV.capacity() << RESET << std::endl;
}

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
            std::cout << GREEN << "Standart vector .size(): " << CYAN << stdV.size() << std::endl;
            std::cout << GREEN << "My vector .size(): " << CYAN << myV.size() << RESET << std::endl;
            std::cout << GREEN << "Standart vector .capacity(): " << CYAN << stdV.capacity() << std::endl;
            std::cout << GREEN << "My vector .capacity(): " << CYAN << myV.capacity() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer vectors using " << CYAN << "filling constructor" << RESET << std::endl;
            ft::vector<int> myVe(5, 3);
            std::vector<int> stdVe(5, 3);
            print_vector(stdVe, myVe);
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer vectors using " << CYAN << "range constructor" << RESET << std::endl;
            std::vector<int> ayV(++stdVe.begin(), --stdVe.end());
            ft::vector<int> amyV(++myVe.begin(), --myVe.end());
            print_vector(ayV, amyV);
//vector max_size()
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".max_size() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart vector: " << CYAN << stdV.max_size() << std::endl;
            std::cout << GREEN << "My vector: " << CYAN << myV.max_size() << RESET << std::endl;
//vector resize()
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".resize() " << RED << "function: " << std::endl;
            for (size_t i = 0; i < 10; i++) {
                int g = rand() % 10;
                stdV.push_back(g);
                myV.push_back(g);
            }
            print_vector(stdV, myV);
            std::cout << MAGENTA << "  RESIZE  " << RESET << std::endl;
            stdV.resize(10);
            myV.resize(10);
            print_vector(stdV, myV);
            std::cout << MAGENTA << "  RESIZE  " << RESET << std::endl;
            stdV.resize(5);
            myV.resize(5);
            print_vector(stdV, myV);
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".reserve() " << RED << "function: " << std::endl;
            stdV.clear();
            myV.clear();
            print_vector(stdV, myV);
            stdV.reserve(20);
            myV.reserve(20);
            print_vector(stdV, myV);
        }
        else if (input == "exit")
            return 0;
        else
            std::cout << RED << "Unknown test" << RESET << std::endl;
    }
    return 0;
}
