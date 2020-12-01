//
// Created by mk on 12/1/2020.
//

#include "ZooAnimal.h"

void ZooAnimal::Destroy (){
    delete[] name;
}


// -------- member function to return the animal's name

char* ZooAnimal::reptName (){
    return name;
}


// -------- member function to return the number of days
// -------- since the animal was last weighed

int ZooAnimal::daysSinceLastWeighed(int today){

    int startday, thisday;
    thisday = today/100*30 + today - today/100*100;
    startday = weightDate/100*30 + weightDate - weightDate/100*100;

    if (thisday < startday){
        thisday += 360;
    }

    return (thisday-startday);

}

void ZooAnimal::Create(std::string name_p, int cageNumber_p, int weightData_p, int weight_p) {
    this->name = new char [name_p.length() + 1];
    strcpy(this->name, name_p.c_str());
    this->cageNumber = cageNumber_p;
    this->weight = weight_p;
    this->weightDate = weightData_p;
}

void ZooAnimal::isMotherOf(ZooAnimal &mother_p) {
    this->mother = &mother_p;
}
