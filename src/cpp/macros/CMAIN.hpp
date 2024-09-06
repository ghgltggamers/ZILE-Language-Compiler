//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the CMAIN macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string CMAIN(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "CMAIN"; // CMAIN means Console Main function which runs when ever the bin runs

    // returning the cpp main
    return "int main(int argc, char * argv[]){\n";

}