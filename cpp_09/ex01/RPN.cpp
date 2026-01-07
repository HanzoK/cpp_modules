#include "RPN.hpp"
#include <list>
#include <stdexcept>
#include <limits>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
    (void)copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    (void)copy;
    return *this;
}

RPN::~RPN() {}

bool RPN::isDigit(char c) const
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

bool RPN::isOperator(char c) const
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

int RPN::evaluate(const std::string &input)
{
    if (input.empty())
        throw std::runtime_error("Empty expression");

    std::list<long> values;

    for (std::size_t i = 0; i < input.size(); ++i)
    {
        char c = input[i];

        if (std::isspace(static_cast<unsigned char>(c)))
            continue;

        if (i + 1 < input.size() && !std::isspace(static_cast<unsigned char>(input[i + 1])))
            throw std::runtime_error("digits must be single characters separated by spaces");

        if (isDigit(c))
        {
            long value = static_cast<long>(c - '0');
            values.push_back(value);
        }
        else if (isOperator(c))
        {
            if (values.size() < 2)
                throw std::runtime_error("Not enough operators for numbers");

            long right = values.back();
            values.pop_back();
            long left = values.back();
            values.pop_back();

            long result = 0;

            switch (c)
            {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    if (right == 0)
                        throw std::runtime_error("Division by zero");
                    result = left / right;
                    break;
                default:
                    throw std::runtime_error("unknown expression encountered UwU");
            }
            if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
            {
                throw std::runtime_error("int overflow");
            }
            values.push_back(result);
        }
        else
            throw std::runtime_error("Invalid character");
    }
    if (values.size() != 1)
        throw std::runtime_error("input expression is invalid");

    long finalResult = values.back();

    if (finalResult > std::numeric_limits<int>::max() 
		|| finalResult < std::numeric_limits<int>::min())
        throw std::runtime_error("int overflow");

    return static_cast<int>(finalResult);
}
