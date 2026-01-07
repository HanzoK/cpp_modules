#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

void printData(const char* label, const Data* d) {
    std::cout << label << " data@" << d
              << " { id=" << d->id
              << ", name=\"" << d->name
              << "\", score=" << d->score
              << ", active=" << (d->active ? "true" : "false")
              << " }\n";
}

int main() {
    Data original;
    original.id = 42;
    original.name = "Hanji";
    original.score = 99.5;
    original.active = true;

	// Data copy;
	// copy.id = 69;
	// copy.name = "Hanju";
	// copy.score = 100;
	// copy.active = false;

    printData("Original:", &original);

    uintptr_t data_raw = Serializer::serialize(&original);
    Data* conversion = Serializer::deserialize(data_raw);
	uintptr_t conversion_raw = Serializer::serialize(conversion);

	std::cout << std::endl;

    printData("Conversion:", conversion);

	std::cout << std::endl;

    std::cout << "Data uintptr_t value: " << data_raw << std::endl;
    std::cout << "Conversion uintptr_t value: " << conversion_raw << std::endl;

	std::cout << std::endl;

    std::cout << "pointers equal? " << std::endl;
	if (conversion == &original) 
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

	std::cout << std::endl;

    printData("Conversion:", conversion);

	std::cout << std::endl;
	std::cout << "changing score to 100" << std::endl;
    conversion->score = 100.0;
    printData("after modifying:", &original);

    return 0;
}
