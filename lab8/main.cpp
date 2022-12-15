#include <iostream>
#include <iomanip>

using namespace std;

char s[255] = "abcd\n";

ostream &endp(ostream &stream) {
    char ss[255];
    static int k = 0;
    int i, j, c = 5;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++) {
        ss[i] = s[j];
        if (ss[i] == '\n') {
            k++;
            if (k == c) {
                ss[i + 1] = '\n';
                stream << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0) {
        ss[i + 1] = '\0';
        stream << ss;
    }
    return stream;
}

// endp with a parameter

ostream &endp(ostream &stream, int n) {
    char ss[255];
    static int k = 0;
    int i, j, c = n;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++) {
        ss[i] = s[j];
        if (ss[i] == '\n') {
            k++;
            if (k == c) {
                ss[i + 1] = '\n';
                stream << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0) {
        ss[i + 1] = '\0';
        stream << ss;
    }
    return stream;
}

ostream &fendp(ostream &stream, int n, string str) {
    char ss[255];
    static int k = 0;
    int i, j, c = n;
    for (i = 0, j = 0; str[j] != '\0'; i++, j++) {
        ss[i] = str[j];
        if (ss[i] == '\n') {
            k++;
            if (k == c) {
                ss[i + 1] = '\n';
                stream << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0) {
        ss[i + 1] = '\0';
        stream << ss;
    }
    return stream;
}

int main() {
    // Задание 1.1 Ответ: До явной отмены.
    /*cout << hex << 11 << endl;
    cout << 11 << endl;
    cout.unsetf(ios::hex);
    cout << 11 << endl;*/
    //Задание 1.2 Ответ: Округляет после точки
    //cout << fixed << setprecision(3) << (4.5559) << endl;
    //Задание 1.3
    /*cout.width(12);
    cout << 123.2937473173247 << endl;
    cout.width(12);
    cout << scientific << 123.2937473173247 << endl;
    cout.unsetf(ios::scientific);
    cout.width(12);
    cout << left << fixed << setfill('-') << 123.2937473173247 << endl;
    cout.width(12);
    cout << right << fixed << setfill('-') << 123.2937473173247 << endl;*/
    //Задание 2, флаги
    /*
    // endl - перевод строки и сброс буфера
    cout << "website:" << endl << "cppstudio.com";
    // boolalpha - вывод буфера в виде true или false
    cout << boolalpha << 0 << endl;
    // oct - вывод восьмеричного числа
    cout << oct << 11 << endl;
    cout.unsetf(ios::oct);
    // hex - вывод шестнадцатеричного числа
    cout << hex << 11 << endl;
    cout.unsetf(ios::hex);
    // dec - вывод десятичного числа
    cout << dec << 11 << endl;
    cout.unsetf(ios::dec);
    // showbase - выводит 0x или 0 в начале числа
    cout << showbase << hex << 11 << endl;
    cout.unsetf(ios::showbase);
    cout.unsetf(ios::hex);
    // noshowbase - не выводит 0x или 0 в начале числа
    cout << noshowbase << hex << 11 << endl;
    cout.unsetf(ios::hex);
    // uppercase - выводит шестнадцатеричное число в верхнем регистре
    cout << uppercase << hex << 11 << endl;
    cout.unsetf(ios::uppercase);
    // nouppercase - выводит шестнадцатеричное число в нижнем регистре
    cout << nouppercase << hex << 11 << endl;
    cout.unsetf(ios::hex);
    // showpos - выводит знак + перед положительным числом
    cout << showpos << 11 << endl;
    cout.unsetf(ios::showpos);
    // noshowpos - не выводит знак + перед положительным числом
    cout << noshowpos << 11 << endl;
    // showpoint - выводит точку даже если число целое
    cout << showpoint << 11 << endl;
    cout.unsetf(ios::showpoint);
    // noshowpoint - не выводит точку даже если число целое
    cout << noshowpoint << 11 << endl;
    // scientific - выводит число в экспоненциальной форме
    cout << scientific << 11 << endl;
    cout.unsetf(ios::scientific);
    // fixed - выводит число в обычной форме
    cout << fixed << 11 << endl;
    // left - выравнивание по левому краю
    cout << left << 11 << endl;
    // right - выравнивание по правому краю
    cout << right << 11 << endl;
    // internal - выравнивание по правому краю
    cout << internal << 11 << endl;
    // setfill - заполняет пустое место в строке символом
    cout << setfill('-') << 11 << endl;
    // setw - задает ширину поля
    cout << setw(12) << 11 << endl;
    // setprecision - задает точность вывода числа
    cout << setprecision(3) << 11 << endl;
    // setbase - задает основание системы счисления
    cout << setbase(8) << 11 << endl;
    // setiosflags - устанавливает флаги
    cout << setiosflags(ios::showbase) << 11 << endl;
    // resetiosflags - сбрасывает флаги
    cout << resetiosflags(ios::showbase) << 11 << endl;
     */
    //Задание 3
//    cout << left << cout.flags() << endl;
//    cout << right << cout.flags()<< endl;
    //Задание 4
    for (int i = 0; i < 7; i++)
        cout << endp << s;
    for (int i = 0; i < 7; i++)
        endp(cout, 5) << s << endl;
    for (int i = 0; i < 7; i++)
        fendp(cout, 5, "\n-------------\n") << s << endl;
    //Задание 5
    cout << "Задание 5." << endl;
    const int maxchar = 10;
    string str;
    cout << "Введите строку:" << endl;
    getline(cin, str);
    if (str.size() > maxchar) {
        cout << "The input is too Short." << endl;
    }
    cout << str << endl;
    cin.clear();
    fflush(stdin);
    string peek;
    cout << "Введите строку:" << endl;
    // функция peek для входных потоков извлекает cимвол из потока
    if (cin >> peek && cin.peek() == '\n' || cin.peek() == '\t') {
        cout << "Проверка peek (ввод $):" << endl;
    }
    // putback - оставляет заданный символ в потоке
    char ch;
    while (cin.get(ch) && ch != '$') {
        if (ch == '$') {
            cin.putback(ch);
        }
    }
    // ignore, удаляет \n
    int number;
    cout << "Введите число: ";
    cin >> number;
    cin.ignore();
    cout << "Вы ввели: " << number << "\n";
    return 0;
}

