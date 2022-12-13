//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#ifndef LAB6_FIGURE_H
#define LAB6_FIGURE_H

class Figure {
public:
    virtual double area() { return 0; };

    virtual void show() {};
};

class Circle : public Figure {
public:
    explicit Circle(double r);

    double area() override;

    void show() override;

protected:
    double r;
};

class Rectangle : public Figure {
public:
    explicit Rectangle(double d1, double d2 = 0);

    double area() override;

    void show() override;

protected:
    double d1, d2;
};

#endif //LAB6_FIGURE_H
