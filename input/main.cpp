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
    // a,b,c... は読み込むことができるが、
    // a, b, c, ... のようにスペースが入ると
    // 先頭の文字しか受け取れないので修正する
    
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::string str;
    // 改行文字が表れるまで1行全て文字列として入力したい場合は、
    // std::getline 関数を用いる
    std::getline(std::cin, str);
    // std::cout << "str:\"" << str << "\"\n";
    std::vector<std::string> res;
    std::replace(str.begin(), str.end(), ',', ' ');
    // auto itr = str.begin();
    size_t idx = 0;
    while (idx < str.size())
    {
        while (str[idx] == ' ')
        {
            // std::cout << "idx incremented.\n";
            ++idx;
            if (idx >= str.size())
                break;
        }
        size_t nextidx = str.find(' ', idx);
        if (nextidx == str.npos)
        {
            std::string sub = str.substr(idx, str.size() - idx + 1);
            // std::cout << "last idx=" << idx << std::endl;
            // std::cout << sub << std::endl;
            res.push_back(sub);
        }
        else
        {
            std::string sub = str.substr(idx, nextidx - idx);
            // std::cout << "idx= " << idx << std::endl;
            // std::cout << sub << std::endl;
            res.push_back(sub);
        }
        idx = nextidx;
    }
    // std::stringstream buf(str);
    // while (!buf.eof())
    // {
    //     std::string s;
    //     buf >> s;
    //     res.push_back(s);
    // }
    // std::cout << res.size() << std::endl;
    for (auto& s : res)
    {
        std::cout << s << '\n';
    }
    return 0;
}

