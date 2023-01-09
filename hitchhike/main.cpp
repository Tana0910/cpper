// オプション -include を用いて、コンパイル時にインクルードする
// g++ -include all.h -o program main.cpp

int main()
{
    // s リテラルを付けて string 型のオブジェクトを構築する(仕様: N3642)
    // https://cpprefjp.github.io/reference/string/basic_string/op_s.html
    std::cout << "Hello"s << std::endl;
    return 0;
}
