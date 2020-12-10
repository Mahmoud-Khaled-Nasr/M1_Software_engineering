#include <iostream>

#include "Rectangle_ex1_ex2.h"
#include "Complex_ex3.h"

void problem_1_and_2();

void problem_3();

int main() {
    problem_1_and_2();
    problem_3();
}

void problem_3() {
    std::cout << "\n\tProblem 3\nPlease enter the first complex number: ";
    double x, y;
    std::cin >> x >> y;
    Complex_ex3 c1 = Complex_ex3(x, y);
    std::cout << "The first complex is: " << c1 << "\nEnter the second complex: ";
    std::cin >> x >> y;
    Complex_ex3 c2 = Complex_ex3(x, y);
    std::cout << "The second complex is: " << c2 << "\nThe sum is: " << c1 + c2;
}

void problem_1_and_2() {
    std::cout << "\tAssignment 4\n\n\tProblem 1 and 2\nEnter two numbers:";
    double l, w;
    std::cin >> l >> w;
    Rectangle_ex1_ex2 rect = Rectangle_ex1_ex2(l, w);
    std::cout << "The input is: " << l << ", " << w << "\nThe area is: " << rect.get_area()<<"\nThe sum is: "
    << rect.get_sum() << std::endl;
}
