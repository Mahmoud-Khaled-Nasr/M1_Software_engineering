//
// Created by mk on 12/10/2020.
//

#ifndef ASSIGNEMTN4_COMPLEX_EX3_H
#define ASSIGNEMTN4_COMPLEX_EX3_H

#include <ostream>

class Complex_ex3 {

private:
    double real, imaginary;
public:
    Complex_ex3(double real, double imaginary);
    Complex_ex3 operator+(Complex_ex3& c2);
    friend std::ostream &operator<<( std::ostream &output, const Complex_ex3& c);

};


#endif //ASSIGNEMTN4_COMPLEX_EX3_H
