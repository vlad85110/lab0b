#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <regex>

namespace custom {
    class input {
        /*class for reading input file*/
    private:
        std::ifstream file;
    public:
        input(char* name);
        ~input();
        bool is_open();
        void read(std::map<std::string, int> & base, float *cnt);
    };

    class output {
        /*class for writing output file*/
    private:
        std::ofstream file;
    public:
        output(char* name);
        ~output();
        bool is_open();
        void write(std::vector <std::pair<std::string, int>> & arr, float cnt);
    };

}