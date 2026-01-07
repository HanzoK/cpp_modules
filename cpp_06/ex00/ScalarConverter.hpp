#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>

#define N "Non displayable"
#define IMP "Impossible"


class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();

    public:
        static void convert(const std::string &input);
};
