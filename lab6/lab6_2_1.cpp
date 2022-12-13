//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#include "lab6_2_1.h"
#include <iostream>
#include <cmath>

using namespace std;

// commented to remove multiple definition error in lab6_2_2.cpp

//class Figure {
//public:
//    virtual double area() {
//        return 0;
//    };
//
//    virtual void show() {
//        cout << "Информация о типе фигуры" << endl;
//    };
//};
//
//class Circle : public Figure {
//public:
//    explicit Circle(double r) {
//        if (r > 0) {
//            this->r = r;
//        } else {
//            cout << "Радиус должен быть больше 0!" << endl;
//            exit(1);
//        }
//    }
//
//    double area() override {
//        return M_PI * pow(this->r, 2);
//    }
//
//    void show() override {
//        cout << "Круг:\t\t" << this << "\t" << sizeof(*this) << "Байт" << "\nr:\t" << this->r << "\t" << &this->r
//             << endl;
//        cout << "Площадь:\t" << this->area() << endl;
//    }
//
//protected:
//    double r;
//};
//
//class Rectangle : public Figure {
//public:
//    explicit Rectangle(double d1, double d2 = 0) {
//        this->d1 = d1;
//        this->d2 = d2;
//    }
//
//    double area() override {
//        if ((d2 > 0) && (d2 != d1)) {
//            return this->d1 * this->d2;
//        } else {
//            return pow(this->d1, 2);
//        }
//    }
//
//    void show() override {
//        if ((d2 > 0) && (d2 != d1)) {
//            cout << "Прямоугольник:\t" << this << "\t" << sizeof(*this) << "Байт"
//                 << "\nd1:\t" << this->d1 << "\t" << &this->d1
//                 << "\nd2:\t" << this->d2 << "\t" << &this->d2 << endl;
//        } else {
//            cout << "Квадрат:\t" << this << "\t" << sizeof(*this) << "Байт" << "\nd:\t" << this->d1 << "\t" << &this->d1
//                 << endl;
//        }
//            cout << "Площадь:\t" << this->area() << endl;
//    }
//
//protected:
//    double d1, d2;
//};
//
void lab6_2_1::run_lab6_2_1() {
//    Rectangle test(4);
//    Circle test1(2);
//    Rectangle test2(1, 2);
//    Figure *mas[3]{&test, &test1, &test2};
//    for (auto i: mas) {
//        i->show();
//    }
}
