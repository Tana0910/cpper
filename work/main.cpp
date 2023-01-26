// オプション -include を用いて、コンパイル時にインクルードする
// g++ -include all.h -o program main.cpp
#ifndef CMPEXCLUDE // コンパイル時には含めないが、エディタでの補完の為用いている
#include "all.h"
#endif

// 試したいコードを気軽に書いていく

// https://faithandbrave.hateblo.jp/entry/2014/05/01/171631 より

std::vector<std::string> split(const std::string& input, char delimiter)
{
    std::stringstream stream(input);
    std::string field;
    std::vector<std::string> res;
    while (std::getline(stream, field, delimiter))
    {
        res.push_back(field);
    }
    return res;
}

int main()
{
    const std::string input1 = "aaa,bbb,ccc";
    std::cout << "Input 1 :" << input1 << std::endl;
    for (auto& s : split(input1, ','))
    {
        std::cout << s << std::endl;
    }
    
    const std::string input2 = "aaa, bbb, ccc";
    std::cout << "Input 2 :" << input2 << std::endl;
    for (auto& s : split(input2, ','))
    {
        std::cout << s << std::endl;
    }
    return 0;
}
