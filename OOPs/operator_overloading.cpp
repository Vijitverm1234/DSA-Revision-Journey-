#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r, int i): real(r), imag(i) {}
    Complex operator+(const Complex& c) { // Operator overloading
        return Complex(real + c.real, imag + c.imag);
    }
    void display() { cout << real << " + " << imag << "i\n"; }
};

int main() {
    Complex c1(2,3), c2(4,5);
    Complex c3 = c1 + c2;  // Operator + is overloaded
    c3.display();
}
