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
        std::cout << "Not Found."s << std::endl;
    }

    pos = find(vec_a.begin(), vec_a.end(), 111);
    if (pos != vec_a.end())
    {
        std::cout << "Found."s << std::endl;
    }
    else
    {
        std::cout << "Not Found."s << std::endl;
    }

    auto find_if = [](auto first, auto last, auto pred)
    {
        for (auto itr = first; itr != last; ++itr)
        {
            if (pred(*itr)) return itr;
        }
        return last;
    };

    vec.clear();
    vec = { 3, 77, 5, 2, 90, 91 };

    auto is_even = [](auto value)
    {
        return value % 2 == 0;
    };

    auto is_odd = [](auto value)
    {
        return value % 2 == 1;
    };

    auto itr_even = find_if(vec.begin(), vec.end(), is_even);
    auto itr_odd = find_if(vec.begin(), vec.end(), is_odd);
    std::cout << *(itr_even) << " "s << *(itr_odd) << std::endl;

    int expected = 77;

    auto iseq = [&](auto elem)
    {
        return expected == elem;
    };

    auto itr_expected = find_if(vec.begin(), vec.end(), iseq);
    if (itr_expected != vec.end())
    {
        std::cout << "Found "s << *(itr_expected) << "."s << std::endl;
    }
    else
    {
        std::cout << "Not found."s << std::endl;
    }

    auto count = [](auto first, auto last, auto value)
    {
        auto ret = 0u;
        for (auto itr = first; itr != last; ++itr)
        {
            if (*itr == value)
                ++ret;
        }
        return ret;
    };

    vec.clear();
    vec = { 1, 10, 22, 1, 22, 22};
    std::cout << count(vec.begin(), vec.end(), 1) << std::endl;
    std::cout << count(vec.begin(), vec.end(), 10) << std::endl;
    std::cout << count(vec.begin(), vec.end(), 22) << std::endl;
    std::cout << count(vec.begin(), vec.end(), 5) << std::endl;

    auto count_if = [](auto first, auto last, auto pred)
    {
        auto ret = 0u;
        for (auto itr = first; itr != last; ++itr)
        {
            if (pred(*itr)) ++ret;
        }
        return ret;
    };

    std::cout << count_if(vec.begin(), vec.end(), [](auto e){ return e % 2 == 1; }) << std::endl;
    std::cout << count_if(vec.begin(), vec.end(), [](auto e){ return e % 2 == 0; }) << std::endl;

    auto distance = [](auto first, auto last)
    {
        return last - first;
    };

    auto d = distance(vec.begin(), vec.end());
    auto d_from_next = distance(vec.begin() + 1, vec.end());

    std::cout << d << std::endl;
    std::cout << d_from_next << std::endl;

    auto equal = [&](auto first1, auto last1, auto first2, auto last2)
    {
        if (distance(first1, last1) != distance(first2, last2))
            return false;

        for (auto i = first1, j = first2; i != last1; ++i, ++j)
        {
            if (*i != *j)
                return false;
        }
        return true;
    };

    vec_a.clear();
    vec_b.clear();

    vec_a = { 1, 2, 3, 4, 5 };
    vec_b = { 1, 2, 3, 4, 5 };

    std::vector<int> vec_c = { 1, 2, 3, 5, 4 };

    std::cout << equal(vec_a.begin(), vec_a.end(), vec_b.begin(), vec_b.end()) << std::endl;
    std::cout << equal(vec_a.begin(), vec_a.end(), vec_c.begin(), vec_c.end()) << std::endl;

    auto equal_comp = [&](auto first1, auto last1, auto first2, auto last2, auto comp)
    {
        if (distance(first1, last1) != distance(first2, last2))
            return false;

        for (auto i = first1, j = first2; i != last1; ++i, ++j)
        {
            if (!comp(*i, *j))
                return false;
        }
        return true;
    };

    std::vector<double> vec_fpn_a = { 1.23, 6.54, 7.89 };
    std::vector<double> vec_fpn_b = { 1.23, 6.54, 7.90 };
    std::vector<double> vec_fpn_c = { 1.23, 6.54, 7.89 };

    auto eq_fpn = [](double x, double y){ return std::abs(x - y) < 0.0001; };

    std::cout << equal_comp(vec_fpn_a.begin(), vec_fpn_a.end(), vec_fpn_b.begin(), vec_fpn_b.end(), eq_fpn) << std::endl;
    std::cout << equal_comp(vec_fpn_a.begin(), vec_fpn_a.end(), vec_fpn_c.begin(), vec_fpn_c.end(), eq_fpn) << std::endl;
    return 0;
}
