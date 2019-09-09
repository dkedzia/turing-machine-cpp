#ifndef _INSTRUCTIONS_HPP
    
    #define _INSTRUCTIONS_HPP
    #include<iostream>
    #include<string>
    class Instructions{
        public:
            struct type{
                int q;
                std::string input;
                std::string output;
                int qOutput;
            };
            void addRecord(int q, std::string input, std::string output, int qOutput);
        private:
    };

#endif