#include "List.hpp"
#include <list>
#include <iostream>


int main(void) {
	std::cout << "<+==============================================+>\n\n";
	std::cout << "Test my list and std::list" << std::endl;
	std::cout << "Create two empty list" << std::endl;
	std::list<int> stdList;
	std::cout << "std::list is empty: " << (stdList.empty() ? "true" : "false") << std::endl;
	std::list<int>::iterator it = stdList.begin();
	std::cout << "Standart list.begin(): " << *it << std::endl;
	ft::list<int> myList;
	std::cout << "My list is empty: " << (myList.empty() ? "true" : "false") << std::endl;
	ft::list<int>::iterator myIt = myList.begin();
	std::cout << "My list.begin(): " << *myIt << std::endl;
	it = stdList.end();
	std::cout << "Std::list.end(): " << *it << std::endl;
	myIt = myList.end();
	std::cout << "My list.end(): " << *myIt << std::endl;
	stdList.clear();

	for (int i = 0; i < 10; ++i)
		stdList.push_back(i + 1);
	for (it = stdList.begin(); it != stdList.end(); it++)
		std::cout << "stdList content: " << *it << std::endl;
	std::cout << "Use range constructor" <<std::endl;
	std::list<int> newStdList(stdList.begin(), stdList.end());
	for(it = newStdList.begin(); it != newStdList.end(); it++)
		std::cout << "newStdList content: " << *it << std::endl;
	std::cout << "Use Fill constructor on my list" << std::endl;
	ft::list<int> myList2(10, 1);
	std::cout << "<+==============================================+>\n\n";
	return 0;
}
