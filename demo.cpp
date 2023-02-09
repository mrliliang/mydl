
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
// #include "basetype.h"



using namespace std;

class A {
    public:
        A() {
            std::cout << "A()" << std::endl;
        }
        A(int a) : v{a} {
            std::cout << "construct A" << std::endl;
        }

        int value() {
            return v;
        }

    private:
        int v;
};

void print(A a) {
    std::cout << &a << std::endl;
    std::cout << a.value() << endl;
}

int main(int argc, char *args[]) {
    A a{10};
    std::cout << &a << std::endl;
    print(a);

    A b = a;
    std::cout << &b << std::endl;
    print(b);
}
