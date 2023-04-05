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

    int& ref_front = a.front();
    int& ref_back = a.back();

    std::cout << ref_front << " " << ref_back << std::endl;

    a.fill(0);
    print(a);

    a = { 1, 2, 3, 4, 5 };
    auto itr = a.begin();
    std::cout << *itr << std::endl;
    ++itr;
    std::cout << *itr << std::endl;
    auto itr_tail = a.end();
    --itr_tail;
    std::cout<< *itr_tail << std::endl;

    std::cout << *(itr++) << std::endl;
    std::cout << *itr << std::endl;

    std::cout << *(itr_tail--) << std::endl;
    std::cout << *itr_tail << std::endl;

    auto itr_l = a.begin();
    auto itr_r = a.begin();
    bool iseq1 = (itr_l == itr_r);
    bool iseq2 = (itr_l != itr_r);
    std::cout << std::boolalpha << iseq1 << " " << iseq2 << std::endl;
    ++itr_l;
    iseq1 = (itr_l == itr_r);
    iseq2 = (itr_l != itr_r);
    std::cout << iseq1 << " " << iseq2 << std::endl;

    return 0;
}
