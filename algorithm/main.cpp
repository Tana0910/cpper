#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std::string_literals;

int main()
{
    // [first, last) を順番にループし、関数 f をループ内で実行する
    auto for_each = [](auto first, auto last, auto f)
    {
        for (auto itr = first; itr != last; ++itr)
        {
            f(*itr);
        }
    };

    std::vector<int> vec = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
    for_each(std::begin(vec), std::end(vec), [](auto value){ std::cout << value << " "s; });
    std::cout << std::endl;
    
    return 0;
}
