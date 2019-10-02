#include <iostream>
#include <cstdlib>

#include "controller.hpp"

Controller::Controller(){
    action();
}

void Controller::action(){
    switch(view.action()){
        case 1:
            runMachine();
            break;
        case 2:
            info();
            break;
        case 3:
            action();
            break;
    }
}

void Controller::runMachine(){
    std::string fileName;
    fileName = view.runMachine();
    std::cout << "Running " << fileName << std::endl; 
    turingMachine.loadFile(fileName);
    printf("\n\tFile loaded.\n\tTape:\n\t");
    turingMachine.printTape();
    printf("\nPress enter to see an alghorytm...\n");
    getchar();
    printf("\n\tAlgorithm:\n");
    turingMachine.printStates();
    printf("\nPress enter to run machine...\n");
    getchar();
    turingMachine.execute();
    printf("\nPress enter to see the final tape...\n");
    getchar();
    turingMachine.printTape();
    printf("\nPress enter to back to the main menu...\n");
    getchar();
    action();
}

void Controller::info(){
    view.showInfo();
    printf("\n\nPress enter to back to the main menu...\n");
    std::cin.get();
    getchar();
    action();
}