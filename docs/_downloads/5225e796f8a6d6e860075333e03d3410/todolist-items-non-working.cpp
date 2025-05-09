#include <map>
#include <string>
#include <iostream>

class Item
{
public:
    void doit() const
    {
        std::cout << "don't know what to do";
    }
};

class Item_up_1_to_10 : public Item
{
public:
    Item_up_1_to_10(const std::string& prefix) : _prefix(prefix) {}
    void doit() const
    {
        for (int i=1; i<=10; i++)
            std::cout << _prefix << ", UP: " << i << '\n';
    }
private:
    std::string _prefix;
};

class Item_down_1000_to_980 : public Item
{
public:
    void doit() const
    {
        for (int i=1000; i>=980; i--)
            std::cout << "DOWN: " << i << '\n';
    }
};

int main()
{
    using todo_list = std::map<std::string, Item>;       // <-- base class

    const todo_list tdl = {
        { "up 1 to 10", Item_up_1_to_10("blah") },       // <-- copy: derived onto base
        { "down 1000 to 980", Item_down_1000_to_980() }, // <-- copy: derived onto base
    };

    for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it) {
        std::string name = it->first;
        Item item = it->second;                          // <-- copy: base onto base

        std::cout << "NAME: " << name << ", ";
        item.doit();
        std::cout << '\n';
    }

    return 0;
}
