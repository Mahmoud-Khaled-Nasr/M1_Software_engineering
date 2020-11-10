#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>


void problem1();
float compute_circle_circumference(float radius, float pi);
float compute_circle_area(float radius, float pi);

void problem2();
int* generate_random_list(int list_size);
void compute_list_min_max(const int*list, int list_size, int& max, int& min);

void problem3();
int compute_fibonacci_sequence(int*fibonacci_sequence_list, int current_fibonacci_element_index);

void problem4();

void problem5();
void compute_and_truth_table();
void compute_or_truth_table();

void print_line();


int main() {
    std::cout << "\tSolution of assignment 1!" << std::endl;
    print_line();
    print_line();
    problem1();
    print_line();
    problem2();
    print_line();
    problem3();
    print_line();
    problem4();
    print_line();
    problem5();
    print_line();
    print_line();
    return 0;
}

void print_line(){
    for (int i = 0; i < 50; ++i) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

// Problem 5
void problem5(){
    std::cout << "Problem 5\nThe truth tables are\n";
    compute_and_truth_table();
    compute_or_truth_table();

}

void compute_or_truth_table(){
    std::cout << "The truth table for or operation on three variables is:\n\tX\tY\tZ\tResult\n";
    print_line();
    for (unsigned int i = 0; i <= 1; ++i) {
        for (unsigned int j = 0; j <= 1; ++j) {
            for (unsigned int k = 0; k <= 1; ++k) {
                std::cout << "\t" << i << "\t" << j << "\t" << k << "\t" << int(i | j | k) << std::endl;
            }
        }
    }
}

void compute_and_truth_table(){
    std::cout << "The truth table for and operation on three variables is:\n\tX\tY\tZ\tResult\n";
    print_line();
    for (unsigned int i = 0; i <= 1; ++i) {
        for (unsigned int j = 0; j <= 1; ++j) {
            for (unsigned int k = 0; k <= 1; ++k) {
                std::cout << "\t" << i << "\t" << j << "\t" << k << "\t" << int(i & j & k) << std::endl;
            }
        }
    }
}


// Problem 4
void problem4(){
    std::cout << "Problem 4\nPlease enter the number for computing it's multiplication table:\n";
    int multiplication_value;
    std::cin >> multiplication_value;
    std::cout << "The multiplication table is:\n";
    for (int i = 1; i <= 10; ++i) {
        std::cout << "\t" << i << "*" << multiplication_value << ":\t" << i*multiplication_value << std::endl;
    }
}

// Problem 3
void problem3(){
    int fibonacci_sequence_size, fibonacci_rank;
    int* fibonacci_sequence_list;
    std::cout << "Problem 3\nPlease enter the fibonacci rank: \n";
    std::cin >> fibonacci_rank;
    fibonacci_sequence_size = fibonacci_rank + 1;
    assert(fibonacci_sequence_size > 0);
    fibonacci_sequence_list = new int [fibonacci_sequence_size];
    for (int i = 0; i < fibonacci_sequence_size; ++i) {
        fibonacci_sequence_list[i] = -1;
    }
    int result = compute_fibonacci_sequence(fibonacci_sequence_list, fibonacci_rank);
    std::cout << "The result is: " << result << std::endl;
    std::cout << "The full sequence is: [";
    for (int i = 0; i < fibonacci_sequence_size; ++i) {
        std::cout << fibonacci_sequence_list[i] << ", ";
    }
    std::cout << "]\n";
    delete fibonacci_sequence_list;
}

int compute_fibonacci_sequence(int*fibonacci_sequence_list, int current_fibonacci_element_index){
    if (current_fibonacci_element_index == 0){
        fibonacci_sequence_list[current_fibonacci_element_index] = 0;
    } else if (current_fibonacci_element_index == 1){
        fibonacci_sequence_list[current_fibonacci_element_index] = 1;
    }

    if (fibonacci_sequence_list[current_fibonacci_element_index] == -1){
        fibonacci_sequence_list[current_fibonacci_element_index] =
                compute_fibonacci_sequence(fibonacci_sequence_list, current_fibonacci_element_index - 1) +
                compute_fibonacci_sequence(fibonacci_sequence_list, current_fibonacci_element_index - 2);
    }
    return fibonacci_sequence_list[current_fibonacci_element_index];
}

// Problem 2
void problem2(){
    int list_size, min, max;
    int*list;

    std::cout << "Problem 2\nThe array used is generated randomly of size n\nPlease enter n:";
    std::cin >> list_size;
    assert(list_size > 0);
    list=generate_random_list(list_size);
    compute_list_min_max(list, list_size, max, min);
    std::cout << "For the list: [";
    for (int i = 0; i < list_size; ++i) {
        std::cout << list[i] << ", ";
    }
    std::cout << "]\nThe max: " << max <<" , the min is: " << min << std::endl;
    delete list;
}

int* generate_random_list(int list_size){
    srand(time(nullptr));
    int*list=new int[list_size];
    for (int i = 0; i < list_size; ++i) {
        list[i] = rand();
    }
    return list;
}

void compute_list_min_max(const int*list, int list_size, int& max, int& min){
    max = list[0];
    min = list[0];
    for (int i = 1; i < list_size; ++i) {
        if (max < list[i]){
            max = list[i];
        }
        if (min > list[i]){
            min = list[i];
        }
    }
}

//Problem 1
void problem1(){
    float diameter, pi=3.14;
    std::cout << "Problem 1:\nPlease enter the circle diameter:\n";
    std::cin >> diameter;
    std::cout << "For pi=3.14, The circle circumference is: "<< compute_circle_circumference(diameter/2, pi)
    << " and the area is: " << compute_circle_area(diameter/2, pi) << std::endl;
}

float compute_circle_circumference(float radius, float pi){
    return 2 * pi * radius;
}

float compute_circle_area(float radius, float pi){
    return pi * radius * radius;
}
