#include <iostream>

using namespace std;

class Base {
public:
    int i;

    Base(int i, long l, double d) {
        this->i = i;
        this->l = l;
        this->d = d;
    }

//    void ff() {
//        cout << "Base::ff()" << endl;
//    }

protected:
    long l;

    double *getD() {
        return &d;
    }

private:
    double d;
};

class Derived : public Base {
public:
    using Base::i;
    using Base::l;

    Derived() : Base(1, 2, 3) {
        this->f = 10.0;
    }

    Derived(int i, long l, double d, float f) : Base(i, l, d) {
        this->f = f;
    }

    friend ostream &operator<<(ostream &os, Derived &derived) {
        os << "i = " << derived.i << " " << &derived.i << endl;
        os << "l = " << derived.l << " " << &derived.l << endl;
        os << "f = " << derived.f << " " << &derived.f << endl;
        double *d = derived.getD();
        os << "d = " << *d << " " << d << endl;
        return os;
    }

//    void ff() {
//        cout << "Derived::ff()" << endl;
//    }

private:
    float f;
};

void ff() {
    cout << "ff()" << endl;
}

class Derived_1 : private Derived {
public:
    Derived_1() : Derived() {
    }

    Derived_1(int i, long l, double d, float f) : Derived(i, l, d, f) {}

    void foo() {
        i++;
        l += 1;
        ff();
    }
};


int main() {
//    Derived derived;
//    cout << sizeof(Derived) << endl;
//    cout << sizeof(Base) << endl;

//    Derived derived(1, 2, 3, 4.0);
//    cout << derived << endl;

    Derived_1 derived_1(1, 2, 3, 4.0);
    derived_1.foo();

    return 0;
}
