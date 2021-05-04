#include "List.hpp"
#include <list>
#include <iostream>
#include <memory>

template<typename T>
struct comparator
{
    // Compare 2 Player objects using name
    bool operator ()(const T & a, const T & b)
    {
        return a > b;
    }
};

bool mycomparison (int first, int second)
{ return first < second; }

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
    a.clear();
    b.clear();
    ft::list<int> eqList;
    ft::list<int> otherList(5, 4);
    eqList = otherList;
    otherList.clear();
    for (myIt = eqList.begin(); myIt != eqList.end(); myIt++)
        std::cout << "Copy constructor: " << *myIt << std:: endl;
    std::cout << "Size: " << eqList.size() << std::endl;
    ft::list<int> anCop(eqList);
    eqList.clear();
    for (myIt = anCop.begin(); myIt != anCop.end(); myIt++)
        std::cout << "Copy constructor2: " << *myIt << std:: endl;
    std::cout << "<+==============================================+>\n\n";
    anCop.clear();
    otherList.clear();
    testPushBack.clear();
    pushFrontTester.clear();
    myList2.clear();
    myList.clear();
    ft::list<char> hohoh;
    for (int i = 0; i < 10; ++i)
        hohoh.push_back((char)(i + 65));
    ft::list<char>::reverse_iterator rit = hohoh.rbegin();
    for (; rit != hohoh.rend(); rit++)
        std::cout << "reverse it: " << *rit << std::endl;
    std::cout << hohoh.front() << std::endl;
    ft::list<char>::iterator newIt = hohoh.begin();
    newIt++;
    std::cout << "It: " << *newIt << std::endl;
    hohoh.insert(newIt, '!');
    std::cout << "Show insert by position: ";
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << *newIt << " ";
    std::cout << std::endl;
    newIt = hohoh.begin();
    for (int i = 0; i < 3; ++i)
        newIt++;
    std::cout << "newIt: " << *newIt << std::endl;
    hohoh.insert(newIt, 5, 'k');
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << "Insert by n: " << *newIt << std::endl;
    ft::list<char> insertList(4, '*');
    newIt = hohoh.begin();
    for (int i = 0; i < 3; ++i)
        newIt++;
    hohoh.insert(newIt, insertList.begin(), insertList.end());
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << "Insert between iterators: " << *newIt << std::endl;
    newIt = hohoh.begin();
    for (int i = 0; i < 4; ++i)
        newIt++;
    hohoh.erase(newIt);
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << "erased: " << *newIt << std::endl;
    std::cout << "resize: ";
    hohoh.resize(5, 't');
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << *newIt << " ";
    std::cout << std::endl;
    std::cout << "Resize if n > .size(): ";
    hohoh.resize(10, '^');
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << *newIt << " ";
    std::cout << std::endl;
    std::cout << "remove ^: ";
    hohoh.remove('^');
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << *newIt << " ";
    std::cout << std::endl << "Unique: ";
    hohoh.unique();
    for (newIt = hohoh.begin(); newIt != hohoh.end(); newIt++)
        std::cout << *newIt << " ";
    std::cout << std::endl;
    ft::list<int> l1;
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(2);
    l1.sort();
    ft::list<int> l2;
    l2.push_back(3);
    l2.push_back(7);
    l2.push_back(1);
    l2.push_back(2);
    l2.sort();
    l1.merge(l2, mycomparison);
    std::cout << "size: " << l1.size() << std::endl;
    std::cout << "merged: ";
   // l1.sort(comparator<int>());
    for (ft::list<int>::iterator lit = l1.begin(); lit != l1.end(); lit++)
        std::cout << *lit << " ";
//    std::cout << std::endl;
//    std::cout << "l2: ";
//    for (std::list<int>::iterator lit = l2.begin(); lit != l2.end(); lit++)
//        std::cout << *lit << " ";

    //    while(1);
	return 0;
}
