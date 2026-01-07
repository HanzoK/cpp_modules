#include "Span.hpp"

int main() {
    try {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan()  << std::endl;

        // ==============  BIG TEST ================

        std::cout << "\n======= BIG TEST (10000 NUMS) =======\n";
        const unsigned int N = 10000;

        Span big(N);

        std::vector<int> buffer;
        buffer.reserve(N);
        for (unsigned int i = 0; i < N; ++i)
            buffer.push_back(i);

        big.addNumber(buffer.begin(), buffer.end());

        std::cout << "size: " << big.size() << std::endl;
        std::cout << "shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "longest span : " << big.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
