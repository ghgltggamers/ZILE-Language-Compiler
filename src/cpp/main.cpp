/*

    Copyright (c) ghgltggamer 2024
    ZILE Compiler v0.1 - 2024 : Zile language compiler
    This file is the main ZILE Compiler file containing all the required code
    Written officiaally by ghgltggamer
    ZILE OpenSource Programming Language 2024
    Contributions and modifications are allowed as this project is under the MIT License stored in LICENSE.txt file
    started writting on : 06/09/2024 at 04:41pm

    Why zile was developed : ZILE was started for compiling to a direct binary file which can directly be executed by the cpu and for writting low level programs 

*/

// Including the macros filee
#include "macros.hpp"
#include   <iostream>
#include    <fstream>
#include     <string>
#include   <string.h>
#include      <cmath>

// main function
int main(int argc, char * argv[]){

    // storing the file name given to zile
    std::string file_name_zile = argv[1];

    if (file_name_zile.find(".zile") != -1){

        // checking for opened files
        std::ifstream code_file(file_name_zile);

        if (code_file.is_open()){

            // FILE READER
        
            // Storing for code;
            std::string code;
            int line_number = 1;
            std::string cpp = "// BFCPP :- \n\n// This file is only the compilation part of ZILA System level Lang, Please do not modify this file without proper knowledge of how ZILA treates .cpp files and how these are going to be compiled\n\n";

            // reading file line by line
            while (std::getline(code_file, code)){

                // this will execute per line so add your custom zile macros right here as functions and make sure to write the actuall macro functions in a .hpp file and include it in macros.hpp file, ZILE Standard macros files are stored in macros dir
                // checking for ALLOW macro
                if (code.find("ALLOW ") != -1){
                    if (ALLOW(code) != "err"){
                        cpp += ALLOW(code);
                        line_number += 1;
                        continue;
                    }
                    else {
                        break;
                        std::cout<<"ZILA Syntax ERROR found on line number "<<line_number<<", Unknown ZSYSARG found for ALLOW. ALLOW can only ALLOW executing valid SYSARG";
                    }
                }
                 // checking for ECMAIN macro
                else if (code.find("ECMAIN") != -1){
                    cpp += ECMAIN(code);
                    line_number += 1;
                    continue;
                }
                 // checking for CMAIN macro
                else if (code.find("CMAIN") != -1){
                    cpp += CMAIN(code);

                    line_number += 1;
                    continue;
                }
                 // checking for OS macro
                else if (code.find("OS ") != -1){
                    cpp += OS(code);
                    line_number += 1;
                    continue;
                }
                 // checking for ; macro
                else if (code.find(";") != -1){
                    continue;
                }
                 // checking for '' macro
                else if (code.find("") != -1){
                    continue;
                }
                // checking for macro EXIT
                else if (code.find("EXIT") != -1){
                    cpp += "exit ( 3 );";
                    continue;
                }
                else {
                    break;// exit the file reader
                    std::cout<<"ZILA Syntax ERROR found on line number "<<line_number<<", Unknown identifier or MACRO found";
                }

            }

            // building the c++ file
            std::ofstream BFCPP(file_name_zile + ".cpp");// BFCPP stands for Build File C Plus Plus
            // writting and signing the BFCPP
            BFCPP<<cpp<<"\n\n// End of BFCPP";


            // finally compiling the ZILE-CPP
            std::string sys_exec_command = "g++ " + file_name_zile + ".cpp";

            // std::system(sys_exec_command.c_str()); this has a problem leter which will be fixed

        }
        else {
            std::cout<<"\n\n ZILE Fatal error -> file doesnot exists";
        }

    }
    else {
        std::cout<<"\n\n ZILE Fatal error -> a zile file was not found for compilation \n\n";
    }

}


// ended on 06/09/2024 by ghgltggamer officially on 06::39pm the very first compiler beta version still in development