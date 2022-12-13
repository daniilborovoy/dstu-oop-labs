//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#include "new_fig.h"
#include <iostream>
#include <cmath>

using namespace std;

//Triangle
Triangle::Triangle(double a, double b, double c) {
    if ((a + b > c || b + c > a || c + a > b) && (a != 0 && b != 0 && c != 0)) {
        this->a = a;
        this->b = b;
        this->c = c;
    } else {
        cout << "Неверные исходные данные!" << endl;
        exit(1);
    }
}

double Triangle::area() {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::show() {
    cout << "Треугольник:\t" << this << "\t" << sizeof(*this) << "Байт:"
         << "\na:\t" << this->a << "\t" << &this->a
         << "\nb:\t" << this->b << "\t" << &this->b
         << "\nc:\t" << this->c << "\t" << &this->c << endl;
    cout << "Площадь:\t" << this->area() << endl;
}
