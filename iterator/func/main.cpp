#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std::string_literals;

int main()
{
    auto output_all = [](auto first, auto last)
    {
        for (auto iter = first; iter != last; ++iter)
        {
            std::cout << *iter << "\n"s;
        }
    };
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    output_all(std::begin(v), std::end(v));

    std::istream_iterator<int> first(std::cin), last;
    output_all(first, last);

    return 0;
}
