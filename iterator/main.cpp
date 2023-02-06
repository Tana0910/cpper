#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    auto i = std::begin(v);
    int x = *i; // v[0](= 1)
    std::cout << x << std::endl; // 1
    *i = 0;
    std::cout << v.at(0) << std::endl; // 0
    ++i;
    std::cout << *i << std::endl; // 2
    --i;
    std::cout << *i << std::endl; // 0

    // イテレータの比較

    auto itrx = std::begin(v);
    auto itry = itrx;
    std::cout << std::boolalpha << (itrx == itry) << std::endl;
    std::cout << (itrx != itry) << std::endl;

    ++itrx;

    std::cout << (itrx == itry) << std::endl;

    // 最後の次の要素

    std::vector<int> v1 = { 10, 20, 30 };
    auto itr_x = std::begin(v1);
    auto itr_y = std::end(v1);
    std::cout << (itr_x == itr_y) <<std::endl;
    ++itr_x;
    std::cout << (itr_x == itr_y) <<std::endl;
    ++itr_x;
    std::cout << (itr_x == itr_y) <<std::endl;
    ++itr_x;
    std::cout << (itr_x == itr_y) <<std::endl;

    return 0;
}
