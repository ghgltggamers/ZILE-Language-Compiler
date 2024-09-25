//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the IOV macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string IOV(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "IOV ";

    // extracting the command from zile
    std::string command = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after OS string length

    // FIRST
    std::string first = command.substr(0, command.find(","));
    std::string second = command.substr(command.find(",")+1);

    // cpp conversion
    std::string cpp;

    if (second.find("GOV_VALUE") != -1){
        cpp = "IOV(\"" + first + "\" , " + "GOV_VALUE" + ");\n"; // embedding the command to the IOB function
    }
    else {
        cpp = "IOV(\"" + first + "\" , \"" + second + "\");\n"; // embedding the command to the IOB function
    }

    // returning cpp
    return cpp;

}