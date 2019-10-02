#pragma once

#include <string>
#include <map>
#include <vector>
#include <string>

class View {
    public:
        int action();
        std::string runMachine();
        void showInfo();
    private:
        void clearScreen();
        void header(); 
};