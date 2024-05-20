#include <iostream>
#include "Iterator.h"
#include "test_scurt.h"
#include "test_extins.h"


// TAD Dic?ionar Ordonat – reprezentare sub forma unei TD cu rezolvare coliziuni prin liste independente.

void afisare(Iterator i) {
    i.prim();
    while (i.valid()) {
        std::cout << i.element().first << " " << i.element().second << "   ";
        i.urmator();
    }
}

bool r(TCheie c1, TCheie c2) {
    if (c1 <= c2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    testAll();
    testAllExtins();
    DO dict(r);
    dict.adauga(3, 1);
    dict.adauga(13, 3);
    dict.adauga(23, 5);
    dict.adauga(33, 6);
    dict.adauga(4, 6);
    Iterator it = dict.iterator();
    afisare(it);

    std::cout << "Finished Tests!" << std::endl;
}
