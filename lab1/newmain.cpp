#include "pol.h"
#include <fstream>

int main(){
    std::ifstream fin("in.txt");
    // std::ofstream fout("out.txt");
    try {
        
        std::map<int, double> ppp, qqq;
        ppp[0] = 0;
        ppp[3] = 4;
        qqq[3] = 4;
        qqq[0] = 1;
        ppp[6] += 4;
        Polynom zxc;
        fin >> zxc;
        std::cout << zxc;
        Polynom qwe = zxc+zxc;
        Polynom a = 8*qwe*5;
        std::cout << a;
        std::cout << qwe;
        Polynom b = qwe.integration(4);
        std::cout << b;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}