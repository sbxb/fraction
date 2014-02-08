#include <iostream>
#include <cstdlib>
#include "Fraction.h"

int main(int argc, char** argv) {
    
    Fraction f1(1, 3);
    Fraction f2(1, 2);
    Fraction f3(-1, 5);
    
    std::cout << "+ " << f1 + f2 + f3 << std::endl;
    std::cout << "- " << f1 - f2 - f3 << std::endl;
    std::cout << "* " << f1 * f2 * f3 << std::endl;
    std::cout << "/ " << f1 / f2 / f3 << std::endl;
    
    std::cout << f2 << " < " << f1 << ((f2 < f1) ? " true" : " false") << std::endl;
    
    std::cout << f1 << " + 3 " << "= " << f1 + 3 << std::endl;
    
    return EXIT_SUCCESS;
}
