#include "List.hpp"
#include <list>
#include <iostream>
#include <memory>


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
	std::list<int> anotherList(10, 1);
	ft::list<int> myList2(10, 1);
	std::cout << "ft::list<int> myList2(10, 1);" << std::endl;
    for (myIt = myList2.begin(); myIt != myList2.end(); myIt++)
	    std::cout << "my list2 elements: " << *myIt << std::endl;
	ft::list<char> testPushBack;
	testPushBack.push_back('a');
	testPushBack.push_back('b');
	for(ft::list<char>::iterator myCharIt = testPushBack.begin(); myCharIt != testPushBack.end(); myCharIt++)
	    std::cout << "Push back tester: " << *myCharIt << std::endl;
	testPushBack.clear();
	std::cout << "testPushBack.clear();" << std::endl;
	std::cout << "testPushBack.size(): " << testPushBack.size() << std::endl;
	ft::list<std::string> pushFrontTester;
	pushFrontTester.push_front("Almir");
    pushFrontTester.push_front("Arpnine");
    pushFrontTester.push_front("Vova");
    pushFrontTester.push_front("boba");
    for (ft::list<std::string>::iterator strIt = pushFrontTester.begin(); strIt != pushFrontTester.end(); strIt++)
        std::cout << "push front test:" << *strIt << std::endl;

    ft::list<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    ft::list<int> b;
    b.push_back(10);
    b.push_back(20);
    b.push_back(30);
    if (a == b)
        std::cout << "Yeap it's true" << std::endl;
    std::list<int> g;
    g.pop_back();
    std::cout << "<+==============================================+>\n\n";
	return 0;
}
