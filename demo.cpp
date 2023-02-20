
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <algorithm>
// #include "basetype.h"



using namespace std;

class A {
    public:
        A() {
            std::cout << "A()" << std::endl;
        }
        A(A& a) {
            std::cout << "A(A& a)" << std::endl;
            this->v = a.value();
        }
        A(int a) : v{a} {
            std::cout << "A(int a)" << std::endl;
        }

        int value() {
            return v;
        }

        A& operator=(A& a) {
            std::cout << "A& operator=(A& a)" << std::endl;
            this->v = a.value();
            return *this;
        }

    private:
        int v;
};

// void print(A& a) {
//     std::cout << &a << std::endl;
//     std::cout << a.value() << endl;
// }

template<typename T = A>
void print(T&& a) {
    std::cout << &a << std::endl;
    std::cout << a.value() << endl;
}

int main(int argc, char *argv[]) {
    string src = "abcdef";
    string dst = src;
    std::transform(src.begin(), src.end(), dst.begin(), ::toupper);

    std::cout << src << endl;
    std::cout << dst << endl;
}
