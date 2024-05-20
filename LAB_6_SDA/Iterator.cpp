#include "Iterator.h"
#include "DO.h"

using namespace std;

Iterator::Iterator(const DO& d) : dict(d) {
	poz_curenta = 0;
	deplasare();
}

void Iterator::prim() {
	poz_curenta = 0;
	deplasare();
}

void Iterator::urmator() {
	curent = curent->urm;
	if (curent == nullptr) {
		poz_curenta++;
		deplasare();
	}
}

bool Iterator::valid() const {
	return poz_curenta < dict.m && curent != nullptr;
}

TElem Iterator::element() const {
	return curent->e;
}


