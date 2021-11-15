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
        explicit data(input & file);
        const std::map<std::string, int> & get_base() const;
        const float get_count() const;
    };

    class input {
        /*class for reading input file*/
    private:
        std::ifstream  file;
    public:
        explicit input(char* name);
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
        explicit output(char* name);
        ~output();
        bool is_open();
        void write(const std::map<std::string,int> &base, float count_words);
    };
}