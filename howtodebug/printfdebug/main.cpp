#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 3, 8, 2, 5, 6, 9, 4, 1, 7 };
    auto size = v.size();

    // 洗濯ソートで vector の要素をソートする
    for (std::size_t head = 0; head != size; ++head)
    {
        // printf debug 1 : 各ステップにおける vector の要素を表示
        std::cerr << "debug head = " << head << ", v = { ";
        for (std::size_t i = 0; i != size; ++i)
        {
            std::cerr << v.at(i) << " ";
        }
        std::cerr << "}\n";
        // printf debug 1

        auto min = head;
        for (std::size_t index = head + 1; index != size; ++index)
        {
            // printf debug 2 : 未ソート領域の要素を表示
            std::cerr << v.at(index) << ", ";
            // printf debug 2

            if (v.at(index) < v.at(min))
            {
                // printf debug 3 : 大小比較のチェック
                std::cerr << v.at(index) << " < " << v.at(min) << "\n";
                // printf debug 3

                min = index;
            }
            // printf debug 3
            else
            {
                std::cerr << v.at(index) << " >= " << v.at(min) << "\n";
            }
            // printf debug 3
        }
        // printf debug 2
        std::cerr << "\n";
        // printf debug 2

        // printf debug 4 : 走査後の最小値のチェック
        std::cerr << "v.at(min) = " << v.at(min) << "\n";
        // printf debug 4

        // printf debug 5 : 要素の交換前後の値をチェック
        std::cerr << "debug befor: " << v.at(head) << ", " << v.at(min) << "\n";
        // printf debug 5

        auto temp = v.at(head);
        v.at(head) = v.at(min);
        v.at(min) = v.at(head); // わざと間違えている
        // 正しくは下記の通り
        // v.at(min) = temp;

        // printf debug 5
        std::cerr << "debug after: " << v.at(head) << ", " << v.at(min) << "\n";
        // printf debug 5
    }

    // 出力
    for (std::size_t i = 0; i != size; ++i)
    {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
