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
    // 注意: std::cin で文字列を読み込んだ場合
    // a, b, c, ... のようにスペースが入るケースに対処できないので、
    // std::getline を用いている
    
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::string str;
    // 改行文字が表れるまで1行全て文字列として入力したい場合は、
    // std::getline 関数を用いる
    std::getline(std::cin, str);

    std::vector<std::string> res;
    std::replace(str.begin(), str.end(), ',', ' ');

    size_t idx = 0;
    while (idx < str.size())
    {
        while (str[idx] == ' ')
        {
            ++idx;
            if (idx >= str.size())
                break;
        }
        size_t nextidx = str.find(' ', idx);
        if (nextidx == str.npos)
        {
            std::string sub = str.substr(idx, str.size() - idx + 1);
            res.push_back(sub);
        }
        else
        {
            std::string sub = str.substr(idx, nextidx - idx);
            res.push_back(sub);
        }
        idx = nextidx;
    }

    // 値を出力して確認する
    for (auto& s : res)
    {
        std::cout << s << '\n';
    }
    return 0;
}
