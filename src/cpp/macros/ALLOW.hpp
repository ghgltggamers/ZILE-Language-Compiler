//  This file is a part of ZILE Compiler 2024 -v0.1 : Contains the ALLOW macro


#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

std::string ALLOW(std::string lang_zile){// Takes zile code as string and then returns the required cpp

    // keyword
    std::string keyword = "ALLOW ";

    // extracting the command from zile
    std::string command = lang_zile.substr(keyword.length()); // extracting the word after OS string length

    // for CIO - Console Input Output.
    if (command == "CIO"){

        // return cpp iostream
        return "#include <iostream>\n";

    }

    else {

        // return error
        return "err";
    }

}