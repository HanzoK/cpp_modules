#pragma once

#include <string>

class RPN
{
private:
	bool isDigit(char c) const;
	bool isOperator(char c) const;

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &input);

};
