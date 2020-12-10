//
// Created by mk on 12/10/2020.
//

#include "Rectangle_ex1_ex2.h"

Rectangle_ex1_ex2::Rectangle_ex1_ex2(double length, double width) {
    this->length = length;
    this->width = width;
}

double Rectangle_ex1_ex2::get_area() {
    return length * width;
}

double Rectangle_ex1_ex2::get_sum() {
    return length + width;
}
