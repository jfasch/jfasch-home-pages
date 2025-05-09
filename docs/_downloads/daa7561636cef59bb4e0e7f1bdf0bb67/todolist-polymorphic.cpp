#include <map>
#include <string>
#include <iostream>

class Item
{
public:
    virtual ~Item() = default;
    virtual void doit() const = 0;
};

class Item_up_1_to_10 : public Item
{
public:
    Item_up_1_to_10(const std::string& prefix) : _prefix(prefix) {}
    void doit() const override
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
    void doit() const override
    {
        for (int i=1000; i>=980; i--)
            std::cout << "DOWN: " << i << '\n';
    }
};

int main()
{
    using todo_list = std::map<std::string, Item*>;            // <-- pointer to interface

    const todo_list tdl = {
        { "up 1 to 10", new Item_up_1_to_10("blah") },         // <-- dynamic allocation
        { "down 1000 to 980", new Item_down_1000_to_980() },   // <-- dynamic allocation
    };

    for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it) {
        std::string name = it->first;
        const Item* item = it->second;

        std::cout << "NAME: " << name << ", ";
        item->doit();                                          // <-- polymorphic use
        std::cout << '\n';
    }

    for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it)
        delete it->second;                                     // <-- polymorphic dtor call

    return 0;
}
