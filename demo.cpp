
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
// #include "basetype.h"



using namespace std;

// struct AttributeMap {
//     AttributeMap(string name, string type, bool isKey) : name{name}, type{type}, isKey{isKey} {
    
//     }
//     string name{""};
//     string type{""};
//     bool isKey{false};
// };

// struct MathMap
// {
//     MathMap() {}
//     MathMap(string lhs, string op, string rhs) : lhs{lhs}, op{op}, rhs{rhs} {

//     }
//     string lhs;
//     string op;
//     string rhs;
// };

// struct AggArg {
//     AggArg() {}
//     AggArg(string type, string attr) : type{type}, attr{attr} {

//     };
//     AggArg(string type, MathMap mathExpr) : type{type}, 
//         mathExpr{mathExpr} {

//     }
//     string type{""};
//     string attr{""};
//     MathMap mathExpr;
// };

// struct AggMap {
//     AggMap() {}
//     AggMap(string aggOp, AggArg aggArg) : aggOp{aggOp}, aggArg{aggArg} {
        
//     }
//     string aggOp{""};
//     AggArg aggArg;
// };

// struct CompareMap {
//     CompareMap() {}
//     CompareMap(string lhsText, string lhsType, string op, string rhsText, string rhsType) 
//     : lhsText{lhsText}, lhsType{lhsType}, op{op}, rhsText{rhsText}, rhsType{rhsType} {}
//     string lhsText;
//     string lhsType;
//     string op;
//     string rhsText;
//     string rhsType;
// };

// struct AssignMap {
//     AssignMap() {}
//     AssignMap(string lhs, MathMap rhs) : lhs{lhs}, rhs{rhs.lhs, rhs.op, rhs.rhs} {

//     }
//     string lhs;
//     MathMap rhs;
// };

// struct AtomArg {
//     AtomArg() {}
//     AtomArg(string name, string type, bool isKeyAttr = false) : 
//         name{name}, type{type}, isKeyAttr{isKeyAttr} {

//     }
//     string name;
//     string type;
//     bool isKeyAttr{false};
// };

// struct AtomMap {
//     string name;
//     vector<AtomArg> argList;
// };

// struct BodyMap {
//     vector<AtomMap> atoms;
//     vector<CompareMap> compares;
//     vector<AssignMap> assigns;
//     vector<AtomMap> negations;
// };

// struct RuleMap {
//     bool nonDedup;
//     bool nonSetDiff;
//     bool dedupOnly;
//     AtomMap head;
//     BodyMap body;
// };

// struct Schema {
//     string name;
//     vector<AtomArg> attributes;
// };

class A {
    public: 
        A() {
            cout << "construct A" << endl;
        }
        ~A() {
            cout << "destroy A" << endl;
        }

        const char *str = "class A";

        void output() {
            cout << "output A: " << str << endl;
        }
};

class AExtend : A {
    public:
        AExtend() : A{} {
            cout << "construct AExtend" << endl;
        }
        ~AExtend() {
            cout << "destroy AExtend" << endl;
        }
};

class B {
    public:
        B() {
            cout << "construct B" << endl;
        }
        ~B() {
            cout << "destroy B" << endl;
        }
        string str = "class B";
        unique_ptr<A>  pa = nullptr;
};

class C {
    public:
        C() {
            cout << "construct C" << endl;
        }
        ~C() {
            cout << "destroy C" << endl;
        }
        unique_ptr<B> pb = nullptr;
};

unique_ptr<A> a() {
        unique_ptr<A> pa = make_unique<A>();
        return pa;
}

unique_ptr<B> b() {
    unique_ptr<B> pb = make_unique<B>();
    pb->pa = a();
    // pb->pa = make_shared<A>();
    return pb;
}

unique_ptr<C> c() {
    unique_ptr<C> pc = make_unique<C>();
    pc->pb = b();
    return pc;
}



int main(int argc, char *args[])
{
    map<string, vector<int>> *headRuleMap = nullptr;
    std::cout << headRuleMap << std::endl;
    delete headRuleMap;
    delete headRuleMap;
}
