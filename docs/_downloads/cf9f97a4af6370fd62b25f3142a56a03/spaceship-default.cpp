#include <map>
#include <string>
#include <cassert>

struct compound_key
{
    int primary, secondary;
    std::strong_ordering operator<=>(const compound_key& rhs) const = default;
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
