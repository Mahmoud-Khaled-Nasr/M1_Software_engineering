#include <iostream>

#include "ZooAnimal.h"


int main() {
    ZooAnimal bozo;
    bozo.Create ("Bozo", 408, 1027, 400);

    std::cout << "This animal's name is " << bozo.reptName() << std::endl;
    bozo.Destroy ();
}
