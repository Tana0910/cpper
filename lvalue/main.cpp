#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std::string_literals;

int main()
{
    int a = 1;
    int& ref = a;
    ref = 3;

    std::cout << "a = "s << a << std::endl; // 3
    std::cout << "ref = "s << ref << std::endl; // 3

    return 0;
}
