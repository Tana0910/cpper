#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    auto i = std::begin(v);
    int x = *i; // v[0](= 1)
    std::cout << x << std::endl;
    *i = 0;
    std::cout << v.at(0) << std::endl; // 0
    return 0;
}
