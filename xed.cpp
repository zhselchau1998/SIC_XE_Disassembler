#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>
#include <cstring>
#include <cstdio>
#include <sstream>

using namespace std;
/*
    Pseduo code as of now:
        1. We check for correct input:
            a. Check for actual argument
            b. check for existence for .obj and .sym file
        1.b If check fail, do graceful exit

        2. Initalize .sic and .lis files. Maybe make one more intermediatory file for debugging purposes.
            a. Create file via C++.

        3. Algorithm for disassembling
            a. Read the .obj and .sym file.
            b. Interpret the contents via code.
            c. Write line by line? or store in intermediatory file and then write to .lis and .sic.

        3.5  Writing it to files
            d. Write the .lis file
            e. Write the .sic file
*/

bool fileExists(string filename){
    FILE* fp;
    if(fp = fopen(filename.c_str(), "r")){
        fclose(fp);
        return true;
    }
    return false;
}

bool fileExists(const char* filename){
    FILE* fp;
    if(fp = fopen(filename, "r")){
        fclose(fp);
        return true;
    }
    return false;
}

int hexToDecimal(string num){
    int x;
    stringstream ss;

    ss << hex << "0"+num;
    ss >> x;

    return x;
}

//Returns a 6 char string
string hexToCommand(string hex){
    int x = hexToDecimal(hex);
    x /= 4;

    //Produces an error on 8C, CC, and E4
    switch(x){//command library
        case 0://00
            return "LDA   ";
            break;
        case 1://04
            return "LDX   ";
            break;
        case 2://08
            return "LDL   ";
            break;
        case 3://0C
            return "STA   ";
            break;
        case 4://10
            return "STX   ";
            break;
        case 5://14
            return "STL   ";
            break;
        case 6://18
            return "ADD   ";
            break;
        case 7://1C
            return "SUB   ";
            break;
        case 8://20
            return "MUL   ";
            break;
        case 9://24
            return "DIV   ";
            break;
        case 10://28
            return "COMP  ";
            break;
        case 11://2C
            return "TIX   ";
            break;
        case 12://30
            return "JEQ   ";
            break;
        case 13://34
            return "JGT   ";
            break;
        case 14://38
            return "JLT   ";
            break;
        case 15://3C
            return "J     ";
            break;
        case 16://40
            return "AND   ";
            break;
        case 17://44
            return "OR    ";
            break;
        case 18://48
            return "JSUB  ";
            break;
        case 19://4C
            return "RSUB  ";
            break;
        case 20://50
            return "LDCH  ";
            break;
        case 21://54
            return "STCH  ";
            break;
        case 22://58
            return "ADDF  ";
            break;
        case 23://5C
            return "SUBF  ";
            break;
        case 24://60
            return "MULF  ";
            break;
        case 25://64
            return "DIVF  ";
            break;
        case 26://68
            return "LDB   ";
            break;
        case 27://6C
            return "LDS   ";
            break;
        case 28://70
            return "LDF   ";
            break;
        case 29://74
            return "LDT   ";
            break;
        case 30://78
            return "STB   ";
            break;
        case 31://7C
            return "STS   ";
            break;
        case 32://80
            return "STF   ";
            break;
        case 33://84
            return "STT   ";
            break;
        case 34://88
            return "COMPF ";
            break;
        case 35://8C
            return "ERROR ";
            break;
        case 36://90
            return "ADDR  ";
            break;
        case 37://94
            return "SUBR  ";
            break;
        case 38://98
            return "MULR  ";
            break;
        case 39://9C
            return "DIVR  ";
            break;
        case 40://A0
            return "COMPR ";
            break;
        case 41://A4
            return "SHIFTL";
            break;
        case 42://A8
            return "SHIFTR";
            break;
        case 43://AC
            return "RMO   ";
            break;
        case 44://B0
            return "SVC   ";
            break;
        case 45://B4
            return "CLEAR ";
            break;
        case 46://B8
            return "TIXR  ";
            break;
        case 47://BC
            return "SUBR  ";
            break;
        case 48://C0
            return "FLOAT ";
            break;
        case 49://C4
            return "FIX   ";
            break;
        case 50://C8
            return "OR    ";
            break;
        case 51://CC
            return "ERROR ";
            break;
        case 52://D0
            return "LPS   ";
            break;
        case 53://D4
            return "STI   ";
            break;
        case 54://D8
            return "RD    ";
            break;
        case 55://DC
            return "WD    ";
            break;
        case 56://E0
            return "TD    ";
            break;
        case 57://E4
            return "ERROR ";
            break;
        case 58://E8
            return "STSW  ";
            break;
        case 59://EC
            return "SSK   ";
            break;
        case 60://F0
            return "SIO   ";
            break;
        case 61://F4
            return "HIO   ";
            break;
        case 62://F8
            return "TIO   ";
            break;
    }

    return "ERROR";
}


int main(int argc, char* argv[]){
    //Case 1: there are no arguments passed
    if(argc != 1){};//exit()

    //Case 2: obj or sym file dne
    string objFile (argv[1]);
    string symFile = objFile + ".sym";
    objFile = objFile + ".obj";
    if(!fileExists(objFile) || !fileExists(symFile)){};//exit()

}


// Make Graceful exit function which includes tailored exit messages

/*
    Input                   Output
    <filename>.obj           <filename>.sic
    <filename>.sym           <filename>.lis

    % xed <filename>
    
*/

/*
    Tips from prof:

    Graceful Exit:
        exit() -> Test return value on every system call. Int error handling routine
    
    Don't use templates in C++.
    Use C versions of I/O commands
*/
