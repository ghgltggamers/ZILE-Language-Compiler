//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the MOV macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string MOV(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "MOV ";

    // extracting the command from zile
    std::string command = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after OS string length

    // FIRST
    std::string first = command.substr(0, command.find(","));
    std::string second = command.substr(command.find(",")+1);

    std::string first_final = "";
    std::string second_final = "";
    if (first.find("MACRO ") != -1){
        std::string key_macro = "MACRO ";
        first_final = first.substr(first.find(key_macro) + key_macro.length());
    }
    else {
        first_final = "\"" + first + "\"";
    }


    if (second.find("MACRO ") != -1){
        std::string key_macro = "MACRO ";
        second_final = second.substr(second.find(key_macro) + key_macro.length());
    }
    else {
        second_final = "\"" + second + "\"";
    }

    std::string cpp = "MOV(" + first_final + " , " + second_final + ");\n"; // embedding the command to the MOV function

    // cpp conversion
    // std::string cpp = "MOV(\"" + first + "\" , \"" + second + "\");\n"; // embedding the command to the MOV function

    // returning cpp
    return cpp;

}