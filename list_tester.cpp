#include "Colors.hpp"
#include "list.hpp"
#include <list>
#include <iostream>
#include <cmath>
struct is_near {
    bool operator() (double first, double second)
    { return (fabs(first-second)<5.0); }
};
template<typename T>
struct pred
{
    bool operator ()(const T & a)
    {
        return a < 6;
    }
};


bool mycomparison (int first, int second)
{ return first > second; }

void list_tester() {
    std::cout << GREEN <<"##############################################################" << std::endl;
    std::cout << "###                     ";
    std::cout << CYAN << "List tester" << GREEN"                        ###" << std::endl;
    std::cout << "##############################################################\n" << RESET << std::endl;
//list filling constructor
    std::cout << GREEN << "Create two integer lists using " << CYAN << "filling constructor" << RESET << std::endl;
    std::list<int> stdList(5, 1);
    ft::list<int> myList(5, 3);
    std::cout << GREEN << "My list: " << CYAN;
    for(ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
//list empty()
    std::cout << GREEN<< "Standart list: " << CYAN;
    for(std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << MAGENTA << "<+==========================================================+>\n" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".empty() " << RED << "function: " << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN << (stdList.empty() ? "true" : "false") << std::endl;
    std::cout << GREEN << "My list: " << CYAN << (myList.empty() ? "true" : "false") << RESET << std::endl;
//list size()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;

    std::cout << RED << "Testing " << CYAN << ".size() " << RED << "function: " << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN << stdList.size() << std::endl;
    std::cout << GREEN << "My list: " << CYAN << myList.size() << RESET << std::endl;
//list max_size()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".max_size() " << RED << "function: " << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN << stdList.max_size() << std::endl;
    std::cout << GREEN << "My list: " << CYAN << myList.max_size() << RESET << std::endl;
//list front()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".front() " << RED << "function: " << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN << stdList.front() << std::endl;
    std::cout << GREEN << "My list: " << CYAN << myList.front() << RESET << std::endl;
//list back()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Add element in each lists for testing .back() in standart add 7, in my add 9" << RESET << std::endl;
    stdList.push_back(7);
    myList.push_back(9);
    std::cout << RED << "Testing " << CYAN << ".back() " << RED << "function: " << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN << stdList.back() << std::endl;
    std::cout << GREEN << "My list: " << CYAN << myList.back() << RESET << std::endl;
//list assign()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".assign(size_type n, const value_type& val) " << RED << "function: " << std::endl;
    stdList.assign(5, 66);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    myList.assign(5, 99);
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".assign(InputIterator first, InputIterator last) " << RED << "function: " << std::endl;
    std::list<int> copyList(10, 0);
    ft::list<int> copyList2(10, 0);
    stdList.assign(copyList.begin(), copyList.end());
    myList.assign(copyList2.begin(), copyList2.end());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    copyList2.clear();
    copyList.clear();
//list push_front() and push_back()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Add element in each lists to front: 4 and back: 8" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".push_back()" << RED << " and " << CYAN << ".push_front()" << RED << "function: " << std::endl;
    stdList.push_front(4);
    myList.push_front(4);
    stdList.push_back(8);
    myList.push_back(8);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
//list pop_back() and pop_front()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Remove element in each lists from front and back" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".pop_back()" << RED << " and " << CYAN << ".pop_front()" << RED << "function: " << std::endl;
    stdList.pop_front();
    myList.pop_front();
    stdList.pop_back();
    myList.pop_back();
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
//list insert()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Insert elements in each lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".insert(iterator position, const value_type& val)" << RED << "function: " << std::endl;
    stdList.insert(stdList.begin(), 5);
    myList.insert(myList.begin(), 5);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".insert(iterator position, size_type n, const value_type& val)" << RED << "function: " << std::endl;
    stdList.insert(++stdList.begin(), 4, 7);
    myList.insert(++myList.begin(), 4, 7);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".insert(iterator position, InputIterator first, InputIterator last)" << RED << "function: " << std::endl;
    std::list<int> cList(3,4);
    ft::list<int> cList2(3, 4);
    stdList.insert(++stdList.begin(), cList.begin(), cList.end());
    myList.insert(++myList.begin(), cList2.begin(), cList2.end());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    cList.clear();
    cList.clear();
//list erase()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Erase elements in each lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".erase(iterator position)" << RED << "function: " << std::endl;
    stdList.erase(++stdList.begin());
    myList.erase(++myList.begin());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".erase(iterator first, iterator last)" << RED << "function: " << std::endl;
    stdList.erase(++stdList.begin(), --stdList.end());
    myList.erase(++myList.begin(), --myList.end());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    stdList.clear();
    myList.clear();
//list swap()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Swap lists elements" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".swap(list& x)" << RED << "function: " << std::endl;
    std::list<int> stdList2;
    ft::list<int> myList2;
    stdList2.push_back(1);
    stdList2.push_back(2);
    stdList2.push_back(3);
    stdList2.push_back(4);
    stdList.push_back(6);
    stdList.push_back(7);
    stdList.push_back(8);
    stdList.push_back(9);
    stdList.push_back(0);
    myList2.push_back(1);
    myList2.push_back(2);
    myList2.push_back(3);
    myList2.push_back(4);
    myList.push_back(6);
    myList.push_back(7);
    myList.push_back(8);
    myList.push_back(9);
    myList.push_back(0);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "  SWAP  " << RESET << std::endl;
    myList.swap(myList2);
    stdList.swap(stdList2);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    stdList2.clear();
    myList2.clear();
//list resize()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Resize lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".resize(size_type n, value_type val = value_type()) n > _size " << RED << "function: " << std::endl;
    stdList.resize(10, 4);
    myList.resize(10, 4);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".resize(size_type n, value_type val = value_type()) n < _size " << RED << "function: " << std::endl;
    stdList.resize(5, 4);
    myList.resize(5, 4);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Resize lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".resize(size_type n, value_type val = value_type()) n > _size " << RED << "function: " << std::endl;
    stdList.resize(10, 4);
    myList.resize(10, 4);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << stdList.size() << RESET << std::endl;
//list splice()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Splice lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".splice(iterator position, list& x)" << RED << "function: " << std::endl;
    stdList2.resize(10, 3);
    myList2.resize(10, 3);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "             SPLICE          " << RESET <<std::endl;
    stdList.splice(++stdList.begin(), stdList2);
    myList.splice(++myList.begin(), myList2);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << RED << "\nTesting " << CYAN << ".splice(iterator position, list& x, iterator i)" << RED << "function: " << std::endl;
    stdList.assign(5, 2);
    myList.assign(5, 2);
    stdList2.resize(10, 3);
    myList2.resize(10, 3);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "             SPLICE          " << RESET <<std::endl;
    stdList.splice(++stdList.begin(), stdList2, --stdList2.end());
    myList.splice(++myList.begin(), myList2, --myList2.end());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << RED << "\nTesting " << CYAN << ".splice(iterator position, list& x, iterator first, iterator last)" << RED << "function: " << std::endl;
    stdList.assign(5, 2);
    myList.assign(5, 2);
    stdList2.resize(10, 3);
    myList2.resize(10, 3);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "             SPLICE          " << RESET <<std::endl;
    stdList.splice(++stdList.begin(), stdList2, ++stdList2.begin(), --stdList2.end());
    myList.splice(++myList.begin(), myList2, ++myList2.begin(), --myList2.end());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
//list remove()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Remove element from lists" << RESET << std::endl;
    std::cout << RED << "\nTesting " << CYAN << ".remove(const value_type& val)" << RED << "function: " << std::endl;
    stdList.assign(5, 2);
    myList.assign(5, 2);
    stdList2.resize(10, 3);
    myList2.resize(10, 3);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "             REMOVE         " << RESET <<std::endl;
    stdList.remove(2);
    myList.remove(2);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
//list remove_if()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Remove_if" << RESET << std::endl;
    std::cout << RED << "\nTesting " << CYAN << ".remove_if(Predicate pred)" << RED << "function: " << std::endl;
    stdList.assign(5, 2);
    myList.assign(5, 2);
    for (int i = 0; i < 10; ++i) {
        stdList.push_back(i);
        myList.push_back(i);
    }
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "             REMOVE  IF      " << RESET <<std::endl;
    stdList.remove_if(pred<int>());
    myList.remove_if(pred<int>());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
//list unique() and sort()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Unique" << RESET << std::endl;
    std::cout << RED << "\nTesting " << CYAN << ".unique()" << RED << " and " << CYAN << ".sort()" << RED << "function: " << std::endl;
    stdList.clear();
    myList.clear();
    for (int i = 0; i < 20; ++i) {
        int g = rand() % 10;
        stdList.push_back(g);
        myList.push_back(g);
    }
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    stdList.sort();
    myList.sort();
    std::cout << MAGENTA << "             SORT      " << RESET <<std::endl;
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "             UNIQUE      " << RESET <<std::endl;
    stdList.unique();
    myList.unique();
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << RED << "\nTesting " << CYAN << ".unique(BinaryPredicate binary_pred)" << RED << " and " << CYAN << ".sort(Compare comp)" << RED << "function: " << std::endl;
    stdList.sort(mycomparison);
    myList.sort(mycomparison);
    std::cout << MAGENTA << "             SORT      " << RESET <<std::endl;
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "             UNIQUE      " << RESET <<std::endl;
    stdList.unique(is_near());
    myList.unique(is_near());
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
// list merge()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Merge lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".merge(list& x)" << RED << "function: " << std::endl;
    stdList2.clear();
    myList2.clear();
    stdList.clear();
    myList.clear();
    for (int i = 0; i < 20; ++i) {
        int g = rand() % 10;
        stdList.push_back(g);
        myList.push_back(g);
        g = rand() % 10;
        stdList2.push_back(g);
        myList2.push_back(g);
    }
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "             MERGE         " << RESET <<std::endl;
    stdList.merge(stdList2);
    myList.merge(myList2);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Merge lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".merge(list& x, Compare comp)" << RED << "function: " << std::endl;
    stdList2.clear();
    myList2.clear();
    stdList.clear();
    myList.clear();
    for (int i = 0; i < 20; ++i) {
        int g = rand() % 10;
        stdList.push_back(g);
        myList.push_back(g);
        g = rand() % 10;
        stdList2.push_back(g);
        myList2.push_back(g);
    }
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
    std::cout << MAGENTA << "             MERGE         " << RESET <<std::endl;
    stdList.sort();
    stdList2.sort();
    myList.sort();
    myList2.sort();
    stdList.merge(stdList2, mycomparison);
    myList.merge(myList2, mycomparison);
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list2: " << CYAN;
    for (std::list<int>::iterator it = stdList2.begin(); it != stdList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "Standart list2 .size(): " << CYAN << stdList2.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list2: " << CYAN;
    for (ft::list<int>::iterator it = myList2.begin(); it != myList2.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << GREEN << "My list2 .size(): " << CYAN << myList2.size() << RESET << std::endl;
//list reverse()
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Reverse lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".reverse()" << RED << "function: " << std::endl;
    stdList2.clear();
    myList2.clear();
    stdList.clear();
    myList.clear();
    for (int i = 0; i < 20; ++i) {
        int g = rand() % 10;
        stdList.push_back(g);
        myList.push_back(g);
        g = rand() % 10;
        stdList2.push_back(g);
        myList2.push_back(g);
    }
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "             REVERSE         " << RESET <<std::endl;
    stdList.sort();
    myList.sort();
    stdList.reverse();
    myList.reverse();
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "\n<+==========================================================+>\n" << RESET << std::endl;
    std::cout << YELLOW << "Reverse lists" << RESET << std::endl;
    std::cout << RED << "Testing " << CYAN << ".clear()" << RED << "function: " << std::endl;
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
    std::cout << MAGENTA << "             CLEAR         " << RESET <<std::endl;
    stdList.clear();
    myList.clear();
    std::cout << GREEN << "Standart list: " << CYAN;
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "Standart list .size(): " << CYAN << stdList.size() << RESET << std::endl;
    std::cout << GREEN << "My list: " << CYAN;
    for (ft::list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    std::cout << GREEN << "My list .size(): " << CYAN << myList.size() << RESET << std::endl;
}

