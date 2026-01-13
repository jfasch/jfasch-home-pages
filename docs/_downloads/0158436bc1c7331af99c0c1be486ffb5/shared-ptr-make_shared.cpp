#include <string>
#include <iostream>
#include <memory>


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

    std::shared_ptr<Interface> my_obj;

    std::string how = argv[1]; // "test" or "real"
    if (how == "test")
        my_obj = std::make_shared<TestImplemention>(); // <-- less clumsy
    else if (how == "real")
        my_obj = std::make_shared<RealImplemention>(
            /*bus*/"/dev/i2c-1", /*address*/0x42);     // <-- less clumsy
    else
        std::cerr << "nix one parameter " << how << std::endl;

    my_obj->doit();

    return 0;
}
