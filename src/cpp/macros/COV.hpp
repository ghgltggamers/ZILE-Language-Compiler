//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the COV macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string COV(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "COV ";

    // extracting the command from zile
    std::string command = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after OS string length

    // cpp conversion
    std::string cpp = "COV(\"" + command + "\");\n"; // embedding the command to the COV function

    // returning cpp
    return cpp;

}