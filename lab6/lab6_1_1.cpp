//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#include "lab6_1_1.h"
#include <iostream>
#include <cstring>

using namespace std;

class Base1 {
    int i;
public:
    Base1() {
        cout << "Конструктор Base1 без параметров" << endl;
        i = 0;
    }

    Base1(int i) {
        cout << "Конструктор Base1 с параметром" << endl;
        this->i = i;
    }

    void put(int number) {
        i = number;
    }

    int get() const {
        return i;
    }
};

class Base2 {
    char name[20];
public:
    Base2() {
        cout << "Конструктор Base2 без параметров" << endl;
        strcpy(name, "Пусто");
    }

    Base2(char *name) {
        cout << "Конструктор Base2 с параметром" << endl;
        strcpy(this->name, name);
    }

    void put(char *name) {
        strcpy(this->name, name);
    }

    char *get() const {
        return (char *) name;
    }
};

class Derived : public Base2, public Base1 {
    char ch;
public:
    Derived() {
        cout << "Конструктор Derived без параметров" << endl;
        ch = 'V';
    }

    Derived(char ch, char *name, int i) : Base1(i), Base2(name) {
        cout << "Конструктор Derived с параметром" << endl;
        this->ch = ch;
    }

    void put(char ch) {
        this->ch = ch;
    }

    char get() const {
        return ch;
    }

    friend ostream &operator<<(ostream &stream, const Derived &obj) {
        stream << "ch = " << obj.ch << endl;
        stream << "name = " << obj.get() << endl;
        stream << "i = " << obj.Base1::get() << endl;
        return stream;
    }
};

void lab6_1_1::run_lab6_1_1() {
    Derived obj1;
    cout << obj1 << endl;
    Derived obj2('A', "Hello", 10);
    cout << obj2 << endl;
}
