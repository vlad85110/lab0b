#include "classes.h"


namespace custom {
    /*class input*/
    input::input(char* name) {
        this->file.open(name);
    }

    bool input::is_open() {
        return file.is_open();
    }

    bool input::eof() {
        return file.eof();
    }

    std::ifstream &input::get_file() {
        return this->file;
    }

    void input::close() {
        this -> file.close();
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

    void output::write(const std::map<std::string, int> & base, float cnt) {
        std::vector <std::pair<const std::string &, int>> arr;
        arr.reserve((size_t)cnt);

        /*sorting words*/
        for (const auto &elem : base)
            arr.emplace_back(elem);
        sort(arr.begin(), arr.end(), [] (const auto &x, const auto &y) {return x.second > y.second;});
        for (const auto &elem : arr)
            file << elem.first << ";" << elem.second << ";" << (float)elem.second / cnt * 100 << "%" << std::endl;
    }

    /*class data*/
    data::data(input &file) {
        float cnt = 0;
        std::regex rgx("\\w+");
        std::string str, substr;

        while(!file.eof()) {
            getline(file.get_file(), str);
            /*getting one string from file and searching matches*/
            for(std::sregex_iterator it(str.begin(), str.end(), rgx), it_end; it != it_end; ++it ) {
                substr = it->str();
                cnt++;
                base[substr]++;
            }
        }
        this->word_count = cnt;
    }

    const std::map<std::string, int> &data::get_base() const {
        return this->base;
    }

    const float data::get_count() const {
        return this->word_count;
    }
}