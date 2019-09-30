#include <iostream>
#include <map>

enum class Move{
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


for(rapidxml::xml_node<>* stateNode = root_node->first_node("state"); stateNode; stateNode = stateNode->next_sibling()) {
  State stateDefinition;
  stateDefinition.stateName = stateNode->first_attribute("name")->value();
 
  for(rapidxml::xml_node<>* transitionNode = root_node->first_node("stateTransition"), transitionNode; transitionNode->nextSibling()) {
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


<turing>
  <state name="stanA">
    </stateTransition tapeSymbol="1" nextState="stanB" newSymbol="DUPA" movementDirection="R">
	</stateTransition tapeSymbol="0" nextState="stanB" newSymbol="CHUJ" movementDirection="L">
  </state>
  <state name="stanB">
    </stateTransition tapeSymbol="1" nextState="stanB" newSymbol="DUPA" movementDirection="R">
	</stateTransition tapeSymbol="0" nextState="stanB" newSymbol="CHUJ" movementDirection="L">
  </state>
</turing>

int main() {
	// your code goes here
	return 0;
}