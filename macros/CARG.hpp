//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the CO macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string CARG(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "CARG ";

    // extracting the command from zile
    std::string aplhabets = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after CO string length

    // cpp conversion
    std::string cpp;
    if (aplhabets.find("MACRO ") != -1){
        std::string key_macro = "MACRO ";
        std::string MACRO = aplhabets.substr(aplhabets.find(key_macro) + key_macro.length());
        cpp = "CARG_DATA = argv[" + MACRO + "];\n";
    }
    else {
        cpp = "CARG_DATA = argv[" + aplhabets + "];\n"; // embedding the command to the cout
    }
    // returning cpp
    return cpp;

}