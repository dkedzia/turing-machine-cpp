/*
|--------------------------------------------------------------------------------------------------
|   Text file parsing
|--------------------------------------------------------------------------------------------------
*/
#ifndef _FILEPARSER_HPP
    #define _FILEPARSER_HPP
    #include<iostream>
    #include<string>
    class FileParser{
        public:
            FileParser(std::string fileName);
            ~FileParser();
            FileParser& operator=(const FileParser& rhs);
    
        private:
            std::string fileName;    
    };

#endif