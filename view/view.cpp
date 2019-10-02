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
    printf("\n\tTuring Machine\n\n\tAuthor:\tDominik Kedzia\t\n\tVer:\t1.0\n\n>\n");
}

int View::action(){
    header();
    printf("\n\tChoose one to continue:\n\t1. Run machine\n\t2. How to prepare machine?\n\t3. Reload this screen\n\t4. Exit\n\t>\n\t");
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
    printf("All alghotytms must be in ./alg/ folder.\n\n\t*.xml structure:\n");
}