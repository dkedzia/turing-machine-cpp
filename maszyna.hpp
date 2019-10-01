#pragma once

#include <string>
#include <map>
#include <vector>
#include <string>

#include "state.hpp"

class TuringMachine {
    public:
        TuringMachine(const std::string& filename);

        void execute();
        void printStates();
        void printTape();
    private:
        std::map<std::string, State> machineStates;
        std::vector<std::string> tape;
        State* currentState = nullptr;
        int tapePosition = 0;
        std::string startState;
        std::string endState;
};