#include "files.h"


using namespace std;


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    /*checking input*/
    if (argc <= 1 || argc > 3) {
        cout << "wrong input" << endl;
        return 1;
    }


    map<string, int> base;
    float cnt = 0;
    custom::input Fin(argv[1]);
    custom::output Fout(argv[2]);
    if (!Fin.is_open() || !Fout.is_open()) {
        cout << "opening file error" << endl;
        return 1;
    }

    Fin.read(base, &cnt);

    /*sorting words*/
    vector <pair<string, int>> arr;
    arr.reserve((size_t)cnt);
    for (const auto &elem: base)
        arr.emplace_back(elem);
    sort(arr.begin(), arr.end(), [] (const auto &x, const auto &y) {return x.second > y.second;});

    /*write output*/
    Fout.write(arr, cnt);


    return 0;
}
