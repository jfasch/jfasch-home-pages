#include <map>
#include <string>

struct compound_key
{
    int primary, secondary;
    bool operator<(const compound_key& rhs) const
    {
        return 
            primary<rhs.primary ||
            (primary==rhs.primary && secondary<rhs.secondary);
    }
};

int main()
{
    std::map<compound_key, std::string> database;
    database.insert({{1,2}, "foo"});
    return 0;
}
