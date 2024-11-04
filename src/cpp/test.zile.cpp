// BFCPP :- 

// This file is only the compilation part of ZILA System level Lang, Please do not modify this file without proper knowledge of how ZILA treates .cpp files and how these are going to be compiled

#include <iostream>
std::string CI_DATA;
#include <fstream>

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
        int main(int argc, char * argv[]){
std::string CARG_DATA = argv[0];
CARG_DATA = argv[1];
if(CARG_DATA == "--version"){
std::cout<<"zile test version 1.2";
}else if("CARG_DATA" == "version"){
std::cout<<"zile test version 1.3";
}else {std::cout<<"a valid command required";
}
}


// End of BFCPP