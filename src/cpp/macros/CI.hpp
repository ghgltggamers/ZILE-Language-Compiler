//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the CI macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string CI(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "CI ";

    // extracting the command from zile
    std::string aplhabets = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after CI string length

    // cpp conversion
    std::string cpp;
    cpp = "std::cout<<\"" + aplhabets + "\";\nstd::cin>>CI_DATA;\n"; // embedding the command to the cout
    // returning cpp
    return cpp;

}