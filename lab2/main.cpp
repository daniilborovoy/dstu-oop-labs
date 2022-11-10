#include <iostream>
#include <clocale>
#include <iomanip>

class Test {
private:
    int W;

    friend void func(Test *testPtr);

    void Z() {
        std::cout << "Это закрытая функция класса Test" << std::endl;
    }

public:
    Test(int W = 1) {
        this->W = W;
    }
};

void func(Test *testPtr) {
    std::cout << testPtr->W << std::endl;
    testPtr->Z();
}

class Abonent {
    int individualNumber;
    char *lastName;
    double phoneNumber;

    friend class Notebook;

public:
    Abonent(int individualNumber, char *lastName, int phoneNumber) {
        std::cout << "Конструктор класса Abonent" << std::endl;
        this->individualNumber = individualNumber;
        this->lastName = lastName;
        this->phoneNumber = phoneNumber;
    }

    ~Abonent() {
        std::cout << "Деструктор класса Abonent" << std::endl;
    }
};

class Notebook {
public:
    void change(double phoneNumber, Abonent *abonentPtr) {
        abonentPtr->phoneNumber = phoneNumber;
    }

    void show(Abonent *abonentPtr) {
        std::cout << std::setw(21) << std::left << abonentPtr->individualNumber;
        std::cout << std::setw(29) << std::left << abonentPtr->lastName;
        std::cout << std::left << abonentPtr->phoneNumber << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Test test;
    func(&test);

    Abonent abonent[5] = {
            Abonent(1, "Иванов", 123456789),
            Abonent(2, "Петров", 987654321),
            Abonent(3, "Сидоров", 123456789),
            Abonent(4, "Смирнов", 987654321),
            Abonent(5, "Кузнецов", 123456789)
    };

    Notebook notebook;

    notebook.change(321312, &abonent[0]);

    int abonentsCount = sizeof(abonent) / sizeof(abonent[0]);
    std::cout << std::endl << "Абоненты: " << abonentsCount << std::endl;
    std::cout << "Индивидуальный номер " << "Фамилия " << "Номер телефона" << std::endl;
    for (int i = 0; i < abonentsCount; i++) {
        notebook.show(&abonent[i]);
    }
    std::cout << std::endl;
    return 0;
}
