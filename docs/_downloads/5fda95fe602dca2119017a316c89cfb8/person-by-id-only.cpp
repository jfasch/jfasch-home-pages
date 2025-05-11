#include <cassert>
#include <string>

struct person
{
    unsigned id;
    std::string name;

    bool operator==(const person& rhs) const
    {
        return id == rhs.id;
    }
};

int main()
{
    person isi{42, "Isi"};
    person joerg{666, "Joerg"};

    assert(isi == isi);
    assert(isi != joerg);                              // <-- magic: a!=b equivalent to !(a==b)
    return 0;
}
