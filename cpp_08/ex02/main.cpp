#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	try {
		std::cout << "=== SUBJECT MAIN ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== ADDITIONAL MAIN  ===" << std::endl;

	try {
		MutantStack<std::string> mstackStr;
		std::cout << "Pushing initial strings to stack...\n" << std::endl;
		mstackStr.push("Hello");
		mstackStr.push("World");
		std::cout << "Size after pushing: " << mstackStr.size() << std::endl;
		std::cout << "Checking current content of the stack:" << std::endl;
		MutantStack<std::string>::iterator itStr1 = mstackStr.begin();
		MutantStack<std::string>::iterator iteStr1 = mstackStr.end();
		while (itStr1 != iteStr1)
		{
			std::cout << *itStr1 << std::endl;
			++itStr1;
		}
		std::cout << std::endl;
		std::cout << "currently at the top of stack: \n" << mstackStr.top() << std::endl;
		std::cout << std::endl;
		mstackStr.pop();
		std::cout << "*pop*\n" << std::endl;
		std::cout << "size after popping: " << mstackStr.size() << std::endl;
		std::cout << "current content of the stack:" << std::endl;
		MutantStack<std::string>::iterator itStr2 = mstackStr.begin();
		MutantStack<std::string>::iterator iteStr2 = mstackStr.end();
		while (itStr2 != iteStr2)
		{
			std::cout << *itStr2 << std::endl;
			++itStr2;
		}
		std::cout << std::endl;
		std::cout << "pushing two more strings to stack..." << std::endl;
		mstackStr.push("C++");
		mstackStr.push("MutantStack");
		std::cout << std::endl;
		MutantStack<std::string>::iterator itStr = mstackStr.begin();
		MutantStack<std::string>::iterator iteStr = mstackStr.end();
		std::cout << "Content of the current stack:" << std::endl;
		while (itStr != iteStr)
		{
			std::cout << *itStr << std::endl;
			++itStr;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
