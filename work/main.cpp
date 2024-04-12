// オプション -include を用いて、コンパイル時にインクルードする
// g++ -include all.h -o program main.cpp
#ifndef CMPEXCLUDE // コンパイル時には含めないが、エディタでの補完の為用いている
#include "all.h"
#endif

// 試したいコードを気軽に書いていく

// left curly blacket
const char leftcb = '{'; 

// right curly blacket
const char rightcb = '}';

const char dquat = '\"';

const char colon = ':';

const char comma = ',';

enum class TokenType : int
{
    Illegal = -1, Leftcb = 0, Rightcb, Dquat, Colon, Commma, Key, Value
};

enum class JsonValueType : int
{
    Undefined = -1,
    NullType = 0, 
    Boolean, Object, Array, Number, String
};

bool ReadChar(const std::string& source, size_t& pos, char& ch)
{
    if (pos >= source.size())
    {
        return false;
    }
    ch = source[pos];
    ++pos;
    return true;
}



// JSON パーサー
int main()
{
    std::string json = R"({
  "Image": {
    "Width": 800,
    "Height": 600
  }
})";

    // input debug
    std::cout << json << std::endl;

    // read json string
    size_t curpos = 0;
    size_t count_bracket = 0;
    char ch;
    while (ReadChar(json, curpos, ch))
    {
        // debug current position
        // std::cout << "curpos = " << curpos << std::endl;
        switch (ch)
        {
        case leftcb:
            ++count_bracket;
            std::cout << leftcb << std::endl;
            break;
        case rightcb:
            --count_bracket;
            std::cout << rightcb << std::endl;
            break;
        case dquat:
            std::cout << dquat << std::endl;
            break;
        case colon:
            std::cout << colon << std::endl;
            break;
        case comma:
            std::cout << comma << std::endl;
            break;
        default:
            break;
        }
    }
    return 0;

}
