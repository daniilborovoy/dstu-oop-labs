//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#ifndef LAB6_NEW_FIG_H
#define LAB6_NEW_FIG_H

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c);

    double area() override;

    void show() override;

protected:
    double a{}, b{}, c{};
};

#endif //LAB6_NEW_FIG_H
