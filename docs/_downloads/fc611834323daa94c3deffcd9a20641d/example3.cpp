#include <iostream>
#include <string>

class Foo
{
public:
    Foo() {
        std::cout << "Foo()" << std::endl;
    }
    ~Foo() {
        std::cout << "~Foo()" << std::endl;
    }
    void bar() const {
        std::cout << "bar()" << std::endl;
    }
};

int main(int argc, char** argv)
{
    Foo* f = nullptr;

    if (argc != 2) {
        std::cerr << "need one parameter" << std::endl;
        return 1;
    }
    int i = std::stoi(argv[1]);
    if (i) {
        Foo some_f;
        f = &some_f;
    }
    if (i)
        delete f;

    return 0;
}
