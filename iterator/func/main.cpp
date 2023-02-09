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

    auto output_all_iter = [](auto first, auto last, auto output_iter)
    {
        for (auto iter = first; iter != last; ++iter, ++output_iter)
        {
            *output_iter = *iter;
        }
    };

    output_all_iter(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout));

    std::cout << "\n"s;

    std::vector<int> destination(5);
    output_all_iter(std::begin(v), std::end(v), std::begin(destination));

    std::cout << "{ "s;
    for (auto iter = std::begin(destination); iter != std::end(destination); ++iter)
    {
        std::cout << *iter << " "s;
    }
    std::cout << "}\n"s;

    return 0;
}
