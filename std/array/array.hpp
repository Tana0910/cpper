#include <iterator>

namespace diystd
{
    template <typename T, std::size_t N>
    struct array
    {
        using value_type = T;

        using reference = T&;
        using const_reference = const T&;

        using size_type = std::size_t;

        value_type strage[N];

        reference operator [] (size_type i)
        {
            return strage[i];
        }

        const_reference operator [] (size_type i) const
        {
            return strage[i];
        }

        size_type size() const
        {
            return N;
        }
    };
}