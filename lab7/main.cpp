#include <iostream>
#include <cstring>

using namespace std;

// Task 1
// 1. template <class T, class T> T f(T x); // error: redeclaration of T
// 2. template <class T1, T2> void f(T1 x); // error: T2 is not a type
// 3. template<class T> T f(int x); // OK, but useless
// 4. inline template <class T> T f(T x, T y); // error: inline template is not allowed

template<typename T>
void swap(T &a, T &b) {
    T c(move(a));
    a = move(b);
    b = move(c);
}

template<class T>
const T &max_value(const T &a, const T &b) {
    std::cout << "Вызванна шаблонная функция max" << std::endl;
    return (a < b) ? b : a;
}

// specialization for char*
template<>
const char *const &max_value(const char *const &a, const char *const &b) {
    std::cout << "Вызванна специализация шаблонной функции max для char*" << std::endl;
    return (std::strcmp(a, b) < 0) ? b : a;
}

template<typename T1, typename T2>
class Complex {
private:
    // Действительная и мнимая части комплексного числа
    T1 re;
    T2 im;

public:
    Complex() = default;

    explicit Complex(T1 r) {
        re = r;
        im = 0;
    }

    Complex(T1 r, T2 i) {
        re = r;
        im = i;
    }

    ~Complex() = default;

    Complex &operator=(const Complex &c) {
        re = c.re;
        im = c.im;

        return (*this);
    }

    Complex &operator+=(Complex &c) {
        re += c.re;
        im += c.im;
        return *this;
    }

    Complex operator+(const Complex &c) {
        return Complex(re + c.re, im + c.im);
    }

    Complex operator-(const Complex &c) {
        return Complex(re - c.re, im - c.im);
    }

    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << "(" << c.re << ", " << c.im << ")";
        return out;
    }

    friend istream &operator>>(istream &in, Complex &c) {
        in >> c.re >> c.im;
        return in;
    }

};

template<class T>
class MATRIX {
private:
    T **M;
    int m;
    int n;
public:
    MATRIX() {
        n = m = 0;
    }


    MATRIX(int _m, int _n) {
        m = _m;
        n = _n;
        M = (T **) new T *[m];
        for (int i = 0; i < m; i++)
            M[i] = (T *) new T[n];
    }


    friend std::ostream &operator<<(std::ostream &out, const MATRIX &mat) {
        for (int i = 0; i < mat.m; i++) {
            cout << endl;
            for (int j = 0; j < mat.n; j++)
                cout << mat.M[i][j] << '\t';
        }
        cout << endl;
        return cout;
    }

    friend std::istream &operator>>(std::istream &in, MATRIX &mat) {
        for (int i = 0; i < mat.m; i++)
            for (int j = 0; j < mat.n; j++)
                in >> mat.M[i][j];
        return in;
    }

    MATRIX operator+(MATRIX mat) {
        if (this->n == mat.n and this->m == mat.m) {
            MATRIX res(mat.m, mat.n);
            for (int i = 0; i < res.m; i++)
                for (int j = 0; j < res.n; j++)
                    res.M[i][j] = this->M[i][j] + mat.M[i][j];
            return res;
        }
    }

    MATRIX operator-(MATRIX mat) {
        if (this->n == mat.n and this->m == mat.m) {
            MATRIX res(mat.m, mat.n);
            for (int i = 0; i < res.m; i++)
                for (int j = 0; j < res.n; j++)
                    res.M[i][j] = this->M[i][j] - mat.M[i][j];
            return res;
        }
    }

    template<class T1, class T2>
    friend MATRIX<double> operator+(MATRIX<T1> mat1, MATRIX<T2> mat2);

    template<class T1, class T2>
    friend MATRIX<double> operator-(MATRIX<T1> mat1, MATRIX<T2> mat2);
};

template<class T1, class T2>
MATRIX<double> operator+(MATRIX<T1> mat1, MATRIX<T2> mat2) {
    if (mat1.n == mat2.n and mat1.m == mat2.m) {
        MATRIX<double> res(mat2.m, mat2.n);
        for (int i = 0; i < res.m; i++)
            for (int j = 0; j < res.n; j++)
                res.M[i][j] = mat1.M[i][j] + mat2.M[i][j];
        return res;
    }
    return {};
}

template<class T1, class T2>
MATRIX<double> operator-(MATRIX<T1> mat1, MATRIX<T2> mat2) {
    if (mat1.n == mat2.n and mat1.m == mat2.m) {
        MATRIX<double> res(mat2.m, mat2.n);
        for (int i = 0; i < res.m; i++)
            for (int j = 0; j < res.n; j++)
                res.M[i][j] = mat1.M[i][j] + mat2.M[i][j];
        return res;
    }
    return {};
}

template<class T, int S>
class Stack {
private:
    int size;
    T top{};
    T *stackPtr;
public:
    Stack();

    void push(T);

    T pop();

    void printStack();

    ~Stack();
};

template<class T, int S>
Stack<T, S>::Stack() {
    size = S;
    stackPtr = new T[size];
    top = -1;
}

template<class T, int S>
Stack<T, S>::~Stack() {
    delete[] stackPtr;
}

template<class T, int S>
void Stack<T, S>::push(T value) {
    if (top == size - 1) {
        cout << "Stack is full" << endl;
    } else {
        top++;
        stackPtr[top] = value;
    }
}

template<class T, int S>
T Stack<T, S>::pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        top--;
        return stackPtr[top + 1];
    }
}

template<class T, int S>
void Stack<T, S>::printStack() {
    for (int i = 0; i <= top; i++) {
        cout << stackPtr[i] << endl;
    }
}

int main() {
    // Task 2
    cout << "Task 2" << endl;
    int a = 5, b = 4;
    string c = "sss", d = "qqq";
    // swap(a, b);
    swap(c, d);
    cout << a << "\t" << b << endl;
    cout << c << "\t" << d << endl;
    // Task 3
    cout << "Task 3" << endl;
    cout << max_value('a', '1') << endl;
    cout << max_value(0, 1) << endl;
    // specialization for char*
    const char *s1 = "Hello";
    const char *s2 = "World";
    cout << max_value(s1, s2) << endl;
    // Task 4
    cout << "Task 4" << endl;
    Complex<int, int> ch(1, 4);
    Complex<float, float> ch1(1.1, 2.3);
    Complex<float, float> ch2(1.2, 2.4);
    cout << ch << endl;
    cout << ch1 << endl;
    cout << ch1 + ch2 << endl;
    MATRIX<int> M1(2, 2);
    cout << "Enter matrix 1:" << endl;
    cin >> M1;
    cout << M1 << endl;
    MATRIX<double> M2(2, 2);
    cout << "Enter matrix 2:" << endl;
    cin >> M2;
    cout << M2 << endl;
    cout << M1 + M2 << endl;
    cout << M1 - M2 << endl;
    // Task 5
    cout << "Task 5" << endl;
    Stack<int, 10> st;
    st.push(10);
    st.push(22);
    st.push(33);
    st.printStack();
    st.pop();
    st.printStack();
    return 0;
}
