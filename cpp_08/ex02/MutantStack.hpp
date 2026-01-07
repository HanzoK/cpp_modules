#pragma once

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> 
{
private:
public:
	MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &copy);
	~MutantStack();

    typedef typename Container::iterator iterator;
	iterator begin()
	{ 
		return this->c.begin(); 
	}
	iterator end()
	{ 
		return this->c.end(); 
	}

    typedef typename Container::const_iterator const_iterator;
	const_iterator begin() const 
	{ 
		return this->c.begin(); 
	}
	const_iterator end()   const 
	{ 
		return this->c.end(); 
	}

    typedef typename Container::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() 
	{ 
		return this->c.rbegin(); 
	}
	reverse_iterator rend()   
	{ 
		return this->c.rend(); 
	}

    typedef typename Container::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const 
	{ 
		return this->c.rbegin(); 
	}
	const_reverse_iterator rend()   const 
	{ 
		return this->c.rend(); 
	}
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {}	

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &copy) {
	if (this != &copy) {
		std::stack<T, Container>::operator=(copy);
	}
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}
