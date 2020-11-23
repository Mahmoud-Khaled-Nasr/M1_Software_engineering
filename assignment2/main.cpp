#include <iostream>
#include <cassert>

#include "headers.h"

int main() {
    std::cout << "\tSecond Assignment" << std::endl;
    print_line();
    print_line();
    calculator();
    print_line();
    draw_pascal_triangle();
    print_line();
    max_value();
    print_line();
    read_print_list();
    print_line();
    sort_list();
    return 0;
}

void print_line(){
    for (int i = 0; i < 50; ++i) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void calculator(){
    char cont;
    do {
        std::cout << "Calculator menu:\n\t1- Add\n\t2- Subtract\n\t3- Multiply\n\t4- Division\n\t5- Modulus\n";
        int operation;
        std::cout << "Please enter your operation:\n";
        std::cin >> operation;
        assert(operation >= 1 && operation <= 5);
        std::cout << "Enter the two numbers:\n";
        float x, y;
        std::cin >> x >> y;
        std::cout << "Result: ";
        switch (operation) {
            case 1:
                std::cout << x + y;
                break;
            case 2:
                std::cout << x - y;
                break;
            case 3:
                std::cout << x * y;
                break;
            case 4:
                std::cout << x / y;
                break;
            case 5:
                std::cout << int(x) % int(y);
                break;
        }
        std::cout << "\nDo you want to try again (y)?";
        std::cin >> cont;
    } while (cont == 'y');
}

int** create_zero_2d_array(int size){
    int** list = new int*[size];
    for (int i = 0; i < size; ++i) {
        list[i] = new int[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            list[i][j] = 0;
        }
    }
    return list;
}

void delete_2d_array(int**list, int size){
    for (int i = 0; i < size; ++i) {
        delete [] list[i];
    }
    delete [] list;
}

void draw_pascal_triangle(){
    std::cout << "Please enter the Size of the Pascal triangle:\n";
    int triangle_size;
    std::cin >> triangle_size;
    assert(triangle_size > 2);
    int** triangle = create_zero_2d_array(triangle_size);
    triangle[0][0] = 1;
    for (int i = 1; i < triangle_size; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (j>0){
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
            } else {
                triangle[i][j] = triangle[i - 1][j];
            }
        }
    }

    for (int i = 0; i < triangle_size; ++i) {
        for (int j = 0; j < triangle_size; ++j) {
            int temp;
            if (triangle[i][j] == 0){
                std::cout << " " << "\t";
            } else {
                std::cout << triangle[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
    delete_2d_array(triangle, triangle_size);
}

void max_value(){
    std::cout << "Compute max value of list\nEnter the size of the list: \n";
    int list_size;
    std::cin >> list_size;
    assert(list_size>0);
    int* list = new int[list_size];
    for (int i = 0; i < list_size; ++i) {
        std::cout << "Enter Value " << i + 1 << " : ";
        std::cin >> list[i];
    }
    int* max_element = get_list_max(list, list_size);
    std::cout << "The max value is: " << *max_element << std::endl;
    delete [] list;
}

int* get_list_max(int* list, int size){
    int max = list[0];
    int max_index = 0;
    for (int i = 1; i < size; ++i) {
        if (max < list[i]){
            max = list[i];
            max_index = i;
        }
    }
    return list + max_index;
}

void read_print_list(){
    std::cout << "Read and print array\nEnter the five values of the list:\n";
    const int size = 5;
    int* list = new int [size];
    for (int i = 0; i < size; ++i) {
        std::cin >> list[i];
    }

    std::cout << "The output list is: [";
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << ", ";
    }
    std::cout << "]\n";
    delete [] list;
}

void sort_list(){
    std::cout << "Sorting a list\nPlease enter the list size:\n";
    int list_size;
    std::cin >> list_size;
    std::cout << "Enter the list values\n";
    int* list = new int[list_size];
    for (int i = 0; i < list_size; ++i) {
        std::cin >> list[i];
    }
    int* sorted_list = selection_sort(list, list_size);
    std::cout << "The sorted list is: \n[";
    for (int i = 0; i < list_size; ++i) {
        std::cout << sorted_list[i] << ", ";
    }
    std::cout << "]";
    delete [] list;
    delete [] sorted_list;
}

int* selection_sort(const int* list, int list_size){
    int* new_list = new int [list_size];
    for (int i = 0; i < list_size; ++i) {
        new_list[i] = list[i];
    }

    int min, min_index;
    for (int i = 0; i < list_size; ++i) {
        min = new_list[i];
        min_index = i;
        for (int j = i; j < list_size; ++j) {
            if (min > new_list[j]){
                min = new_list[j];
                min_index = j;
            }
        }
        int temp = new_list[min_index];
        new_list[min_index] = new_list[i];
        new_list[i] = temp;
    }
    return new_list;
}

