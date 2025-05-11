#include <cassert>

struct point
{
    int x;
    int y;

    bool operator==(const point& rhs) const = default;
};

int main()
{
    point p1{1,2};
    point p2{3,4};
    assert(p1 == p1);
    assert(p1 != p2);
    return 0;
}
