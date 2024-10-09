//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the COV macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string GOV(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "GOV ";

    // extracting the command from zile
    std::string command = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after OS string length


    std::string command_final = "";

    if (command.find("MACRO ") != -1){
        std::string key_macro = "MACRO ";
        command_final = command.substr(command.find(key_macro) + key_macro.length());
    }
    else {
        command_final = "\"" + command + "\"";
    }
    // cpp conversion
    std::string cpp = "GOV(" + command_final + ");\n"; // embedding the command to the GOV function

    // returning cpp
    return cpp;

}