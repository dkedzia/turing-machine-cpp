#pragma once

#include <map>
#include <string>

enum class Move {
  STAY,
  MOVE_LEFT,
  MOVE_RIGHT,
};

struct StateTransition {
  std::string tapeSymbol;
  std::string nextState;
  std::string newSymbol;
  Move movementDirection; 
};

struct State {
  std::string stateName;
  std::map<std::string, StateTransition> transitions;
};