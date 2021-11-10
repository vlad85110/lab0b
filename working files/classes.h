#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <regex>

namespace custom {
    class input;
    class output;
    class data;


    class data {
    private:
        std::map<std::string, int> base;
        float word_count;
    public:
        data(input & file);
        const std::map<std::string, int> &get_base();
        float & get_count();
    };

    class input {
        /*class for reading input file*/
    private:
        std::ifstream  file;
    public:
        input(char* name);
        bool is_open();
        bool eof ();
        void close ();
        std::ifstream & get_file();
    };

    class output {
        /*class for writing output file*/
    private:
        std::ofstream  file;
    public:
        output(char* name);
        ~output();
        bool is_open();
        void write(const std::map<std::string,int> &base, float count_words);
    };
}