#include "files.h"


namespace custom {
    /*class input*/
    input::input(char* name) {
        this->file.open(name);
    }

    input::~input() {
        this->file.close();
    }

    bool input::is_open() {
        return file.is_open();
    }

    void input::read(std::map<std::string, int> & base, float * cnt) {
        std::regex rgx("\\w+");
        std::string str, substr;
        while(!file.eof()) {
            getline(file, str);
            /*getting one string and searching matches*/
            for(std::sregex_iterator it(str.begin(), str.end(), rgx), it_end; it != it_end; ++it ) {
                substr = it->str();
                (*cnt)++;
                if (base.find(substr) != base.end())
                    base[substr]++;
                else
                    base.emplace(substr, 1);
            }
        }
    }

    /*class output*/
    output::output(char *name) {
        this->file.open(name);
    }

    output::~output() {
        this->file.close();
    }

    bool output::is_open() {
        return file.is_open();
    }

    void output::write(std::vector<std::pair<std::string, int>> & arr, float cnt) {
        for (const auto &elem : arr)
            file << elem.first << ";" << elem.second << ";" << (float)elem.second / cnt * 100 << "%" << std::endl;
    }
}