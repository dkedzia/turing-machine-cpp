#include "Instructions.hpp"

Instructions::Instructions()
    :type instr[100]
{}
void Instructions::addRecord(int q, std::string input, std::string output, int qOutput){
    instr[0].q = q;
    instr[0].input = input;
    instr[0].output = output;
    instr[0].qOutput = qOutput;

    std::cout << "q:" << instr[0].q << std::endl;
}