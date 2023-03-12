#include "array.hpp"

#include <iostream>
#include <string>
using namespace std::string_literals;

template <class TArray>
void print(const TArray& a)
{
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i];
    }
    std::cout << std::endl;
}

int main()
{
    using array_type = diystd::array<int, 5>;
    array_type a = { 1, 2, 3, 4, 5};
    array_type::value_type x = 0;
    array_type::reference ref = a[0];
    std::cout << x << ref << std::endl;
    std::cout << "a.size() = "s << a.size() << std::endl;
    print(a);
    return 0;
}
