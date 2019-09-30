#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include "FileParser.hpp"

#include "add/rapidxml-1.13/rapidxml.hpp"


FileParser::FileParser(std::string fileName) : fileName(fileName){
    // Lista inicjalizacyjna ^
}


void FileParser::execute(){
    
	for (rapidxml::xml_node<> * symbol_node = root_node->first_node("symbol"); symbol_node; symbol_node = symbol_node->next_sibling())
	{
		printf("%s", symbol_node->first_attribute("type")->value());
	    for(rapidxml::xml_node<> * q_node = symbol_node->first_node("q"); q_node; q_node = q_node->next_sibling())
	    {
	    	printf("\t%s\t%s\t%s\t%s\n", 
				q_node->first_attribute("type")->value(),
	    		q_node->first_attribute("write")->value(),
	    		q_node->first_attribute("move")->value(), 
	    		q_node->first_attribute("gotoq")->value());
	    }
	    std::cout << std::endl;
	}
}

void FileParser::testStruct(){
	maszyna.q = 'x';
	std::cout << maszyna.q << std::endl;
}