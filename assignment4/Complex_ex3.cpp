//
// Created by mk on 12/10/2020.
//

#include "Complex_ex3.h"

Complex_ex3::Complex_ex3(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex_ex3 Complex_ex3::operator+(Complex_ex3 &c2) {
    return Complex_ex3(this->real + c2.real, this->imaginary + c2.imaginary);
}

std::ostream &operator<<(std::ostream &output, const Complex_ex3 &c) {
    return output << "Complex: " << c.real << " + " << c.imaginary <<"i";
}


