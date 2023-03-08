
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cmath>
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

        A(A&& a) {
            std::cout << "A(A&& a)" << std::endl;
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

unique_ptr<A> pointer(int v) {
    unique_ptr<A> pa = std::make_unique<A>(v);
    return pa;
}

int main(int argc, char *argv[]) {
    string s1 = "abc";
    string s2 = "ghi";
    string s3 = s1 + "def" + "ghi" + "jkl";

    std::cout << s3 << std::endl;

}
