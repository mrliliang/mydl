
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
    vector<A> vec;
    vec.emplace_back(A(10));
    vec.emplace_back(A(20));
    vec.emplace_back(A(30));

    int i = 0;
    for (auto& v : vec) {
        std::cout << "i = " << i << std::endl;
        std::cout << "v.value = " << v.value() << ", " << "vec[" << i << "].value = " << vec[i].value() << std::endl;
        std::cout << &v << ", " << &vec[i] << std::endl;
        i++;
    }

    map<int, string> kvs;
    kvs[1] = "abc";
    kvs[2] = "def";
    kvs[3] = "ghi";
    for (auto& kv : kvs) {
        std::cout << kv.first << ": " << kv.second << std::endl;
    }
    

}
