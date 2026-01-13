#include <string>
#include <iostream>


class Interface
{
public:
    virtual ~Interface() = default;
    virtual void doit() const = 0;
};

class TestImplemention : public Interface
{
public:
    ~TestImplemention() override {
        std::cout << "TestImplemention::~TestImplemention()" << std::endl;
    }
    void doit() const override {
        std::cout << "TestImplemention::doit()" << std::endl;
    }
};

class RealImplemention : public Interface
{
public:
    RealImplemention(const std::string& bus, unsigned address) { /*...*/ }
    ~RealImplemention() override {
        std::cout << "RealImplemention::~RealImplemention()" << std::endl;
    }
    void doit() const override {
        std::cout << "RealImplemention::doit()" << std::endl;
    }
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "nix one parameter" << std::endl;
        return 1;
    }

    Interface* my_obj;

    std::string how = argv[1]; // "test" or "real"
    if (how == "test")
        my_obj = new TestImplemention();
    else if (how == "real")
        my_obj = new RealImplemention(/*bus*/"/dev/i2c-1", /*address*/0x42);
    else
        std::cerr << "nix good parameter" << how << std::endl;

    my_obj->doit();                                    // <-- use polymorphic object

    delete my_obj;                                     // <-- what if I forget this?

    return 0;
}
