#ifndef NDArray
#define NDArray

#include <cstdio>
#include <cstdlib>
namespace nda
{
    unsigned long inline max(unsigned long a, unsigned long b) { return (a > b ? a : b); }
    static unsigned int log2(unsigned long x)
    {
        if (x <= 1)
            return 0;
        unsigned int ret = 0;
        while (x > 1)
        {
            x >>= 1;
            ret++;
        }
        return ret;
    }
    /*
        Auto-expanding array
        Automatically expand when the visit value is higher than the capacity
        If the expansion is at least expanded to (2<<log2(current capacity))
        自动扩容数组
        访问值高于容量时自动扩容
        如果扩容最少扩容到(2<<log2(当前容量))
    */
    template <class T>
    class DArray
    {
        unsigned long siz;
        T *a;

    public:
        DArray()
        {
            siz = 2;
            a = (T *)malloc(sizeof(T) << 1);
        }

        unsigned inline long size() { return siz; }

        void inline clear() { free(a); }

        void inline expansion(unsigned long i)
        {
            unsigned long nSize = nda::max(2 << nda::log2(siz), i);
            a = realloc(a, nSize * sizeof(T));
        }

        T &operator[](unsigned long i)
        {
            if (i >= siz)
                expansion(i);
            else if (i < 0)
                throw "Invalid array position.";
            return a[i];
        }
    };
} // namespace nda

#endif