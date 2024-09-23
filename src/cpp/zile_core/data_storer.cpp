// This file is for testing purose of the data_storer.hpp file
#include "data_storer.hpp"
#include <iostream>

int main(){
    // COV("myVector");
    // IOV("myVector", "Hellow world 2024");

    // COV("myVector2");

    // GOV("myVector");
    // GOV("myVector2");

    // std::cout<<GOV_VALUE;

    // MOV("myVector", "myVector2");


    ROV(
        "myVector", "myVector2"
    );
}