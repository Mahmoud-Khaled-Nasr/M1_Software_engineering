//
// Created by mk on 12/1/2020.
//

#ifndef ASSIGNMENT3_ZOOANIMAL_H
#define ASSIGNMENT3_ZOOANIMAL_H

#include <cstring>
#include <iostream>


class ZooAnimal
{

private:

    char *name;
    int cageNumber;
    int weightDate;
    int weight;
    ZooAnimal *mother;

public:

    // The create function I created it separately by it should be the constructor
    void Create(std::string name_p, int cageNumber_p, int weightData_p, int weight_p);

    void Destroy (); // destroy function
    char* reptName ();
    int daysSinceLastWeighed (int today);
    inline int reptWeightDate() {
        return this->weightDate;
    }
    inline void changeWeightDate (int today){
        this->weightDate = today;
    }
    void isMotherOf (ZooAnimal& mother_p);

};


#endif //ASSIGNMENT3_ZOOANIMAL_H
