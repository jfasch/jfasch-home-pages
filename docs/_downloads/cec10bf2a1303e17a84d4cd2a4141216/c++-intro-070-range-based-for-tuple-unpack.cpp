#include <map>
#include <string>
#include <iostream>

int main()
{
    using todo_list = std::map<std::string, std::string>;

    todo_list tdl{
        { "up 1 to 10",         "prefix: 'UP', count up from 1 to 10, interval 1 second" },
        { "down 1000 to 980",   "prefix: 'DOWN', count down from 1000 to 980, interval 0.5 second"},
    };

    for (const auto& [name, desc]: tdl)  // <--- unpacking std::pair right into its parts
        std::cout << "NAME: " << name << ", DESC: " << desc << std::endl;

    return 0;
}
