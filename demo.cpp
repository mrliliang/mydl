
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
    vector<vector<pair<string, string>>> v(std::pow(2, 10), vector<pair<string, string>>{});
    std::cout << v.size() << std::endl;

    vector<vector<pair<string, string>>>& v1 = v;
    v1 = vector<vector<pair<string, string>>>(std::pow(2, 10), vector<pair<string, string>>{});
    std::cout << "v1: " << v1.size() << std::endl;
    std::cout << "v: " << v.size() << std::endl;
}
