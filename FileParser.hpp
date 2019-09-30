/*
|--------------------------------------------------------------------------------------------------
|   Text file parsing
|--------------------------------------------------------------------------------------------------
*/
#ifndef _FILEPARSER_HPP
    #define _FILEPARSER_HPP
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <memory>
    #include "add/rapidxml-1.13/rapidxml.hpp"
    #include <vector>

    class FileParser{
        public:
            FileParser(std::string fileName);
            //~FileParser();
            //FileParser& operator=(const FileParser& rhs);
            void execute();
            void testStruct();
        private:
            std::string fileName;
    };
#endif