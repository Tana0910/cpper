#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

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

    auto twice = [](auto& value){ value = 2 * value; };
    for_each(std::begin(vec), std::end(vec), twice);
    for_each(std::begin(vec), std::end(vec), [](auto value){ std::cout << value << " "s; });
    std::cout << std::endl;

    // [first, last) 間において、全ての要素が条件 pred を満たす場合 true、
    // そうでない場合 false
    // 空の場合は true
    auto all_of = [](auto first, auto last, auto pred)
    {
        for (auto itr = first; itr != last; ++itr)
        {
            if (!pred(*itr)) return false;
        }
        return true;
    };

    std::vector<int> vec_a = { 10, 0, 44, 152, 8 };
    std::vector<int> vec_b = { 8, 4, 22, 3, 98 };

    bool iseven_a = all_of(vec_a.begin(), vec_a.end(), [](auto value){ return value % 2 == 0; });
    bool iseven_b = all_of(vec_b.begin(), vec_b.end(), [](auto value){ return value % 2 == 0; });
    std::cout << std::boolalpha << iseven_a << ", "s << iseven_b << std::endl;

    // STLライブラリ
    iseven_a = std::all_of(vec_a.begin(), vec_a.end(), [](auto value){ return value % 2 == 0; });
    iseven_b = std::all_of(vec_b.begin(), vec_b.end(), [](auto value){ return value % 2 == 0; });
    std::cout << std::boolalpha << iseven_a << ", "s << iseven_b << std::endl;

    // [first, last) 間において、いずれかの要素が pred を満たす場合 true、
    // そうでない場合 false
    // 空の場合は false
    auto any_of = [](auto first, auto last, auto pred)
    {
        for (auto itr = first; itr != last; ++itr)
        {
            if(pred(*itr)) return true;
        }
        return false;
    };

    iseven_a = any_of(vec_a.begin(), vec_a.end(), [](auto value){ return value % 2 != 0; });
    iseven_b = any_of(vec_b.begin(), vec_b.end(), [](auto value){ return value % 2 != 0; });
    std::cout << std::boolalpha << iseven_a << ", "s << iseven_b << std::endl;

    iseven_a = std::any_of(vec_a.begin(), vec_a.end(), [](auto value){ return value % 2 != 0; });
    iseven_b = std::any_of(vec_b.begin(), vec_b.end(), [](auto value){ return value % 2 != 0; });
    std::cout << std::boolalpha << iseven_a << ", "s << iseven_b << std::endl;

    // [first, last) 間において、全ての要素が pred を満たさない場合 true、
    // そうでない場合 false
    // 空の場合は true
    auto none_of = [](auto first, auto last, auto pred)
    {
        for (auto itr = first; itr != last; ++itr)
        {
            if (pred(*itr)) return false;
        }
        return true;
    };

    iseven_a = none_of(vec_a.begin(), vec_a.end(), [](auto value){ return value % 2 != 0; });
    iseven_b = none_of(vec_b.begin(), vec_b.end(), [](auto value){ return value % 2 != 0; });
    std::cout << std::boolalpha << iseven_a << ", "s << iseven_b << std::endl;

    iseven_a = std::none_of(vec_a.begin(), vec_a.end(), [](auto value){ return value % 2 != 0; });
    iseven_b = std::none_of(vec_b.begin(), vec_b.end(), [](auto value){ return value % 2 != 0; });
    std::cout << std::boolalpha << iseven_a << ", "s << iseven_b << std::endl;


    auto find = [](auto first, auto last, const auto& value)
    {
        for (auto itr = first; itr != last; ++itr)
        {
            if (*itr == value)
            {
                return itr;
            }
        }
        return last;
    };

    auto pos = find(vec_a.begin(), vec_a.end(), 8);
    if (pos != vec_a.end())
    {
        std::cout << "Found."s << std::endl;
    }
    else
    {
        std::cout << "Found."s << std::endl;
    }
    return 0;
}
