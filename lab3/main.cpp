#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Goods {
    string name;
    time_t registrationDate;
    double price;
    int count;
    int invoiceNumber;

    Goods operator=(const Goods &other) {
        name = other.name;
        registrationDate = other.registrationDate;
        price = other.price;
        count = other.count;
        invoiceNumber = other.invoiceNumber;
        return *this;
    }

public:
    Goods() {
        name = "21";
        price = 100;
        count = 5;
        invoiceNumber = 984712;
        registrationDate = time(0);
        cout << "Constructor" << endl;
    }

    Goods(const Goods &obj) {
        name = obj.name;
        price = obj.price;
        count = obj.count;
        invoiceNumber = obj.invoiceNumber;
        registrationDate = obj.registrationDate;
        cout << "Copy constructor" << endl;
    }

    void changeInfo(string name, double price, int count, int invoiceNumber) {
        this->name = name;
        this->price = price;
        this->count = count;
        this->invoiceNumber = invoiceNumber;
        registrationDate = time(0);
    }

    int getTotalPrice() {
        return price * count;
    }
};

// by value
Goods tovar(Goods s) {
    return s;
}

// by link and return by value
Goods tovar2(Goods &s) {
    return s;
}

// by link and return by link
Goods* tovar3(Goods &s) {
    return &s;
}

int main() {
//    cout<<"Вход в функцию main()"<<endl;
//    Goods goods;
//    cout<<"Выход из функции main()"<<endl;


    Goods goods1;
//    Goods goods2 = goods1;

//    tovar(goods1);
//    tovar2(goods1);
    tovar3(goods1);
    return 0;
}
