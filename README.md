<!-----------------------------------------------------------------
Name: Blake Meyers(cssc0430, Red id: 819557369), Darpan Beri(cssc0429, Red id: 820880704), Zach Selchau(cssc0418, Red id: 820533188)
 Project: CS530 Assignment 2
 File: README.md
 Notes: A README file describing the program and detailing its files.
--------------------------------------------------------------------->

## CS-530, Spring 2019 Assignment 2
### Developed by Blake Meyers(cssc0430, Red id: 819557369), Darpan Beri(cssc0429, Red id: 820880704), Zach Selchau(cssc0418, Red id: 820533188)

#### The Program:
    Opens an SIC/XE object file, and its accompanying symbol file.
    Then it will disassemble the object code, and generate an SIC/XE source file, and SIC/XE listing file using the assembled code.

#### Files Included:
**README.md**:

    A README file describing the program and detailing its files.

**xed.cpp**:

    The file cointains an algorithm that opens an SIC/XE object file and its accompanying symbol file, which then disassembles the object code, and generate an SIC/XE source file, and SIC/XE listing file using the assembled code.

**xed.hpp**:

    Declares and briefly explains functions implemented in xed.cpp.

**Makefile**:

    Creates a compiled version of xed.cpp.

#### Compilation Instructions:
**Make Instructions:**

    make all:
    	compiles the xed file

    make clear:
    	deletes the xed file, the <filename>.sic file, and the <filename>.lis file

**Running the Program:**

    xed <filename>

**NOTE:** <> are not part of the command.

#### Operating Instructions:
**Required Input**:

    The input filename needs to be the filename that has a .obj and a .sym file extension.
        The .obj file needs to be an object file of SIC/XE machine.
        The .sym file needs to be a symtab and littab file for the SIC/XE machine,

#### Significant Design Decisions:
    The data from the .sym file is stored in a linked list.
    We store interpreted text records inside a vector while we are reading the object file.

#### Extra features:

    Makefile also cleans <filename>.sic and <filename>.lis in addition to the required xed.

#### Known Deficiencies and Bugs:
**Known Bugs and Deficiencies**
    If a LDB command is encountered and it is not immediate addressing, we do not know what is in the base register and therefore cannot calculate base relative addressing.

#### Lessons Learned:
* An algorithm and design takes 1 month to figure out. The actual implementation requires 1 week.
* Quality of work matters over the quantity of work done.
* Pair programming works well with small groups.
* Software Design Document helps to plan out the approach to deal with a problem.
* Motivation is important for teams.
* Check for compatability with target system.
<!-----------------------------------------[ EOF: README.md ]--------------------------------->