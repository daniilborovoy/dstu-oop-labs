//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#include <iostream>
#include "lab6_1_2.h"
#include <string>
#include <utility>

using namespace std;

class DomesticAnimal {
protected:
    int weight;
    int price;
    string color;

public:
    DomesticAnimal() {
        weight = 0;
        price = 0;
        color = "white";
    }

    DomesticAnimal(int weight, int price, string color) : weight(weight), price(price), color(std::move(color)) {
        cout << "Вызван конструктор DomesticAnimal с параметрами" << endl;
    }

    void print() {
        cout << "DomesticAnimal:" << endl;
        cout << typeid(*this).name()
             << "\nweight: " << this->weight
             << "\nprice: " << this->price
             << "\ncolor: " << this->color << endl;
    }
};

class Cow : virtual public DomesticAnimal {
public:
    void print() {
        cout << typeid(*this).name()
             << "\nweight: " << this->weight
             << "\nprice: " << this->price
             << "\ncolor: " << this->color << endl;
    }

    Cow() {}

    Cow(int weight, int price, string color) : DomesticAnimal(weight, price, std::move(color)) {}
};

class Buffalo : virtual public DomesticAnimal {
public:
    Buffalo() {}

    Buffalo(int weight, int price, string color) : DomesticAnimal(weight, price, std::move(color)) {}

    void print() {
        cout << typeid(*this).name()
             << "\nweight: " << this->weight
             << "\nprice: " << this->price
             << "\ncolor: " << this->color << endl;
    }
};

class Beefalo : public Cow, public Buffalo {
public:
    Beefalo() {}

    Beefalo(int weight, int price, const string& color): DomesticAnimal(weight, price, color) {}

    void print() {
        cout << typeid(*this).name()
             << "\nweight: " << this->weight
             << "\nprice: " << this->price
             << "\ncolor: " << this->color << endl;
    }
};

void lab6_1_2::run_lab6_1_2() {
    cout << "Лабораторная работа №6.1.2" << endl;
    Cow cow(1000, 500, "white");
    Beefalo beefalo(100, 1000, "black");
    cow.print();
    beefalo.print();
}
