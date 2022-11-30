#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Date {
private:
    int day, month, year, days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date() {
        time_t theTime = time(nullptr);
        struct tm *aTime = localtime(&theTime);
        day = aTime->tm_mday;
        month = aTime->tm_mon + 1;
        year = aTime->tm_year + 1900;
    }

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date operator+(Date date) {
        Date result;
        result.day = day + date.day;
        result.month = month + date.month;
        result.year = year + date.year;
        while (result.day > days[result.month]) {
            result.day -= days[result.month];
            result.month++;
            while (result.month > 12) {
                result.month -= 12;
                result.year++;
            }
        }
        return result;
    }

    Date operator-(Date date) {
        Date result;
        result.day = this->day - date.day;
        result.month = this->month - date.month;
        result.year = this->year - date.year;
        while (result.month < 1) {
            result.month += 12;
            result.year--;
        }
        while (result.day < 0) {
            result.day += days[result.month];
            result.month--;
        }
        return result;
    }

    Date operator+(int days) {
        int day = this->day + days;
        int month = this->month;
        int year = this->year;
        while (day > this->days[month]) {
            day -= this->days[month];
            month++;
            if (month > 12) {
                month -= 12;
                year++;
            }
        }
        return {day, month, year};
    }

    friend Date operator+(int days, Date date) {
        int newDay = date.day + days;
        int newMonth = date.month;
        int newYear = date.year;
        while (newDay > date.days[newMonth]) {
            newDay -= date.days[newMonth];
            newMonth++;
            if (newMonth > 12) {
                newMonth -= 12;
                newYear++;
            }
        }
        return {newDay, newMonth, newYear};
    }

    Date operator-(int days) {
        int day = this->day - days;
        int month = this->month;
        int year = this->year;
        while (day < 0) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += this->days[month];
        }
        if (month == 0) {
            month = 12;
            year--;
        }
        return {day, month, year};
    }

    Date operator++(int) {
        int day = this->day + 1;
        int month = this->month;
        int year = this->year;
        if (day > this->days[month]) {
            day -= this->days[month];
            month++;
            if (month > 12) {
                month -= 12;
                year++;
            }
        }
        return *this = {day, month, year};
    }

    Date operator--(int) {
        int day = this->day - 1;
        int month = this->month;
        int year = this->year;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += this->days[month];
        }
        return *this = {day, month, year};
    }

    ostream &operator<<(ostream &os) const {
        os << this->year << '/' << this->month << '/' << this->day;
        return os;
    }

    friend ostream &operator<<(ostream &os, const Date &date) {
        os << date.year << '/' << date.month << '/' << date.day;
        return os;
    }
};

// finding the perimetr of a triangle in a 2D plane by coordinates of its vertices
double perimetr(double x1, double y1, double x2, double y2, double x3, double y3) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) +
           sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
}

// finding the area of a triangle in a 3D plane by coordinates of its vertices
double perimetr(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)) +
           sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2) + pow(z3 - z2, 2)) +
           sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));
}

int myfunc(int i); // Эти функции различаются типами параметров
double myfunc(double i);

int main() {
    // TODO: implement the following code
//    cout << myfunc(1) << endl; // Вызов функции с типом int
//    cout << myfunc(1.0) << endl; // Вызов функции с типом double
//    trianglePerimetr();

    cout << perimetr(0, 0, 0, 1, 1, 0) << endl;
    cout << perimetr(1, 1, 1, 2, 2, 2, 3, 3, 3) << endl;

    Date date1(10, 10, 2002);
    Date date2(11, 10, 1999);
    Date date3(13, 10, 2002);
    Date currentDate;
    cout << "date1: " << date1 << endl;
    cout << "date2: " << date2 << endl;
    cout << "date3: " << date3 << endl;
    cout << "currentDate: " << currentDate << endl;

    cout << "date1 + date2: " << date1 + date2 << endl;
    cout << "date3 - date2: " << date3 - date2 << endl;

    cout << "365 + date1: " << 365 + date1 << endl;
    cout << "date1 + 365: " << date1 + 365 << endl;
    cout << "date1 - 365: " << date1 - 365 << endl;
    cout << "date1++: " << date1++ << endl;
    cout << "date1--: " << date1-- << endl;
    return 0;
}

double myfunc(double i) {
    return i;
}

int myfunc(int i) {
    return i;
}
