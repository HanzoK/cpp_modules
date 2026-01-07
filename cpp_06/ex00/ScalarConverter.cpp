#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

static void printFromInt(long number) 
{
    int i = static_cast<int>(number);
    char c;
    float f = 0.0;
    double d = 0.0;

    if (number > static_cast<long>(INT_MAX) ||  number < static_cast<long>(INT_MIN))
	{
        std::cout << "char: " << IMP << std::endl;
		std::cout << "int: " << IMP << std::endl;
		std::cout << "float: " << IMP << std::endl;
		std::cout << "double: " << IMP << std::endl;
	}
    else 
	{
        // for chars
        if (i < 0 || i > 127)
            std::cout << "char: " << IMP << std::endl;
        else if (!std::isprint(i)) 
            std::cout << "char: " << N << std::endl;
        else 
		{
            c = static_cast<char>(i);
            std::cout << "char: '" << c << "'" << std::endl;
        }

		// for ints
		std::cout << "int :" << i << std::endl;

        // for flaots
        f = static_cast<float>(i);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;

        // for doubles
        d = static_cast<double>(i);
        std::cout << "double: " << d << std::endl;
    }
}

static void printFromDouble(double d) 
{
	int i = 0;
	char c;

	if (d > static_cast<double>(INT_MAX) ||
        d < static_cast<double>(INT_MIN))
	{
		std::cout << "char: " << IMP << std::endl;
        std::cout << "int: " << IMP << std::endl;
        std::cout << "float: " << IMP << std::endl;
        std::cout << "double: " << IMP << std::endl;
		return ;
    } 
	else 
	{
        i = static_cast<int>(d);

        if (i < 0 || i > 127)
            std::cout << "char: " << IMP << std::endl;
        else if (!std::isprint(i))
            std::cout << "char: " << N << std::endl;
        else 
		{
            c = static_cast<char>(i);
            std::cout << "char: '" << c << "'" << std::endl;
        }
		std::cout << "int: " << i << std::endl;
    }

    // FLOAT
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;

    // DOUBLE
    std::cout << "double: " << d << std::endl;
}

static void printFromFloat(float f) 
{
	int i = 0;

	if (f > static_cast<float>(INT_MAX) ||
        f < static_cast<float>(INT_MIN) ||
        f != f) 
	{
		std::cout << "char: " << IMP << std::endl;
        std::cout << "int: " << IMP << std::endl;
    } 
	else 
	{
        i = static_cast<int>(f);

        if (i < 0 || i > 127) 
            std::cout << "char: " << IMP << std::endl;
        else if (!std::isprint(i)) 
            std::cout << "char: " << N << std::endl;
        else 
		{
            char c = static_cast<char>(i);
            std::cout << "char: '" << c << "'" << std::endl;
        }
		std::cout << "int: " << i << std::endl;
    }

    // FLOAT
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;

    // DOUBLE
    double d = static_cast<double>(f);
    std::cout << "double: " << d << std::endl;
}

static void printFromChar(char c)
{
	int i = 0;
	float f = 0.0;
	double d = 0.00;

    i = static_cast<int>(c);

	std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;

    d = static_cast<double>(c);
    f = static_cast<float>(c);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
}

// ---------------------------------------------
//  toInt / toChar / toDouble / toFloat / isString / inputCheck
// ---------------------------------------------

static void toInt(const std::string &input) 
{

	long value;
    std::stringstream ss(input);

    ss >> value;
    if (ss.fail() || !ss.eof()) 
	{
		std::cout << "char: " << IMP << std::endl;
        std::cout << "int: " << IMP << std::endl;
        std::cout << "float: " << IMP << std::endl;
        std::cout << "double: " << IMP << std::endl;
        return;
    }
    printFromInt(value);
}

static void toChar(const std::string &input) 
{

	char c;
	float f = 0.0;
	double d = 0.00;

    if (input.size() != 1) 
	{
		std::cout << "char: " << IMP << std::endl;
        std::cout << "int: " << IMP << std::endl;
        std::cout << "float: " << IMP << std::endl;
        std::cout << "double: " << IMP << std::endl;
        return;
    }
    c = input[0];
    if (!std::isprint(static_cast<unsigned char>(c))) {
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "char: " << N << std::endl;
        d = static_cast<double>(c);
        f = static_cast<float>(c);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        return;
    }
    printFromChar(c);
}

static void toDouble(const std::string &input) 
{

	double d = 0.00;
    std::stringstream ss(input);

    ss >> d;
    if (ss.fail() || !ss.eof()) 
	{
		std::cout << "char: " << IMP << std::endl;
        std::cout << "int: " << IMP << std::endl;
        std::cout << "float: " << IMP << std::endl;
        std::cout << "double: " << IMP << std::endl;
        return;
    }
    printFromDouble(d);
}

static void printFromPseudo(const std::string &s) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (s == "nan" || s == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (s == "+inf" || s == "inf" || s == "+inff" || s == "inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (s == "-inf" || s == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

static void toFloat(const std::string &input) 
{

    std::string core = input;
	if (core.size() > 0 && core[core.size() - 1] == 'f')
		core.erase(core.size() - 1);

	float f;
    std::stringstream ss(core);

    ss >> f;
    if (ss.fail() || !ss.eof()) 
	{
		std::cout << "char: " << IMP << std::endl;
		std::cout << "int: " << IMP << std::endl;
        std::cout << "float: " << IMP << std::endl;
        std::cout << "double: " << IMP << std::endl;
        return;
    }
    printFromFloat(f);
}


static void isString(const std::string &input) 
{
	(void)input;
		std::cout << "char: " << IMP << std::endl;
        std::cout << "int: " << IMP << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
}

static bool isPseudo(const std::string &s) 
{
	if (s == "nan"  || s == "nanf" ||
          s == "+inf" || s == "-inf" || s == "inf" ||
          s == "+inff"|| s == "-inff"|| s == "inff")
		return true;
	else
	 	return false;
}

/*
 * inputCheck:
 *  1 = int
 *  2 = char
 *  3 = double
 *  4 = float
 *  5 = string/other input
 */
static int inputCheck(const std::string &input) 
{
    if (input.empty())
        return 5;

    if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
        return 1;

    std::size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        ++i;

    bool hasDigit = false;
    bool hasDot	= false;
    bool hasF	= false;
	char c	= input[i];

    for (; i < input.size(); ++i) 
	{
        c = input[i];
		if (std::isdigit(static_cast<unsigned char>(c))) 
            hasDigit = true;
		else if (c == '.') 
		{
            if (hasDot) 
				return 5;
            hasDot = true;
        } 
		else if (c == 'f' && i == input.size() - 1) 
            hasF = true;
		else
        	return 5;
    }

    if (!hasDigit)
        return 5;

    if (!hasDot && !hasF)
        return 2; // int
    if (hasDot && !hasF)
        return 3; // double
    if (hasDot && hasF)
        return 4; // float
    return 5;
}

void ScalarConverter::convert(const std::string &input) {
    std::cout << "----------THE CONVERTER----------" << std::endl;
    std::cout << std::endl;

	if (isPseudo(input)) {
        printFromPseudo(input);
        return;
    }

    int flag = inputCheck(input);

    switch (flag) 
	{
        case 1: // char
            toChar(input);
            break;
        case 2: // int
            toInt(input);
            break;
        case 3: // double
            toDouble(input);
            break;
        case 4: // float
            toFloat(input);
            break;
        case 5:
            isString(input);
            break;
    }
}
