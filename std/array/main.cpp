#include "array.hpp"

#include <iostream>
#include <string>
using namespace std::string_literals;

int main()
{
    using array_type = diystd::array<int, 5>;
    array_type a = { 1, 2, 3, 4, 5};
    array_type::value_type x = 0;
    array_type::reference ref = a[0];
    std::cout << x << ref << std::endl;
    std::cout << "a.size() = "s << a.size() << std::endl;
    return 0;
}
