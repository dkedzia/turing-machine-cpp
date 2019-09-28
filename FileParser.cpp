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
    rapidxml::xml_document<> doc;
	rapidxml::xml_node<> * root_node;
    std::ifstream theFile ("alg/zamiana.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("turing");
    for (rapidxml::xml_node<> * brewery_node = root_node->first_node("symbol"); brewery_node; brewery_node = brewery_node->next_sibling())
	{
	    for(rapidxml::xml_node<> * beer_node = brewery_node->first_node("q"); beer_node; beer_node = beer_node->next_sibling())
	    {
	    	printf("On %s, I tried their %s which is a %s. ", 
	    		beer_node->first_attribute("write")->value(),
	    		beer_node->first_attribute("move")->value(), 
	    		beer_node->first_attribute("gotoq")->value());
	    	printf("I gave it the following review: %s", beer_node->value());
	    }
	    std::cout << std::endl;
	}
}