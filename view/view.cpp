#include <iostream>
#include <cstdlib>

#include "view.hpp"

void View::clearScreen(){
    #ifdef WINDOWS
        std::system("cls");
    #else
        // Assume POSIX
        std::system ("clear");
    #endif
}


void View::header(){
    clearScreen();
    printf("\n\tTuring Machine\n\n\tAuthor:\tDominik Kedzia\t\n\tVer:\t1.0\n\n> - - - - - - - - - - - - - - - - -\n");
}

int View::action(){
    header();
    printf("\n\tChoose one to continue:\n\t1. Run machine\n\t2. How to prepare machine?\n\t3. Reload this screen\n\tAny other key to exit\n\t>\n\t");
    int option;
    std::cin >> option;
    return option;
}

std::string View::runMachine(){
    std::string fileName;
    header();
    printf("\n\tMake sure, that *.xml file with Turing Machine you'd like to run is in the folder ./alg\n\tType file name (with '*.xml'): ");
    std::cin.get();
    std::getline(std::cin, fileName);
    std::cout << fileName << std::endl;
    return fileName;
}

void View::showInfo(){
    header();
    printf("All alghotytms must be in ./alg/ folder.\n\n\t*.xml structure:\n\n\n");
    printf("root node 'turing'\n");
        printf("\tstart state node\n");
            printf("\t\tstarte state node attribute name\n");
        printf("\tend of start state node\n");
        printf("\tend state node\n");
            printf("\t\tend state node attribute name\n");
        printf("\tend of end state node\n");
        printf("\tstate nodes\n");
            printf("\t\tstate nodes attribute name\n");
            printf("\t\tstate transition nodes\n");
                printf("\t\t\tstate transition node attribute tape symbol\n");
                printf("\t\t\tstate transition node attribute next state\n");
                printf("\t\t\tstate transition node attribute new symbol\n");
                printf("\t\t\tstate transition node attribute movemenct direction\n");
            printf("\t\tend of state transition nodes\n");
        printf("\tend of state nodes\n");
        printf("\ttape node\n");
            printf("\t\tsymbol nodes\n");
                printf("\t\t\tsymbol node attribute content\n");
            printf("\t\tend of symbol nodes\n");
        printf("\tend of tape node\n");
    printf("end of root node 'turing'\n");
}