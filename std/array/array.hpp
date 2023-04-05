#include <iterator>

namespace diystd
{
    // イテレーターを表現するクラス
    template <typename Array>
    struct array_iterator
    {
        Array& a;
        std::size_t idx;

        array_iterator(Array& ar, std::size_t i) : a(ar), idx(i) {}

        typename Array::reference operator * ()
        {
            return a[idx];
        }

        array_iterator& operator ++()
        {
            ++idx;
            return *this;
        }

        array_iterator operator ++(int)
        {
            array_iterator copy = *this;
            ++*this;
            return copy;
        }

        array_iterator& operator --()
        {
            --idx;
            return *this;
        }

        array_iterator operator --(int)
        {
            array_iterator copy = *this;
            --*this;
            return copy;
        }

        bool operator == (const array_iterator& right) const
        {
            return (idx == right.idx);
        }

        bool operator != (const array_iterator& right) const
        {
            return (idx != right.idx);
        }
    };

    template <typename T, std::size_t N>
    struct array
    {
        // 要素の型
        using value_type = T;

        // 要素の参照
        using reference = T&;

        // 要素の参照(const)
        using const_reference = const T&;

        // 要素数を表す型
        using size_type = std::size_t;

        // イテレーター
        using iterator = array_iterator<array>;

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

        reference front()
        {
            return strage[0];
        }

        const_reference front() const
        {
            return strage[0];
        }

        reference back()
        {
            return strage[N-1];
        }

        const_reference back() const
        {
            return strage[N-1];
        }

        void fill(const_reference v)
        {
            for (size_type i = 0; i < N; ++i)
            {
                strage[i] = v;
            }
        }

        // イテレーターを返すメンバー関数
        iterator begin()
        {
            return iterator(*this, 0);
        }

        iterator end()
        {
            return iterator(*this, N);
        }

        // bool operator == (const array& right) const
        // {
        //     if (N != right.size())
        //         return false;
            
        //     for (size_type i = 0; i < N; ++i)
        //     {
        //         if (strage[i] != right.strage[i])
        //             return false;
        //     }

        //     return true;
        // }

        // bool operator != (const array& right) const
        // {
        //     return !(*this == right);
        // }
    };
}