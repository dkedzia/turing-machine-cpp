// Maszyna turinga

#include "maszyna.hpp"

#include <iostream>

#include "state.hpp"

int main(){
    TuringMachine turingMachine("zamiana.xml");
    turingMachine.printStates();
    turingMachine.printTape();
    turingMachine.execute();
}