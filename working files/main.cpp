#include "classes.h"


using namespace std;


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    /*checking input*/
    if (argc <= 1 || argc > 3) {
        cout << "wrong input" << endl;
        return 1;
    }

    float cnt = 0;
    /*opening files*/
    custom::input Fin(argv[1]);
    custom::output Fout(argv[2]);
    if (!Fin.is_open() || !Fout.is_open()) {
        cout << "opening file error" << endl;
        return 1;
    }
    custom::data base(Fin);
    Fin.close();

    /*write output*/
    Fout.write(base);


    return 0;
}
