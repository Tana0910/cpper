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
    std::cout << "ref_xvalue = "s << ref_xvalue << std::endl;

    const int& const_ref = xvalue;
    // ++const_ref; // コンパイルエラー
    std::cout << "const_ref = "s << const_ref << std::endl;

    a = 0;
    const int& b = a;
    int const& c = a;
    std::cout << b << ", "s << c << std::endl;

    // int& const d = a; // コンパイルエラー

    const int const_x = 90;
    // int& ref_const_x_err = const_x; // コンパイルエラー
    const int& ref_const_x_ok = const_x;
    std::cout << "ref_const_x_ok ="s << ref_const_x_ok << std::endl;

    auto vecfunc0 = [](std::vector<int> v)
    {
        std::cout << v.at(1234) << std::endl;
    };

    std::vector<int> vec(10000, -1);
    vecfunc0(vec); // vecがコピーされてしまうので非効率

    auto vecfunc1 = [](std::vector<int>& v)
    {
        std::cout << v.at(1234) << std::endl;
    };
    vecfunc1(vec); // vec のリファレンスを渡すので、コピーせずに済む。
    // しかし、関数内で値を変更してしまうと、その変更が呼び出し元にも反映されてしまう。

    // 引数の値を変更しないことを保証するためには、
    // const な lvalue リファレンスを用いればよい
    auto vecfunc2 = [](const std::vector<int>& v)
    {
        std::cout << v.at(1234) << std::endl;
    };
    vecfunc2(vec);
    return 0;
}
