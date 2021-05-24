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
#include "queue.hpp"
#include <queue>
#include <stack>
#include "stack.hpp"
#include <map>
#include "map.hpp"
#include <set>
#include "set.hpp"

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
        else if (input == "queue") {
            std::cout << GREEN <<"##############################################################" << std::endl;
            std::cout << "###                     ";
            std::cout << CYAN << "Queue tester" << GREEN"                       ###" << std::endl;
            std::cout << "##############################################################\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer queues using " << CYAN << "default constructor" << RESET << std::endl;
            std::queue<int, std::list<int> > stdQ;
            ft::queue<int, ft::list<int> > myQ;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".empty() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart queue .empty(): " << CYAN << (stdQ.empty() ? "true" : "false") << std::endl;
            std::cout << GREEN << "My queue .empty(): " << CYAN << (myQ.empty() ? "true" : "false") << RESET << std::endl;
            for (int i = 0; i < 10; i++) {
                int g = rand() % 10;
                stdQ.push(g);
                myQ.push(g);
            }
            std::cout << GREEN << "Standart queue .empty(): " << CYAN << (stdQ.empty() ? "true" : "false") << std::endl;
            std::cout << GREEN << "My queue .empty(): " << CYAN << (myQ.empty() ? "true" : "false") << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".size() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart queue size: " << CYAN << stdQ.size() << std::endl;
            std::cout << GREEN << "My queue size: " << CYAN << myQ.size() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".front() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart queue front: " << CYAN << stdQ.front() << std::endl;
            std::cout << GREEN << "My queue front: " << CYAN << myQ.front() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".back() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart queue back: " << CYAN << stdQ.back() << std::endl;
            std::cout << GREEN << "My queue back: " << CYAN << myQ.back() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".push(124) " << RED << "function: " << std::endl;
            stdQ.push(124);
            myQ.push(124);
            std::cout << GREEN << "Standart queue back: " << CYAN << stdQ.back() << std::endl;
            std::cout << GREEN << "My queue back: " << CYAN << myQ.back() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".pop() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "Before .pop():" << std::endl;
            std::cout << GREEN << "Standart queue front: " << CYAN << stdQ.front() << std::endl;
            std::cout << GREEN << "My queue front: " << CYAN << myQ.front() << RESET << std::endl;
            stdQ.pop();
            myQ.pop();
            std::cout << YELLOW << "after .pop():" << std::endl;
            std::cout << GREEN << "Standart queue front: " << CYAN << stdQ.front() << std::endl;
            std::cout << GREEN << "My queue front: " << CYAN << myQ.front() << RESET << std::endl;
        }
        else if (input == "stack") {
            std::cout << GREEN <<"##############################################################" << std::endl;
            std::cout << "###                     ";
            std::cout << CYAN << "Stack tester" << GREEN"                       ###" << std::endl;
            std::cout << "##############################################################\n" << RESET << std::endl;
            std::cout << GREEN << "Create two integer Stacks using " << CYAN << "default constructor" << RESET << std::endl;
            std::stack<int, std::list<int> > stdS;
            ft::stack<int, ft::list<int> > myS;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".empty() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart stack .empty(): " << CYAN << (stdS.empty() ? "true" : "false") << std::endl;
            std::cout << GREEN << "My stack .empty(): " << CYAN << (myS.empty() ? "true" : "false") << RESET << std::endl;
            for (int i = 0; i < 10; i++) {
                int g = rand() % 10;
                stdS.push(g);
                myS.push(g);
            }
            std::cout << GREEN << "Standart stack .empty(): " << CYAN << (stdS.empty() ? "true" : "false") << std::endl;
            std::cout << GREEN << "My stack .empty(): " << CYAN << (myS.empty() ? "true" : "false") << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".size() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart stack size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My stack size: " << CYAN << myS.size() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".top() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart stack top: " << CYAN << stdS.top() << std::endl;
            std::cout << GREEN << "My stack top: " << CYAN << myS.top() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".push(124) " << RED << "function: " << std::endl;
            stdS.push(124);
            myS.push(124);
            std::cout << GREEN << "Standart stack top: " << CYAN << stdS.top() << std::endl;
            std::cout << GREEN << "My stack top: " << CYAN << myS.top() << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".pop() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "Before .pop():" << std::endl;
            std::cout << GREEN << "Standart stack front: " << CYAN << stdS.top() << std::endl;
            std::cout << GREEN << "My stack front: " << CYAN << myS.top() << RESET << std::endl;
            stdS.pop();
            myS.pop();
            std::cout << YELLOW << "after .pop():" << std::endl;
            std::cout << GREEN << "Standart stack top: " << CYAN << stdS.top() << std::endl;
            std::cout << GREEN << "My stack top: " << CYAN << myS.top() << RESET << std::endl;
        }
        else if(input == "map") {
            std::cout << GREEN << "##############################################################" << std::endl;
            std::cout << "###                     ";
            std::cout << CYAN << "Map tester" << GREEN"                         ###" << std::endl;
            std::cout << "##############################################################\n" << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << GREEN << "Create two integer, string maps using " << CYAN << "default constructor" << RESET
                      << std::endl;
            std::map<int, std::string> stdM;
            ft::map<int, std::string> myM;
            std::map<int, std::string>::iterator itm = stdM.begin();
            ft::map<int, std::string>::iterator mitm = myM.begin();
            std::cout << GREEN << "St First: " << CYAN << itm->first << RED << ", st Second: " << CYAN << itm->second
                      << std::endl;
            std::cout << GREEN << "My First: " << CYAN << mitm->first << RED << ", my Second: " << CYAN << mitm->second
                      << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << YELLOW << "Create two integer, string maps using " << CYAN << "range constructor" << RESET
                      << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdM.insert(std::pair<int, std::string>(r, "l"));
                myM.insert(std::pair<int, std::string>(r, "l"));
            }
            std::map<int, std::string> stdM2(stdM.begin(), stdM.end());
            ft::map<int, std::string> myM2(myM.begin(), myM.end());
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << GREEN << "St2 size: " << CYAN << stdM2.size() << std::endl;
            std::cout << GREEN << "My2 size: " << CYAN << myM2.size() << std::endl;

            std::cout << RED << " stdM: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << RED << " stdM2: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM2.begin(), ite = stdM2.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << RED << " myM: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << RED << " myM2: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM2.begin(), ite = myM2.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
           std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".insert(const value_type &val) " << RED << "function: " << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdM.insert(std::pair<int, std::string>(r, "l"));
                myM.insert(std::pair<int, std::string>(r, "l"));
            }
            std::cout << std::endl;
            std::cout << GREEN << "Std insert: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My insert: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator it = myM.begin(), ite = myM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".max_size() " << RED << "function: " << std::endl;
            std::cout << GREEN << "St max size: " << CYAN << stdM.max_size() << std::endl;
            std::cout << GREEN << "My max size: " << CYAN << myM.max_size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".empty() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart map .empty(): " << CYAN << (stdM.empty() ? "true" : "false") << std::endl;
            std::cout << GREEN << "My map .empty(): " << CYAN << (myM.empty() ? "true" : "false") << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".erase(iterator position) " << RED << "function: " << std::endl;
            std::cout << GREEN << "Std map: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My map: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            stdM.erase(++(stdM.begin()));
            myM.erase(++(myM.begin()));
            std::cout << GREEN << "Std map: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My map: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << "CHeck: " << stdM.erase(1) << std::endl;
            std::cout << "CHeck2: " << myM.erase(1) << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << "operator[key]" << RED << ": " << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            stdM[66] = "gg";
            myM[66] = "gg";
            std::cout << GREEN << "stdM[66]: " << CYAN << stdM[66] << std::endl;
            std::cout << GREEN << "myM[66]: " << CYAN << myM[66] << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".clear()" << RED << " function: " << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            stdM.clear();
            myM.clear();
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".swap(map &x)" << RED << " function: " << std::endl;
            myM2.clear();
            stdM2.clear();
            for (int i = 0; i < 10; i++) {
                myM.insert(std::pair<int, std::string>(i, "k"));
                stdM.insert(std::pair<int, std::string>(i, "k"));

            }
            for (int i = 100; i < 105; i++) {
                myM2.insert(std::pair<int, std::string>(i, "k"));
                stdM2.insert(std::pair<int, std::string>(i, "k"));
            }
            std::cout << GREEN << "Std map: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "Std map2: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM2.begin(), ite = stdM2.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My map: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My map2: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM2.begin(), ite = myM2.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << GREEN << "St2 size: " << CYAN << stdM2.size() << std::endl;
            std::cout << GREEN << "My2 size: " << CYAN << myM2.size() << std::endl;
            std::cout << MAGENTA << "                 SWAP" << std::endl;
            myM.swap(myM2);
            stdM.swap(stdM2);
            std::cout << GREEN << "Std map: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "Std map2: " << " " << CYAN;
            for (std::map<int, std::string>::iterator it = stdM2.begin(), ite = stdM2.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My map: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My map2: " << " " << CYAN;
            for (ft::map<int, std::string>::iterator mit = myM2.begin(), ite = myM2.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdM.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myM.size() << std::endl;
            std::cout << GREEN << "St2 size: " << CYAN << stdM2.size() << std::endl;
            std::cout << GREEN << "My2 size: " << CYAN << myM2.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".lower_bound(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << GREEN << "Std: " << CYAN << stdM.lower_bound(101)->first << std::endl;
            std::cout << GREEN << "My: " << CYAN << myM.lower_bound(101)->first << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".upper_bound(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << GREEN << "Std: " << CYAN << stdM.upper_bound(101)->first << std::endl;
            std::cout << GREEN << "My: " << CYAN << myM.upper_bound(101)->first << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".equal_range (const key_type& k)" << RED << " function: " << std::endl;
            std::pair <std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> tst = stdM.equal_range(102);
            std::pair <ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> mtst = myM.equal_range(102);
            std::cout << GREEN << "Std map: " << " " << CYAN;
            for(; tst.first != tst.second; tst.first++) {
                std::cout << tst.first->first << " ";
            }
            std::cout << std::endl;
            std::cout << GREEN << "My map: " << " " << CYAN;
            for(; mtst.first != mtst.second; mtst.first++) {
                std::cout << mtst.first->first << " ";
            }
            std::cout << std::endl;
            std::cout << GREEN << "Std: " << CYAN << stdM.upper_bound(101)->first << std::endl;
            std::cout << GREEN << "My: " << CYAN << myM.upper_bound(101)->first << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".find(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << GREEN << "Std: " << CYAN << stdM.find(103)->first << std::endl;
            std::cout << GREEN << "My: " << CYAN << myM.find(103)->first << std::endl;
            std::cout << GREEN << "Std: " << CYAN << stdM.find(108)->first << std::endl;
            std::cout << GREEN << "My: " << CYAN << myM.find(108)->first << std::endl;
        }
        else if (input == "set") {
            std::cout << GREEN << "##############################################################" << std::endl;
            std::cout << "###                     ";
            std::cout << CYAN << "Set tester" << GREEN"                         ###" << std::endl;
            std::cout << "##############################################################\n" << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << GREEN << "Create two integer, string sets using " << CYAN << "default constructor" << RESET
                      << std::endl;
            std::set<int> stdS;
            ft::set<int> myS;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << YELLOW << "Create two integer, string sets using " << CYAN << "range constructor" << RESET
                      << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdS.insert(r);
                myS.insert(r);
            }
            std::set<int> stdS2(stdS.begin(), stdS.end());
            ft::set<int> myS2(myS.begin(), myS.end());
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << GREEN << "St2 size: " << CYAN << stdS2.size() << std::endl;
            std::cout << GREEN << "My2 size: " << CYAN << myS2.size() << std::endl;

            std::cout << RED << " stdS: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << RED << " stdS2: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS2.begin(), ite = stdS2.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << RED << " myS: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << RED << " myS2: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS2.begin(), ite = myS2.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
            std::cout << RED << "Testing " << CYAN << ".insert(const value_type &val) " << RED << "function: " << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdS.insert(r);
                myS.insert(r);
            }
            std::cout << std::endl;
            std::cout << GREEN << "Std insert: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My insert: " << " " << CYAN;
            for (ft::set<int>::iterator it = myS.begin(), ite = myS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".max_size() " << RED << "function: " << std::endl;
            std::cout << GREEN << "St max size: " << CYAN << stdS.max_size() << std::endl;
            std::cout << GREEN << "My max size: " << CYAN << myS.max_size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".empty() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Standart set .empty(): " << CYAN << (stdS.empty() ? "true" : "false") << std::endl;
            std::cout << GREEN << "My set .empty(): " << CYAN << (myS.empty() ? "true" : "false") << RESET << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".erase(iterator position) " << RED << "function: " << std::endl;
            std::cout << GREEN << "Std set: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My set: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            stdS.erase(++(stdS.begin()));
            myS.erase(++(myS.begin()));
            std::cout << GREEN << "Std set: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My set: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << "CHeck: " << stdS.erase(1) << std::endl;
            std::cout << "CHeck2: " << myS.erase(1) << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".clear()" << RED << " function: " << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            stdS.clear();
            myS.clear();
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".swap(set &x)" << RED << " function: " << std::endl;
            myS2.clear();
            stdS2.clear();
            for (int i = 0; i < 10; i++) {
                myS.insert(i);
                stdS.insert(i);

            }
            for (int i = 100; i < 105; i++) {
                myS2.insert(i);
                stdS2.insert(i);
            }
            std::cout << GREEN << "Std set: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "Std set2: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS2.begin(), ite = stdS2.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My set: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My set2: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS2.begin(), ite = myS2.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << GREEN << "St2 size: " << CYAN << stdS2.size() << std::endl;
            std::cout << GREEN << "My2 size: " << CYAN << myS2.size() << std::endl;
            std::cout << MAGENTA << "                 SWAP" << std::endl;
            myS.swap(myS2);
            stdS.swap(stdS2);
            std::cout << GREEN << "Std set: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "Std set2: " << " " << CYAN;
            for (std::set<int>::iterator it = stdS2.begin(), ite = stdS2.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My set: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << GREEN << "My set2: " << " " << CYAN;
            for (ft::set<int>::iterator mit = myS2.begin(), ite = myS2.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << GREEN << "St size: " << CYAN << stdS.size() << std::endl;
            std::cout << GREEN << "My size: " << CYAN << myS.size() << std::endl;
            std::cout << GREEN << "St2 size: " << CYAN << stdS2.size() << std::endl;
            std::cout << GREEN << "My2 size: " << CYAN << myS2.size() << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".lower_bound(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << GREEN << "Std: " << CYAN << *(stdS.lower_bound(101)) << std::endl;
            std::cout << GREEN << "My: " << CYAN << *(myS.lower_bound(101)) << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".upper_bound(const value_type& val)" << RED << " function: " << std::endl;
            std::cout << GREEN << "Std: " << CYAN << *(stdS.upper_bound(101)) << std::endl;
            std::cout << GREEN << "My: " << CYAN << *(myS.upper_bound(101)) << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".equal_range (const value_type& val)" << RED << " function: " << std::endl;
            std::pair <std::set<int>::iterator, std::set<int>::iterator> tst = stdS.equal_range(102);
            std::pair <ft::set<int>::iterator, ft::set<int>::iterator> mtst = myS.equal_range(102);
            std::cout << GREEN << "Std set: " << " " << CYAN;
            for(; tst.first != tst.second; tst.first++) {
                std::cout << *(tst.first) << " ";
            }
            std::cout << std::endl;
            std::cout << GREEN << "My set: " << " " << CYAN;
            for(; mtst.first != mtst.second; mtst.first++) {
                std::cout << *(mtst.first) << " ";
            }
            std::cout << std::endl;
            std::cout << GREEN << "Std: " << CYAN << *(stdS.upper_bound(101)) << std::endl;
            std::cout << GREEN << "My: " << CYAN << *(myS.upper_bound(101)) << std::endl;
            std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET
                      << std::endl;
            std::cout << RED << "Testing " << CYAN << ".find(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << GREEN << "Std: " << CYAN << *(stdS.find(103)) << std::endl;
            std::cout << GREEN << "My: " << CYAN << *(myS.find(103)) << std::endl;
        }
        else if (input == "exit")
            return 0;
        else
            std::cout << RED << "Unknown test" << RESET << std::endl;
    }
    return 0;
}
