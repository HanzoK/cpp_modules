#pragma once

#include <stdint.h> // uintptr_t in C++98
#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);

private:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();
};
