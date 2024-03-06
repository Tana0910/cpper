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

struct jsonToken
{
    std::string objectType;
};

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
    size_t lastpos = 0;
    while (curpos < json.size())
    {
        // debug current position
        // std::cout << "curpos = " << curpos << std::endl;

        switch (json[curpos])
        {
        case leftcb:
            std::cout << leftcb << std::endl;
            break;
        case rightcb:
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
        // next pos
        ++curpos;
    }
    return 0;

}
