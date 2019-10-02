/*
|------------------------------------------------
|   Turing Machine
|   Main file
|------------------------------------------------
*/
#include <iostream>

#include "./mod/maszyna.hpp"
#include "./mod/state.hpp"

int main(){
    TuringMachine turingMachine("zamiana.xml");
    turingMachine.printStates();
    turingMachine.printTape();
    turingMachine.execute();
}