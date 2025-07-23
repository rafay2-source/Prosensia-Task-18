#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    void display() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }

    bool operator>(const Complex& c) const {
        return this->magnitude() > c.magnitude();
    }

    float magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real and imaginary parts: ";
        in >> c.real >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2, c3;
    cin >> c1 >> c2;

    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;

    cout << "Difference: " << (c1 - c2) <
