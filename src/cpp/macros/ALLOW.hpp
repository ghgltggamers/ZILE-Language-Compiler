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
    std::string command = lang_zile.substr(lang_zile.find(keyword) + keyword.length()); // extracting the word after OS string length

    // for CIO - Console Input Output.
    if (command == "CIO"){

        // return cpp iostream
        return "#include <iostream>\nstd::string CI_DATA;\n";

    }
    // for FIO - File Input Output
    else if (command == "FIO"){
        return "#include <fstream>\n";
    }
    // for DS - Data Storer
    else if (command == "DS"){
        return R"(
int COV(std::string vname){// iN ZILE COV stands for Create Output Vector
    std::ofstream vector_Output(vname);
    return 1;
}



int IOV(std::string vname, std::string vdat){
    // we need to check weather vector exists or not
    std::ifstream input_Vector_Available(vname);

    if (input_Vector_Available.is_open()){
        std::ofstream input_Vector_Ready(vname);
        input_Vector_Ready<<vdat;
    }
    else{
        std::cout<<"\n\nIOV Can not exactly insert the vector data into an Virtual vector you need to create a vector using COV\n\n";
        return 0;
    }
    return 1;
}

std::string GOV_VALUE;
int GOV(std::string vname){
    std::ifstream input_Vector_Available(vname);

    if (input_Vector_Available.is_open()){
        std::string vgov_value;

        while (std::getline(input_Vector_Available, vgov_value)){
            GOV_VALUE += vgov_value + "\n";
        }
    }
    else {
        std::cout<<"\n\nGOV can only return an physical vector\n\n";
    }
    return 1;
}

int FREE_GOV(){
    GOV_VALUE = "";
    return 1;
}





int MOV(std::string vin, std::string vout){
    FREE_GOV();
    GOV(vin);
    IOV(vout, GOV_VALUE);
    COV(vin);
    FREE_GOV();
    return 1;
}



int ROV(std::string v1, std::string v2){
    FREE_GOV();
    GOV(v1);
    const std::string v1_vvalue = GOV_VALUE;
    FREE_GOV();
    GOV(v2);
    const std::string v2_vvalue = GOV_VALUE;
    FREE_GOV();
    IOV(v1, v2_vvalue);
    IOV(v2, v1_vvalue);
    return 1;
}
        )";
    }

    else {

        // return error
        return "err";
    }

}