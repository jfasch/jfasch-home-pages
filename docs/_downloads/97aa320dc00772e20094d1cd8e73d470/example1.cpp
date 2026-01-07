#include <iostream>

class Foo
{
public:
    Foo() {
        std::cout << "Foo()" << std::endl;
    }
    ~Foo() {
        std::cout << "~Foo()" << std::endl;
    }
};

int main()
{
    std::cout << "begin main" << std::endl;
    Foo f;
    std::cout << "end main" << std::endl;
    return 0;
}
