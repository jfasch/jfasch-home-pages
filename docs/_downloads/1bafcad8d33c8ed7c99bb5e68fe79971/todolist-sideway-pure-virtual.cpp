#include <map>
#include <string>
#include <iostream>

class Item
{
public:
    virtual void doit() const = 0;
};

class Item_up_1_to_10 : public Item
{
public:
    Item_up_1_to_10(const std::string& prefix) : _prefix(prefix) {}
    void doit() const override                         // <-- override is redundant (base is pure)
    {
        for (int i=1; i<=10; i++)
            std::cout << _prefix << ", UP: " << i << '\n';
    }
private:
    std::string _prefix;
};

int main()
{
    Item_up_1_to_10 derived("blah");

    Item* base;
    base = &derived;
    base->doit();

    return 0;
}
