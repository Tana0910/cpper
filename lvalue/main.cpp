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

    std::cout << "a = "s << a << std::endl; // a = 3
    std::cout << "ref = "s << ref << std::endl; // ref = 3

    // lvalue リファレンスは必ず初期化しなければならない
    // int& ref_err; // コンパイルエラー

    auto assign_incorrect = [](int x)
    {
        x = 5;
    };

    a = 0;
    assign_incorrect(a);
    std::cout << "a = "s << a <<  std::endl; // a = 0;

    auto assign_correct = [](int& x)
    {
        x = 5;
    };

    a = 0;
    assign_correct(a);
    std::cout << "a = "s << a << std::endl; // a = 5

    auto swap_incorrect = [](auto a, auto b)
    {
        auto temp = a;
        a = b;
        b = temp;
    };
    int x = 10, y = 20;
    swap_incorrect(x, y);
    std::cout << "(x, y) = ("s << x << ", "s << y << ")" << std::endl;

    auto swap_correct = [](auto& a, auto& b)
    {
        auto temp = a;
        a = b;
        b = temp;
    };
    int z = 123, w = 456;
    swap_correct(z, w);
    std::cout << "(z, w) = ("s << z << ", "s << w << ")" << std::endl;

    z = 1234, w = 5678;
    std::swap(z, w);
    std::cout << "(z, w) = ("s << z << ", "s << w << ")" << std::endl;

    const int xc = 0;
    // xc = 100; // 変更できないのでコンパイルエラー
    std::cout << xc << std::endl;

    int const yc = 0; // const int yc = 0; と同じ
    std::cout << yc << std::endl;

    int xvalue = 1000;
    int& ref_xvalue = xvalue;
    ++ref_xvalue;

    const int& const_ref = xvalue;
    // ++const_ref; // コンパイルエラー

    return 0;
}
