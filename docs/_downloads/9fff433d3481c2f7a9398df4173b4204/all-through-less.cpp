#include <map>
#include <string>
#include <cassert>

struct compound_key
{
    int primary, secondary;
    bool operator<(const compound_key& rhs) const
    {
        return 
            primary<rhs.primary ||
            (primary==rhs.primary && secondary<rhs.secondary);
    }

    bool operator==(const compound_key& rhs) const
    {
        return !(*this < rhs) && !(rhs < *this);
    }
    bool operator!=(const compound_key& rhs) const
    {
        return !(*this == rhs);
    }
    bool operator>(const compound_key& rhs) const
    {
        return (rhs < *this) && (*this != rhs);
    }
    bool operator<=(const compound_key& rhs) const
    {
        return !(*this > rhs);
    }
    bool operator>=(const compound_key& rhs) const
    {
        return !(*this < rhs);
    }
};

int main()
{
    compound_key k1{1, 2};
    compound_key k2{2, 3};

    assert(k1 == k1);
    assert(!(k1 < k1));
    assert(k1 < k2);
    assert(k1 != k2);
    assert(k2 > k1);

    assert(k1 <= k2);
    assert(k1 <= k1);

    assert(k2 >= k1);
    assert(k1 >= k1);

    return 0;
}
