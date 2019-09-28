// Maszyna turinga

#include "Tape.hpp"
#include "Instructions.hpp"
#include "FileParser.hpp"
#include<iostream>

int main(){
    std::cout << "Maszyna Turinga" << std::endl;
    Tape tape;
    tape.moveP();

    Instructions instructions;
    instructions.addRecord(11, "StrIn", "StrOut", 66);

    FileParser fileParser("test");
    fileParser.execute();
}