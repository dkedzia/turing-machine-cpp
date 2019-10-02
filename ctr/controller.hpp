#pragma once

#include <string>
#include <map>
#include <vector>
#include <string>

#include "../view/view.hpp"
#include "../mod/maszyna.hpp"
#include "../mod/state.hpp"

class Controller {
    public:
        Controller();
        void action();
        void runMachine();
        void info();
    private:
        void clearScreen();
        void header(); 
        View view;
        TuringMachine turingMachine;
        int option;
};