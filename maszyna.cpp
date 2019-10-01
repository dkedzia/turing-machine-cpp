
#include "maszyna.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "add/rapidxml-1.13/rapidxml.hpp"

TuringMachine::TuringMachine(const std::string& filename){
    rapidxml::xml_document<> document;
	rapidxml::xml_node<>* root_node;
    std::ifstream file("./alg/" + filename);

	if(!file.good()) {
		std::cout << "File error." << std::endl;
		return;	
	}

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    document.parse<0>(&buffer[0]);
    root_node = document.first_node("turing");

    for(rapidxml::xml_node<>* stateNode = root_node->first_node("state"); stateNode; stateNode = stateNode->next_sibling("state")) {
        State stateDefinition;
        stateDefinition.stateName = stateNode->first_attribute("name")->value();

        for(rapidxml::xml_node<>* transitionNode = stateNode->first_node("stateTransition"); transitionNode; transitionNode = transitionNode->next_sibling("stateTransition")) {
            StateTransition stateTransition;

            stateTransition.tapeSymbol = transitionNode->first_attribute("tapeSymbol")->value();
            stateTransition.nextState = transitionNode->first_attribute("nextState")->value();
            stateTransition.newSymbol = transitionNode->first_attribute("newSymbol")->value();
            
            std::string movementDirection = transitionNode->first_attribute("movementDirection")->value();
            if(movementDirection == "L") { stateTransition.movementDirection = Move::MOVE_LEFT; }
            else if(movementDirection == "R") { stateTransition.movementDirection = Move::MOVE_RIGHT; }
            else { stateTransition.movementDirection = Move::STAY; }

            stateDefinition.transitions[stateTransition.tapeSymbol] = stateTransition;
        }
  
        machineStates[stateDefinition.stateName] = stateDefinition; 
    }

    rapidxml::xml_node<>* tapeNode = document.first_node("turing")->first_node("tape");
    if(tapeNode == nullptr) {
        std::cerr << "DUPA DUPA DUPA" << std::endl;
        throw "No valid program present in xml file!";
    }

    for(rapidxml::xml_node<>* symbolNode = tapeNode->first_node(); symbolNode; symbolNode = symbolNode->next_sibling()){
        tape.push_back(symbolNode->first_attribute("content")->value());
    }

    rapidxml::xml_node<>* stState = document.first_node("turing")->first_node("startState");
    startState = stState->first_attribute("name")->value();

    rapidxml::xml_node<>* enState = document.first_node("turing")->first_node("endState");
    endState = enState->first_attribute("name")->value();

    currentState = &machineStates[startState];
}
void TuringMachine::printStates(){
    for(const auto& [_unused, state] : machineStates) {
        std::cout << "State: {" << std::endl;
        std::cout << "\tName: " << state.stateName << std::endl;
        std::cout << "\tTransitions: { " << std::endl;

        for(auto const& [_unused2, stateTransition] : state.transitions) {
            std::cout << "\t\t" << "StateTransition{tapeSymbol: " << stateTransition.tapeSymbol;
            std::cout << ", nextState: " << stateTransition.nextState;
            std::cout << ", newSymbol: " << stateTransition.newSymbol;

            std::string direction;

            if(stateTransition.movementDirection == Move::MOVE_LEFT) { direction = "L"; }
            else if(stateTransition.movementDirection == Move::MOVE_RIGHT) { direction = "R"; }
            else if(stateTransition.movementDirection == Move::STAY) { direction = "S"; }
            else { throw "Invalid tape movement direction!"; }

            std::cout << ", movementDirection: " << direction << "}" << std::endl;
        } 
        std::cout << "\t}\n}," << std::endl;
    }
}
void TuringMachine::printTape(){
    std::cout << "Tape: {";

    for(unsigned i = 0; i < tape.size(); ++i) {
        std::cout << tape[i] << (i != tape.size() - 1 ? ", " : ""); 
    }

    std::cout << "}" << std::endl;
}
void TuringMachine::execute(){
		std::string currentTapeSymbol = tape[tapePosition];

    while(tapePosition >= 0 && tapePosition < tape.size()  ) {
        currentTapeSymbol = tape[tapePosition];
        StateTransition* stateTransition = &(currentState->transitions[currentTapeSymbol]);
        		
        if(stateTransition == nullptr) {
            std::cout << "Invalid state transition!" << std::endl;
        }
        
        tape[tapePosition] = stateTransition->newSymbol;
        
        switch(stateTransition.movementDirection) {
          case Move::MOVE_LEFT: {
							std::cout << "Lewo" << std::endl;
            	tapePosition -= 1;
          }
          case Move::MOVE_RIGHT: {
						  std::cout << "Prawo" << std::endl;
            	tapePosition += 1;
          }
          case Move::STAY: {
							std::cout << "Nie ruszam sie" << std::endl;
          }
          default: {
              std::cout << "Invalid movement command!" << std::endl;
              throw "Invalid movement command!";
          }
        }
        
        currentState = &machineStates[stateTransition->newState];
        
				printTape();
    }
}
/*
void TuringMachine::execute(){
    std::string stateName = "0";
    while(tapePosition >= 0 && tapePosition < tape.size()){
        for(const auto& [_unused, state] : machineStates) {
            if(state.stateName == stateName){
                for(auto const& [_unused2, stateTransition] : state.transitions) {
                    if(stateTransition.tapeSymbol == tape[tapePosition]){
                        std::cout << "tape[" << tapePosition << "]: " << tape[tapePosition];
                        tape[tapePosition] = stateTransition.newSymbol;
                        std::cout << " -> " << tape[tapePosition] << std::endl;
                        stateName = stateTransition.nextState;

                        

                        if(stateTransition.movementDirection == Move::MOVE_LEFT) { 
                            std::cout << "Lewo" << std::endl;
                            tapePosition-=1;
                        } else if(stateTransition.movementDirection == Move::MOVE_RIGHT) {
                            std::cout << "Prawo" << std::endl;
                            tapePosition+=1;
                        }

                    }                   
                } 
            }
        }
    }
    printTape();
}
*/