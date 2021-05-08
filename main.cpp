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
void print_vector(std::vector<T> &stdV, ft::vector<T> &myV) {
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
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer vectors using " << CYAN << "copy constructor" << RESET << std::endl;
            std::vector<int> copyV(stdVe);
            ft::vector<int> myCopyV(myVe);
            print_vector(copyV, myCopyV);
//vector max_size()
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".max_size() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart vector: " << CYAN << stdV.max_size() << std::endl;
            std::cout << GREEN << "My vector: " << CYAN << myV.max_size() << RESET << std::endl;
//vector resize()
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".resize(size_type n) " << RED << "function: " << std::endl;
            for (size_t i = 0; i < 10; i++) {
                int g = rand() % 10;
                stdV.push_back(g);
                myV.push_back(g);
            }
            std::cout << std::endl;
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
            std::cout << RED << "Testing " << CYAN << ".reserve(size_type n) " << RED << "function: " << std::endl;
            print_vector(stdV, myV);
            stdV.reserve(100);
            myV.reserve(100);
            std::cout << MAGENTA << "  RESERVE  " << RESET << std::endl;
            std::cout << GREEN << "Standart vector .size(): " << CYAN << stdV.size() << std::endl;
            std::cout << GREEN << "My vector .size(): " << CYAN << myV.size() << RESET << std::endl;
            std::cout << GREEN << "Standart vector .capacity(): " << CYAN << stdV.capacity() << std::endl;
            std::cout << GREEN << "My vector .capacity(): " << CYAN << myV.capacity() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".front() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart vector front: " << CYAN << stdV.front() << std::endl;
            std::cout << GREEN << "My vector front: " << CYAN << myV.front() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".back() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart vector back: " << CYAN << stdV.back() << std::endl;
            std::cout << GREEN << "My vector back: " << CYAN << myV.back() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".at(size_type n) " << RED << "function: " << std::endl;
            try {
                std::cout << GREEN << "Standart vector back: " << CYAN << stdV.at(3) << std::endl;
            std::cout << GREEN << "My vector back: " << CYAN << myV.at(3) << std::endl;
            } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".assign(InputIterator first, InputIterator last) " << RED << "function: " << std::endl;
            std::vector<int> assignV(5, 1);
            ft::vector<int> myAssignV(5, 1);
            myV.assign(++myAssignV.begin(), --myAssignV.end());
            stdV.assign(++assignV.begin(), --assignV.end());
            std::cout << GREEN<< "Standart vector: " << CYAN;
            print_vector(stdV, myV);
            std::cout << RED << "Testing " << CYAN << ".assign(size_type n, const value_type& val) " << RED << "function: " << std::endl;
            myV.assign(6, 1);
            stdV.assign(6, 1);
            print_vector(stdV, myV);
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".pop_back() " << RED << "function: " << std::endl;
            stdV.pop_back();
            myV.pop_back();
            print_vector(stdV, myV);
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".push_back(const value_type& val) " << RED << "function: " << std::endl;
            stdV.push_back(7);
            myV.push_back(7);
            print_vector(stdV, myV);
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".erase(iterator position) " << RED << "function: " << std::endl;
            stdV.erase(--stdV.end());
            myV.erase(--myV.end());
            print_vector(stdV, myV);
            std::cout << RED << "Testing " << CYAN << ".erase(iterator first, iterator last) " << RED << "function: " << std::endl;
            stdV.erase(++stdV.begin(), --stdV.end());
            myV.erase(++myV.begin(), --myV.end());
            print_vector(stdV, myV);
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".swap(vector& x) " << RED << "function: " << std::endl;
            std::vector<int> swapV;
            ft::vector<int> mswapV;
            for (int i = 0; i < 5; i++) {
                int g = rand() % 10;
                swapV.push_back(g);
                mswapV.push_back(g);
            }
            std::cout << MAGENTA << "Vector for swap" << std::endl;
            print_vector(swapV, mswapV);
            std::cout << MAGENTA << "              SWAP!" << std::endl;
            myV.swap(mswapV);
            stdV.swap(swapV);
            std::cout << MAGENTA << "Vector after swap" << std::endl;
            print_vector(stdV, myV);
        }
        else if (input == "exit")
            return 0;
        else
            std::cout << RED << "Unknown test" << RESET << std::endl;
    }
    return 0;
}
