#include <iterator>

namespace diystd
{
    template <typename T, std::size_t N>
    struct array
    {
        using value_type = T;
        using reference = T&;

        using size_type = std::size_t;

        value_type strage[N];

        reference operator [] (size_type i)
        {
            return strage[i];
        }

        size_type size()
        {
            return N;
        }
    };
}