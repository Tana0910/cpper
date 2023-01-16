// build command
// g++ -std=c++17 -Wall --pedantic-erro main.cpp -o program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    // カンマ区切り毎に文字列を取得する
    // 数値の個数は任意

    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::cin >> str;
    std::vector<std::string> res;
    std::replace(str.begin(), str.end(), ',', ' ');
    std::stringstream buf(str);
    while (!buf.eof())
    {
        std::string s;
        buf >> s;
        res.push_back(s);
    }
    for (auto& str : res)
    {
        std::cout << str << std::endl;
    }
    return 0;
}

