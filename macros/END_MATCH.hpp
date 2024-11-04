//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the ECMAIN macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string END_MATCH(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "END_MATCH"; // ECMAIN stops the CMAIN

    // returning the cpp main
    return "}\n";

}